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
		StartClose(); 
	}

	else if (pressed & WPAD_BUTTON_A) {

		struct MenuOptions {
			char* One[100];
			char* Two[100];
			char* Three[100];
			char* Four[100];
			char* Five[100];
			char* Six[100];
			char* Seven[100];
			char* Eight[100];
			char* Nine[100];
			char* Ten[100];
			char* Eleven[100];
			char* Twelve[100];
			char* Thirteen[100];
			char* Fourteen[100];
			char* Fifteen[100];
			char* Sixteen[100];
			char* Seventeen[100];
			char* Eighteen[100];
			char* Ninteen[100];
			char* Twenty[100];
		};

		char* menuName[100];
		menuName[0] = "Menu";
		int optionsNum = 2;
		bool Horizontal = false;
		struct MenuOptions MenuOptions;
		MenuOptions.One[0] = "Test1";
		MenuOptions.Two[0] = "Test2";
		void displayMenu(char* menuName[100], bool Horizontal, int optionsNum, struct MenuOptions MenuOptions);
		displayMenu(menuName, Horizontal, optionsNum, MenuOptions);
	}

	else if (pressed & WPAD_BUTTON_MINUS) {
		ScrollAway();
		ClearConsole();
		char* state[12];
		state[0] = "DisplayHelp";
		ChangeState(state[0]);
	}
	else {
		// Not implemented
	}

}
