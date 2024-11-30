#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>

#define MAGIC_NUMBER 0xF5
#define PRIVILEGED_IOCTL_CMD _IOWR(MAGIC_NUMBER, 1, int)

static dev_t dev_number;
static struct cdev my_cdev;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    if (!capable(CAP_SYS_ADMIN)) {
        return -EPERM;
    }
    
    if (_IOC_TYPE(cmd) != MAGIC_NUMBER) {
        return -ENOTTY;
    }
    
    switch (cmd) {
        case PRIVILEGED_IOCTL_CMD: {
            int data;
            if (!access_ok((int *)arg, sizeof(data))) {
                return -EFAULT;
            }
            if (copy_from_user(&data, (int *)arg, sizeof(data))) {
                return -EFAULT;
            }
            pr_info("Privileged IOCTL accessed: %d\n", data);
            break;
        }
        default:
            return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = device_ioctl,
    .open = device_open,
    .release = device_release,
    .owner = THIS_MODULE,
};

static int __init ioctl_init(void) {
    int result = alloc_chrdev_region(&dev_number, 0, 1, "char_device");
    if (result < 0) {
        return result;
    }

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    result = cdev_add(&my_cdev, dev_number, 1);
    if (result) {
        unregister_chrdev_region(dev_number, 1);
        return result;
    }

    pr_info("char_device registered with major number %d\n", MAJOR(dev_number));
    return 0;
}

static void __exit ioctl_exit(void) {
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_number, 1);
    pr_info("char_device unregistered\n");
}

module_init(ioctl_init);
module_exit(ioctl_exit);
MODULE_LICENSE("GPL");