#include <stdint.h>
#include <stdio.h>
#include "inc/errnum.hpp"
void panic(uint8_t err) {
    printf(" \
Woaaahhhh.  Slow down!\r\n \
You just managed to crash the program!\r\n");
    switch (err) {
        case ERR_NO_MENU_OPTS:
            printf("The menu that you just tried to access has no options!\r\n");
            break;
        case ERR_NO_MENU_DATA:
            printf("The menu that you just tried to access has no data at all!\r\n");
            break;
        case ERR_NO_MENU_OPTNAMES:
            printf("The menu that you just tried to access has no option names!\r\n");
            break;
        case ERR_NO_MENU_TITLE:
            printf("The menu that you just tried to access has no title!\r\n");
            break;
        default:
            printf(
"Dang man, you just got double errored!  Some error caused this screen to show,\r\n \
AND this screen tried to access an invalid error code!  We really don't know what happened here...");
    }
}
