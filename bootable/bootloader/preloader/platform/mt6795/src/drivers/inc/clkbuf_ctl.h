/**
* @file    mt_clk_buf_ctl.c
* @brief   Driver for RF clock buffer control
*
*/
#ifndef __MT_CLK_BUF_CTL_H__
#define __MT_CLK_BUF_CTL_H__
#if 0

//XXX: only in kernel

#include <linux/kernel.h>
#include <linux/mutex.h>
#include <cust_clk_buf.h>
#else
#include <gpio.h>
#endif


#if 1//TODO, need add Pad name@DCT tool
#ifndef GPIO_RFIC0_BSI_CS
#define GPIO_RFIC0_BSI_CS         (GPIO72|0x80000000)    /* RFIC0_BSI_CS = GPIO53 */
#endif
#ifndef GPIO_RFIC0_BSI_CK
#define GPIO_RFIC0_BSI_CK         (GPIO68|0x80000000)    /* RFIC0_BSI_CK = GPIO68 */
#endif
#ifndef GPIO_RFIC0_BSI_D0
#define GPIO_RFIC0_BSI_D0         (GPIO69|0x80000000)    /* RFIC0_BSI_D0 = GPIO69 */
#endif
#ifndef GPIO_RFIC0_BSI_D1
#define GPIO_RFIC0_BSI_D1         (GPIO70|0x80000000)    /* RFIC0_BSI_D1 = GPIO70 */
#endif
#ifndef GPIO_RFIC0_BSI_D2
#define GPIO_RFIC0_BSI_D2         (GPIO71|0x80000000)    /* RFIC0_BSI_D2 = GPIO71 */
#endif
#endif


enum clk_buf_id{
    CLK_BUF_BB			= 0,
    CLK_BUF_6605		= 1,
    CLK_BUF_5193		= 2,
    CLK_BUF_AUDIO		= 3,
    CLK_BUF_INVALID		= 4,
};
typedef enum
{
   CLK_BUF_SW_DISABLE = 0,
   CLK_BUF_SW_ENABLE  = 1,
}CLK_BUF_SWCTRL_STATUS_T;
#define CLKBUF_NUM         4 

#define STA_CLK_ON      1
#define STA_CLK_OFF     0
#if 0

//XXX: only in kernel

bool clk_buf_ctrl(enum clk_buf_id id,bool onoff);
void clk_buf_get_swctrl_status(CLK_BUF_SWCTRL_STATUS_T *status);
bool clk_buf_init(void);

extern struct mutex clk_buf_ctrl_lock;
#else
void clk_buf_all_on(void);
#endif
#endif

