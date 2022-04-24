#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

void handleInput(uint32_t WpadPressed) {
	if (WpadPressed & WPAD_BUTTON_A) {
		printf("A pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_B) {
		printf("B pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_1) {
		printf("1 pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_2) {
		printf("2 pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_PLUS) {
		printf("+ pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_MINUS) {
		printf("- pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_HOME) {
		exit(0);
	}
	if (WpadPressed & WPAD_BUTTON_LEFT) {
		printf("Left pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_RIGHT) {
		printf("Right pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_UP) {
		printf("Up pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_DOWN) {
		printf("Down pressed\r\n");
	}
	if (WpadPressed & WPAD_BUTTON_PLUS) {
		printf("+ pressed\r\n");
	}
}
