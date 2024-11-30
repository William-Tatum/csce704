#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define IOCTL_RESTRICTED_ACCESS _IOR('r', 1, int)
#define VALID_USER_CREDENTIAL 0x1234ABCD

long restricted_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    int user_cred;
    
    if (copy_from_user(&user_cred, (int __user *)arg, sizeof(user_cred)))
        return -EFAULT;

    if(user_cred != VALID_USER_CREDENTIAL)
        return -EPERM;

    switch(cmd) {
        case IOCTL_RESTRICTED_ACCESS:
            return 0;
        default:
            return -ENOTTY;
    }
}

static const struct file_operations fops = {
    .unlocked_ioctl = restricted_ioctl,
};

int init_module(void) {
    register_chrdev(0, "restricted_ioctl_device", &fops);
    return 0;
}

void cleanup_module(void) {
    unregister_chrdev(0, "restricted_ioctl_device");
}