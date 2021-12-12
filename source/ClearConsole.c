#include "head/StdC_Headers.h"

void ClearConsole() {
    printf("\033[H\033[2J");
    printf("\r\n");
}
