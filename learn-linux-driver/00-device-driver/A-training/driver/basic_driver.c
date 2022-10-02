/*
 * fileName: character_driver.c
 * Author : -
 * date: 20/09/2022
 * description : character driver for virtual device that is vchar_device.
 *           vchar_device is vitual device on RAM.
 */

#include <linux/module.h> /* define  macro for module_init and module_exit */
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h> /*contain kmalloc and  kfree function*/
#include <linux/cdev.h> /* cdev*/
#include <linux/uaccess.h> /*contain functions that help for communication between user and kernel*/
#include "vchar_driver.h"/* library describe registers of vchar device*/

/*struct contain fields to interact with "vchar_device" device*/
typedef struct vchar_dev
{
	unsigned char *control_regs;
	unsigned char *status_regs;
	unsigned char *data_regs;
}vchar_dev_t;

/*datas that is essential for create device file*/
struct _vchar_drv
{
	dev_t dev_num;
	struct class *dev_class;
	struct device *dev;
	vchar_dev_t* vchar_hw;
	struct cdev *vcdev;
	unsigned int open_cnt;
}vchar_drv;

#define DRIVER_AUTHOR "Test Program"
#define DRIVER_DESC   "A sample character device driver"
#define DRIVER_VERSION "1.0"

int vchar_hw_init(vchar_dev_t *hw)
{
	char *buf;

	buf = kzalloc(NUM_DEV_REGS * REG_SIZE, GFP_KERNEL);
}
