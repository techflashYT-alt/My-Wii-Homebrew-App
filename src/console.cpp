#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
/*!
	\fn
	\brief Clear the console screen.

	\returns Nothing
*/
void consoleClear() {
	printf("\033[2;0H\033[2J");
}
/*!
	\fn
	\brief Moves the cursor the specified row and column.
	
	\param x The row to move the cursor to.
	\param y The column to move the cursor to.
	\returns Nothing
*/
void consoleMove(uint8_t x, uint8_t y) {
	printf("\033[%d;%dH", y, x);
}
/*!
	\fn
	\brief Scroll the console up by printing a ton of newlines.
	
	\returns Noting
*/
void consoleScroll() {
	printf("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
	consoleClear();
}
