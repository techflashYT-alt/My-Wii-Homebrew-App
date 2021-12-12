#include "head/funcDecl.h"
#include "head/StdC_Headers.h"

struct MenuOpts {
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

struct menu {
	char* name[100];
	int selected;
	struct MenuOpts options;
	bool isHorizontal;
};

void displayMenu(char* menuName[100], bool Horizontal, int optionsNum, struct MenuOptions MenuOptions) {
	printf("\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A");
	printf("\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A\x0A");
	ClearConsole();
	struct menu menu;
	menu.name[0] = menuName[0];
	printf(menu.name[0]);
	printf("\x0a\x0A\x0A");

	for (int i = 1; i <= optionsNum; i++) {
		if (i == 1) {
			menu.options.One[0] = MenuOptions.One[0];
			printf(menu.options.One[0]);
			printf("\x0a");
		}
		else if (i == 2) {
			menu.options.Two[0] = MenuOptions.Two[0];
			printf(menu.options.Two[0]);
			printf("\x0a");
		}
		else if (i == 3) {
			menu.options.Three[0] = MenuOptions.Three[0];
			printf(menu.options.Three[0]);
			printf("\x0a");
		}
		else if (i == 4) {
			menu.options.Four[0] = MenuOptions.Four[0];
			printf(menu.options.Four[0]);
			printf("\x0a");
		}
		else if (i == 5) {
			menu.options.Five[0] = MenuOptions.Five[0];
			printf(menu.options.Five[0]);
			printf("\x0A");
		}
		else {
			printf("uh oh");
		}
	};
}
