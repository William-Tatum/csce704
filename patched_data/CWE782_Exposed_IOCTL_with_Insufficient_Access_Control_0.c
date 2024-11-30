#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/mutex.h>

#define DEVICE_NAME "vuln_device"
#define IOCTL_PRIVILEGED_CMD _IO('V', 1)

static dev_t dev_num;
static struct cdev c_dev;
static DEFINE_MUTEX(ioctl_lock);

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    long ret = 0;
    if (!capable(CAP_SYS_ADMIN)) {
        return -EPERM;
    }
    mutex_lock(&ioctl_lock);
    switch (cmd) {
        case IOCTL_PRIVILEGED_CMD:
            printk(KERN_INFO "Privileged command executed\n");
            break;
        default:
            ret = -EINVAL;
    }
    mutex_unlock(&ioctl_lock);
    return ret;
}

static int dev_open(struct inode *inode, struct file *file) {
    return 0;
}

static int dev_release(struct inode *inode, struct file *file) {
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = device_ioctl,
    .open = dev_open,
    .release = dev_release,
};

static int __init vuln_device_init(void) {
    if (alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME) < 0) {
        return -1;
    }
    cdev_init(&c_dev, &fops);
    if (cdev_add(&c_dev, dev_num, 1) == -1) {
        unregister_chrdev_region(dev_num, 1);
        return -1;
    }
    return 0;
}

static void __exit vuln_device_exit(void) {
    cdev_del(&c_dev);
    unregister_chrdev_region(dev_num, 1);
}

module_init(vuln_device_init);
module_exit(vuln_device_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Exposed IOCTL with Insufficient Access Control");