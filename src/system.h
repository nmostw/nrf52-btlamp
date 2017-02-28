/*
 * system.h
 *
 *  Created on: Jul 22, 2012
 *      Author: petera
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "types.h"

#define IOSTD   0
#define STDIN   0
#define STDOUT  0

//#ifndef MIN
//#define MIN(x,y)  ((x)<(y)?(x):(y))
//#endif
//#ifndef MAX
//#define MAX(x,y)  ((x)>(y)?(x):(y))
//#endif
#define ABS(x)    ((x)<0?(-(x)):(x))
#define SIGN(x)   ((x) == 0 ? 0 : ((x)<0?(-1):(1)))

#define STR(tok) #tok

#ifndef offsetof
#define offsetof(st, m) \
     ((u32_t) ( (char *)&((st *)0)->m - (char *)0 ))
#endif

#define CONFIG_MEMOPS
#ifdef CONFIG_MEMOPS
#define memcpy(d,s,n) __builtin_memcpy((d),(s),(n))
#define memset(s,t,n) __builtin_memset((s),(t),(n))
#endif

#ifdef CONFIG_VARCALL
extern void *_variadic_call(void *func, int argc, void* args);
#endif

#ifdef CONFIG_MATH
extern int _sqrt(int);
#endif

#ifdef PROC_FAMILY_STM32
typedef GPIO_TypeDef * hw_io_port;
typedef uint16_t hw_io_pin;

#if defined(PROC_STM32F1)

#define GPIO_enable(port, pin) (port)->BSRR = (pin)
#define GPIO_disable(port, pin) (port)->BSRR = ((pin)<<16)
#define GPIO_set(port, pin_ena, pin_dis) (port)->BSRR = (pin_ena) | ((pin_dis)<<16)
#define GPIO_read(port, pin) (((port)->IDR & (pin)) != 0)

#elif defined(PROC_STM32F4)

#define GPIO_enable(port, pins) (port)->BSRRL = (pins)
#define GPIO_disable(port, pins) (port)->BSRRH = (pins)
#define GPIO_set(port, pin_ena, pin_dis) \
  (((volatile u32_t *)(port))[0x18/sizeof(u32_t)]) = (pin_ena) | ((pin_dis)<<16)
#define GPIO_read(port, pin) (((port)->IDR & (pin)) != 0)

#else

#error "undefined processor for family"

#endif

#endif

typedef enum {
  ASSERT_BLINK_4EVER = 0,
  ASSERT_RESET
} assert_behaviour_t;

///**
// * Called at startup
// */
//void SYS_init();
///**
// * Called from timer irq. Returns TRUE on ms update, FALSE otherwise.
// * On CONFIG_SYS_USE_RTC, this does not need to be called to keep
// * the system clock ticking.
// */
//bool SYS_timer();
///**
// * Get milliseconds since system clock start
// */
//sys_time SYS_get_time_ms();
///**
// * Get ticks since system clock start
// */
//sys_time SYS_get_tick();
///**
// * Get current system time
// */
//void SYS_get_time(u16_t *d, u8_t *h, u8_t *m, u8_t *s, u16_t *ms);
///**
// * Sets current system time
// */
//void SYS_set_time(u16_t d, u8_t h, u8_t m, u8_t s, u16_t ms);
//
//void SYS_assert(const char* file, int line);
//void SYS_set_assert_callback(void (*f)(void));
//void SYS_set_assert_behaviour(assert_behaviour_t b);
//void SYS_hardsleep_ms(u32_t ms);
//void SYS_hardsleep_us(u32_t us);
//u32_t SYS_build_number(void);
//u32_t SYS_build_date(void);
//void SYS_break_if_dbg(void);
//void SYS_dump_trace(u8_t io);
//void SYS_reboot(enum reboot_reason_e);

#endif /* SYSTEM_H_ */
