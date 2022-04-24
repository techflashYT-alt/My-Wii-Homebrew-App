#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void init(void *&xfb, GXRModeObj *&rmode);
void handleInput(uint32_t WpadPressed);

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	init(xfb, rmode);
	printf("Welcome to Techflash's Wii App!\r\n");

	while(true) {
		// Get the current controller connected
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		uint32_t WpadPressed = WPAD_ButtonsDown(0);
		// uint32_t padPressed[4]  = {PAD_ButtonsDown(0), PAD_ButtonsDown(1), PAD_ButtonsDown(2), PAD_ButtonsDown(3)};
		handleInput(WpadPressed);

		// Wait for the next frame
		VIDEO_WaitVSync();
	}
	return 0;
}
