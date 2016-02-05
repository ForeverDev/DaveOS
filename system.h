#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "types.h"

#define PORT_KEYBOARD_READY 0x64
#define PORT_KEYBOARD_CHAR 	0x60
#define SCREEN_WIDTH		80
#define SCREEN_HEIGHT		25
#define SCREEN_DEPTH		2
#define VIDMEM				((s8 *)0xb8000)

#define SCRPOINT(x, y) (y * SCREEN_WIDTH + x)

extern const s8 KEYMAP[84];

void 	docmd(s8*);
void 	quit(void);
u8		getport(u16);
void	setport(u16, u8);

#endif
