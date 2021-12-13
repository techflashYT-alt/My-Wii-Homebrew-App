#include "head/all.h"

s8 HWAction = -1;
void HotReset() {
	HWAction = SYS_HOTRESET;
}

void ReturnToMenu() {
	HWAction = SYS_RETURNTOMENU;
}

void ForceFullPowerOff() {
	HWAction = SYS_POWEROFF_STANDBY;
}

void ForceRC24Idle() {
	HWAction = SYS_POWEROFF_IDLE;
}

void Reboot() {
	HWAction = SYS_RESTART;
}

void AutoDetectPowerOff() {
	HWAction = SYS_POWEROFF;
}

void AutoDetectPowerOffWiimote(s32 chan) {
	HWAction = SYS_POWEROFF;
}

const char *CurrentState = "None";


//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	SYS_SetResetCallback(HotReset); //Console reset button support
	SYS_SetPowerCallback(AutoDetectPowerOff); //Console power button support
	WPAD_SetPowerButtonCallback(AutoDetectPowerOffWiimote); //Wiimote power button support
	
	//char* CurrentState[12];


	static void *xfb = NULL;
	static GXRModeObj *rmode = NULL;


	// Initialise the video system
	VIDEO_Init();

	// This function initialises the attached controllers
	WPAD_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();

	if(rmode->viTVMode&VI_NON_INTERLACE) {
		VIDEO_WaitVSync();	
	} 
	WPAD_SetDataFormat(0,WPAD_FMT_BTNS_ACC_IR);
	WPAD_SetVRes(WPAD_CHAN_ALL,640,480);

	// The console understands VT terminal escape codes
	// This positions the cursor on row 2, column 0
	// we can use variables for this with format codes too
	// e.g. printf ("\x1b[%d;%dH", row, column );
	printf("\x0A\x0A");

	printf("\033[33mWelcome to Techflash's\x0AWii application\033[37m\x0A\x0A\x0A"); // 1st is yellow color code, then reset

	// if (checkAspect() == 0) {
		
	// }
	printf("To go to the menu,\x0Apress the A button");
	// char* confirm[25];
	// confirm[0] = "confirm";
	
	// char* exit[25];
	// exit[0] = "exit";

	while(true) {
		getControllerInput();
		VIDEO_WaitVSync();
		CheckForNewAction();

		if (HWAction != -1) {
			break;
		}
	}

	if (HWAction != -1) {
		SYS_ResetSystem(HWAction, 0, 0);
	}
	return 0;
}

