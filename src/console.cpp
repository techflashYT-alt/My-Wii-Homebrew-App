#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
void consoleClear() {
	sleep(1);
	printf("\e[2;0H\e[2J");
}
void consoleMove(uint8_t x, uint8_t y) {
	printf("\e[%d;%dH", y, x);
}
void consoleScroll() {
	printf("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
	consoleClear();
}
