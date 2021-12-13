#include "head/all.h"


void getControllerInput() {
	// Call WPAD_ScanPads each loop, this reads the latest controller states
	WPAD_ScanPads();
	// Also scan for GC pad controller state, not doing anything with it yet.
	PAD_ScanPads();

	// WPAD_ButtonsDown tells us which buttons were pressed in this loop
	// this is a "one shot" state which will not fire again until the button has been released
	u32 pressed = WPAD_ButtonsDown(0);
	//u32 held = WPAD_ButtonsHeld(0);
	//u32 released = WPAD_ButtonsUp(0);

	// Loop through all the buttons to see if the user pressed one.

	// We return to the launcher application via exit
	if (pressed & WPAD_BUTTON_HOME) {
		const char *state = "ExitToHBC";
		ChangeState(state);
	}

	if (pressed & WPAD_BUTTON_A) {
		const char *state = "TestMenu";
		ChangeState(state);
	}

	if (pressed & WPAD_BUTTON_MINUS) {
		const char *state = "DisplayHelp";
		ChangeState(state);
		HelpScreen();
	}
	else {
		// Not implemented
	}

}
