#include "string.h"
#include "system.h"
#include "screen.h"

static u32 cursorX = 0, cursorY = 0;

void clearLine(u8 start, u8 finish) {
	u16 i = SCREEN_WIDTH * start * SCREEN_DEPTH;
	for (u16 i = SCREEN_WIDTH * start * SCREEN_DEPTH; i < SCREEN_WIDTH * (finish + 1) * SCREEN_DEPTH; i++) {
		VIDMEM[i] = 0x00;
	}
}

void updateCursor(void) {
	u32 temp = cursorY * SCREEN_WIDTH + cursorX;

	setport(0x3d4, 14);
	setport(0x3d5, temp >> 8);
	setport(0x3d4, 15);
	setport(0x3d5, temp);
}	

void clearScreen(void) {
	clearLine(0, SCREEN_HEIGHT - 1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}

void putchar(s8 c) {
	VIDMEM[SCRPOINT(cursorX, cursorY) * SCREEN_DEPTH] = c;
	VIDMEM[SCRPOINT(cursorX, cursorY) * SCREEN_DEPTH + 1] = c ? 0x5f : 0x00;
}

void printch(s8 c) {
	switch (c) {
		// backspace
		case 0x08:
			if (cursorX > 0) {
				cursorX--;
			} else if (cursorY > 0) {
				cursorY--;
			}
			putchar(0);
			break;
		// tab
		case 0x09:
			cursorX = (cursorX + 8) & ~(8 - 1);
			break;
		// newline
		case '\n':
			cursorX = 0;
			cursorY++;
			break;
		default:
			putchar(c);
			cursorX++;
			break;
	}

	if (cursorX > SCREEN_WIDTH) {
		cursorX = 0;
		cursorY++;
	}
}

void getstr(void) {
	s8 buf[1024];
	u16 bufptr = 0;
	memset(buf, 0, sizeof(buf));
	while (1) {
		if (getport(PORT_KEYBOARD_READY) & 0x01) {
			u8 scancode = getport(PORT_KEYBOARD_CHAR);
			if (scancode == 0x1c) {
				docmd(buf);
				bufptr = 0;
				break;
			}
			if (!(scancode & 0x80)) {
				printch(KEYMAP[scancode]);
				buf[bufptr++] = KEYMAP[scancode];
			}
		}
	}
}

void printf(s8* str) {
	for (u16 i = 0; i < strlen(str); i++) {
		printch(str[i]);
	}
}	
