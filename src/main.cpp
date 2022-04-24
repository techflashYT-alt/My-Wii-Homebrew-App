#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <gccore.h>
#pragma GCC diagnostic pop
#include <wiiuse/wpad.h>

#include "inc/color.hpp"

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void init(void *&xfb, GXRModeObj *&rmode);
char handleInput(const uint32_t &WpadPressed);
char* convertInputToString(const char &button);
struct menu_t;
extern menu_t testMenu;
void printMenu(menu_t &menu);
void consoleScroll();

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	init(xfb, rmode);
	printf("Welcome to Techflash's Wii App!\r\nPress the \x1b[32mA\x1b[0m button to start.\r\n");

	while(true) {
		// Get the current controller connected
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		uint32_t WpadPressed = WPAD_ButtonsDown(0);
		// uint32_t padPressed[4]  = {PAD_ButtonsDown(0), PAD_ButtonsDown(1), PAD_ButtonsDown(2), PAD_ButtonsDown(3)};
		const char* button = {convertInputToString(handleInput(WpadPressed))};
		if (button != NULL) {
			if (strcmp(button, "A") == 0) {
				printMenu(testMenu);
			}
			if (strcmp(button, "Home") == 0) {
				printf("\r\nBye!\r\n");
				sleep(2);
				consoleScroll();

				break;
			}
		}

		// Wait for the next frame
		VIDEO_WaitVSync();
	}
	return 0;
}
