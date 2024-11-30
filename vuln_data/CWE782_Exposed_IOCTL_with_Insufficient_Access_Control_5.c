#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define MAGIC_NUMBER 0xF5
#define PRIVILEGED_IOCTL_CMD _IOWR(MAGIC_NUMBER, 1, int)

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
    
    switch (cmd) {
        case PRIVILEGED_IOCTL_CMD: {
            int data;
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
    .release = device_release
};

static int __init ioctl_init(void) {
    int major = register_chrdev(0, "char_device", &fops);
    if (major < 0) {
        return major;
    }
    pr_info("char_device registered with major number %d\n", major);
    return 0;
}

static void __exit ioctl_exit(void) {
    unregister_chrdev(0, "char_device");
    pr_info("char_device unregistered\n");
}

module_init(ioctl_init);
module_exit(ioctl_exit);
MODULE_LICENSE("GPL");