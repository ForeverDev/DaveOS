#include "types.h"
#include "system.h"
#include "screen.h"
#include "kernel.h"

void kmain(void) {
	
	clearScreen();
	
	printf("Welcome to DaveOS!\n");
	
	while (1) {
		printf("\nDaveOS :> ");
		getstr();
	}
}
