#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "example_device"
#define IOCTL_RESTRICTED_CMD 0xABCDEF

static int major_number;

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    if (!capable(CAP_SYS_ADMIN)) {
        printk(KERN_WARNING "Unauthorized access to restricted IOCTL command\n");
        return -EPERM;
    }
    switch (cmd) {
        case IOCTL_RESTRICTED_CMD:
            printk(KERN_INFO "Authorized access to restricted functionality\n");
            // Perform restricted action here
            break;
        default:
            return -EINVAL;
    }
    return 0;
}

static struct file_operations fops = {
    .unlocked_ioctl = device_ioctl,
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