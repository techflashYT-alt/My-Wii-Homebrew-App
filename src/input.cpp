#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
/*!
	\fn
	\brief Handle inputs from the Wii remote

	\param WpadPressed A const reference to the current buttons that are pressed.
	\returns A char corresponding to the button that was pressed.
*/
char handleInput(const uint32_t &WpadPressed) {
	if (WpadPressed & WPAD_BUTTON_A) {
		return 'A';
	}
	else if (WpadPressed & WPAD_BUTTON_B) {
		return 'B';
	}
	else if (WpadPressed & WPAD_BUTTON_1) {
		return '1';
	}
	else if (WpadPressed & WPAD_BUTTON_2) {
		return '2';
	}
	else if (WpadPressed & WPAD_BUTTON_PLUS) {
		return '+';
	}
	else if (WpadPressed & WPAD_BUTTON_MINUS) {
		return '-';
	}
	else if (WpadPressed & WPAD_BUTTON_HOME) {
		return 'H';
	}
	else if (WpadPressed & WPAD_BUTTON_LEFT) {
		return 'L';
	}
	else if (WpadPressed & WPAD_BUTTON_RIGHT) {
		return 'R';
	}
	else if (WpadPressed & WPAD_BUTTON_UP) {
		return 'U';
	}
	else if (WpadPressed & WPAD_BUTTON_DOWN) {
		return 'D';
	}
	return '\0';
}

/*!
	\fn
	\brief Convert the handleInput() button codes to a string.

	\param button A char corresponding to the button that was pressed.
	\returns A string corresponding to the button that was pressed.
*/
char* convertInputToString(const char &button) {
	switch (button) {
		case 'A': {
			return (char *)"A";
		}
		case 'B': {
			return (char *)"B";
		}
		case '1': {
			return (char *)"1";
		}
		case '2': {
			return (char *)"2";
		}
		case '+': {
			return (char *)"+";
		}
		case '-': {
			return (char *)"-";
		}
		case 'H': {
			return (char *)"Home";
		}
		case 'L': {
			return (char *)"Left";
		}
		case 'R': {
			return (char *)"Right";
		}
		case 'U': {
			return (char *)"Up";
		}
		case 'D': {
			return (char *)"Down";
		}
		default: {
			return nullptr;
		}
	}
}
