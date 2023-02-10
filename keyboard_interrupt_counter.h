#include <linux/ioctl.h>

#define KIC_DEVICE_NAME "keyboard_interrupt_counter"
#define KIC_DEVICE_PATH "/dev/"KIC_DEVICE_NAME
#define KIC_MAJOR 420 		//modify accordingly if needed

#define KIC_GET_COUNT_QUERY _IOR(KIC_MAJOR, 0, unsigned long int *)
#define KIC_GET_TIME_QUERY _IOR(KIC_MAJOR, 1, long int *)
#define KIC_RESET_QUERY _IO(KIC_MAJOR, 2)
