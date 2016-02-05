#include "string.h"

u64 strlen(s8* str) {
	s8* ptr = str;
	while (*(ptr++));
	return (u64)((--ptr) - str);
}

u8 strcmp(s8* str0, s8* str1) {
	u32 idx = 0;
	while (1) {
		if ((str0[idx] == str1[idx]) && str0[idx] == 0) {
			return 1;
		}
		if (str0[idx] == 0 || str1[idx] == 0) {
			return 0;
		}
		idx++;
	}
}

void memset(s8* memory, u8 data, size_t size) {
	for (u32 i = 0; i < size; i++) {
		memory[i] = data;
	}
}	
