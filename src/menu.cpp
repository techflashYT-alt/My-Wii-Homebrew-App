#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include <string.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <gccore.h>
#pragma GCC diagnostic pop
#include <wiiuse/wpad.h>

#include "inc/errnum.hpp"
void consoleMove(uint8_t x, uint8_t y);
char* convertInputToString(const char &button);
char handleInput(const uint32_t &WpadPressed);

struct menu_t;
struct menu_t {
	char title[20] = "Default Menu Title";
	menu_t *submenus[4];
	void (* option [4])();
	char optionNames[8][20];
	uint8_t selected = 0;
};

void printHi() {
	printf("Hi!\n");
}

menu_t testMenu = {
	"Default menu",
	{ NULL, NULL, NULL, NULL },
	{ printHi, printHi, printHi, printHi },
	{ "Submenu 1", "Submenu 2", "Submenu 3", "Submenu 4", "Option 1", "Option 2", "Option 3", "Option 4" }
};
uint8_t numOptions = 0;
uint8_t currentErrors[6] = { 0, 0, 0, 0, 0, 0 };
void printMenu(menu_t &menu) {
	if (menu.title == NULL) {
		currentErrors[0] = ERR_NO_MENU_TITLE;
	}
	printf("%s\r\n", menu.title);
	for (uint8_t i = 0; i < 8; i++) {
		if (menu.optionNames[i] != NULL) {
			printf("  %s\r\n", menu.optionNames[i]);
		}
		else {
			continue;
		}
	}
	if (numOptions == 0) {
		currentErrors[1] = ERR_NO_MENU_OPTS;
	}
	for (uint16_t i = 0; i < UINT16_MAX; i++) {
		consoleMove((menu.selected + 2), 0);
		printf("→");
		char* b = convertInputToString((handleInput(WPAD_ButtonsDown(0))));
		if (strcmp(b, "Down") == 0 ) {
			menu.selected++;
		}
		else if (strcmp(b, "Up") == 0) {
			menu.selected--;
		}
		VIDEO_WaitVSync();
	}
	return;
}
