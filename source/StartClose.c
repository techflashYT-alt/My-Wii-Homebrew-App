#include "head/StdC_Headers.h"
#include "head/funcDecl.h"

void StartClose() {
	ScrollAway();
	ClearConsole();
	printf("Exiting...\x0A");
	exit(0);
}
