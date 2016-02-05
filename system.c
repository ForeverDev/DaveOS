#include "system.h"
#include "string.h"
#include "screen.h"
#include "system.h"

const s8 KEYMAP[84] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
	8, 9, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']',
	0, 0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '`',
	0, '\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', 0, 0, 
	0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '+', 0,
	0, 0, '+', 0, 0, 0, 0, 0
};

void docmd(s8* cmd) {
	if (strcmp(cmd, "exit")) {
		printf("EXIT!!!!\n");
	}
}

u8 getport(u16 port) {
	u8 ret;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void setport(u16 port, u8 data) {
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}
