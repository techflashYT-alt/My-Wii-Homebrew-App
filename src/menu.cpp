#include <stdio.h>
#include <stdint.h>
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

void printMenu(menu_t &menu) {
    printf("%s\r\n", menu.title);
    for (uint8_t i = 0; i < 8; i++) {
        if (menu.submenus[i] != NULL) {
            printf("  %s\r\n", menu.optionNames[i]);
        }
        else {
            i = 5; // Skip past the submenu option names
            printf("  %s\r\n", menu.optionNames[i]);
        }
    }
}
