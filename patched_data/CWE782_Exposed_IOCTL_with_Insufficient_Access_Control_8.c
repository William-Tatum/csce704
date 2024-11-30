#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define DEVICE_NAME "example_device"
#define IOCTL_RESTRICTED_CMD 0xABCDEF

static int major_number;
static DEFINE_MUTEX(ioctl_lock);

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    long ret = 0;

    if (!mutex_trylock(&ioctl_lock)) {
        printk(KERN_WARNING "Device is busy\n");
        return -EBUSY;
    }

    if (!capable(CAP_SYS_ADMIN)) {
        mutex_unlock(&ioctl_lock);
        printk(KERN_WARNING "Unauthorized access to restricted IOCTL command\n");
        return -EPERM;
    }

    switch (cmd) {
        case IOCTL_RESTRICTED_CMD:
            printk(KERN_INFO "Authorized access to restricted functionality\n");
            break;
        default:
            ret = -EINVAL;
    }

    mutex_unlock(&ioctl_lock);
    return ret;
}

static struct file_operations fops = {
    .unlocked_ioctl = device_ioctl,
    .owner = THIS_MODULE,
};

static int __init module_init_function(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }
    printk(KERN_INFO "Module loaded with device major number %d\n", major_number);
    return 0;
}

static void __exit module_exit_function(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Module unloaded\n");
}

module_init(module_init_function);
module_exit(module_exit_function);
MODULE_LICENSE("GPL");