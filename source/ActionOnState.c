#include "head/StdC_Headers.h"
#include "head/funcDecl.h"

int CheckForNewAction() {
	//printf(CurrentState);
	if (strncmp(CurrentState, "None", 4) == 0) {
		return 0;
	}
	//size_t len = strlen(CurrentState);
	else if (strncmp(CurrentState, "TestMenu", 8) == 0) {
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
		return 0;
	}
	else if (strncmp(CurrentState, "ExitToHBC", 9) == 0) {
		ScrollAway();
		ClearConsole();
		printf("Exiting...\x0A");
		exit(0);
	}
	else {
		printf("Uh oh!  You tried to call value '%s', which doesn't have an action handler implemented yet!\x0A", CurrentState);
		printf("Exiting to avoid issues.");
		sleep(7.5);
		exit(1);
	}
	printf("Why in the actual heck could it get past an if-else statement,\x0A");
	printf("this is VERY bad, please report error code 1 to the GitHub issues\x0A");
	printf("page (https://github.com/sanikdah/My-Wii-Homebrew-App/).\x0A");
	printf("Exiting in 20 seconds to avoid corruption...");
	sleep(20);
	exit(1);
}
