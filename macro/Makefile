CROSS=arm-none-eabi-
CC=$(CROSS)gcc

all:
	@$(CC) -c main.c
	@$(CROSS)objdump -D main.o > main.s
	@$(CC) -E main.c -o main.i
clean:
	@rm -rf main.o main.s main.i
