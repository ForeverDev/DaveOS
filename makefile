CC = gcc
CF = -std=c11 -fno-builtin -m32 -fno-stack-protector
CSRC = screen.o string.o system.o kernel.o

all: $(CSRC) kasm.o
	ld -m elf_i386 -T link.ld -o kernel.bin kasm.o $(CSRC)
	qemu-system-x86_64 -kernel kernel.bin
	rm -Rf *.o

kasm.o: kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o

%.o: %.c
	$(CC) $(CF) -c -o $@ $<
