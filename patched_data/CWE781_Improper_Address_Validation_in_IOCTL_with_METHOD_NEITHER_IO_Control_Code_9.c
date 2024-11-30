#include <linux/ioctl.h>
#include <linux/uaccess.h>

#define IOCTL_EXAMPLE_METHOD_NEITHER _IOWR('E', 1, unsigned long)

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
    case IOCTL_EXAMPLE_METHOD_NEITHER: {
        void *user_buffer;
        unsigned long size;

        if (copy_from_user(&size, (void __user *)arg, sizeof(unsigned long)))
            return -EFAULT;

        if (size > SIZE_MAX - sizeof(unsigned long))
            return -EINVAL;

        if (!access_ok((void __user *)(arg + sizeof(unsigned long)), size))
            return -EFAULT;

        user_buffer = kmalloc(size, GFP_KERNEL);
        if (!user_buffer)
            return -ENOMEM;

        if (copy_from_user(user_buffer, (void __user *)(arg + sizeof(unsigned long)), size)) {
            kfree(user_buffer);
            return -EFAULT;
        }

        kfree(user_buffer);
        return 0;
    }
    default:
        return -EINVAL;
    }
}

struct file_operations fops = {
    .unlocked_ioctl = device_ioctl,
    // Other file operations
};