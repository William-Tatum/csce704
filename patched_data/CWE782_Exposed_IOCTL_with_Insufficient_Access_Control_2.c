#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define IOCTL_RESTRICTED_ACCESS _IOR('r', 1, int)
#define VALID_USER_CREDENTIAL 0x1234ABCD

static dev_t dev_number;
static struct cdev restricted_cdev;
static struct class *restricted_class;

long restricted_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int user_cred;

    if (cmd != IOCTL_RESTRICTED_ACCESS)
        return -ENOTTY;

    if (copy_from_user(&user_cred, (int __user *)arg, sizeof(user_cred)))
        return -EFAULT;

    if (user_cred != VALID_USER_CREDENTIAL)
        return -EPERM;

    return 0;
}

static const struct file_operations fops = {
    .unlocked_ioctl = restricted_ioctl,
    .owner = THIS_MODULE
};

int __init init_module(void) {
    int ret;
    ret = alloc_chrdev_region(&dev_number, 0, 1, "restricted_ioctl_device");
    if (ret < 0) return ret;

    cdev_init(&restricted_cdev, &fops);
    restricted_cdev.owner = THIS_MODULE;

    ret = cdev_add(&restricted_cdev, dev_number, 1);
    if (ret) {
        unregister_chrdev_region(dev_number, 1);
        return ret;
    }

    restricted_class = class_create(THIS_MODULE, "restricted_dev_class");
    if (IS_ERR(restricted_class)) {
        cdev_del(&restricted_cdev);
        unregister_chrdev_region(dev_number, 1);
        return PTR_ERR(restricted_class);
    }

    device_create(restricted_class, NULL, dev_number, NULL, "restricted_ioctl_device");
    return 0;
}

void __exit cleanup_module(void) {
    device_destroy(restricted_class, dev_number);
    class_destroy(restricted_class);
    cdev_del(&restricted_cdev);
    unregister_chrdev_region(dev_number, 1);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Fixed Vulnerable IOCTL Example");