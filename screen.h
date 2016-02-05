#ifndef __SCREEN_H
#define __SCREEN_H

#include "types.h"

void	clearLine(u8, u8);
void	updateCursor(void);
void 	clearScreen(void);
void 	putchar(s8);
void 	printch(s8);		
void	getstr(void);
void	printf(s8*);

#endif
