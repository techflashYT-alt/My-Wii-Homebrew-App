#include "head/StdC_Headers.h"
#include "head/WiiHeaders.h"

char* checkAspect() {
	char* AspectRatio;
	if (CONF_GetAspectRatio() == CONF_ASPECT_16_9) {
		AspectRatio = "0";
		if (debugMode) {
			printf("Aspect ratio: 16:9");
		}
		return AspectRatio;
	}
	else if (CONF_GetAspectRatio() == CONF_ASPECT_4_3) {
		AspectRatio = "1";
		if (debugMode) {
			printf("Aspect ratio: 4:3");
		}
		return AspectRatio;
	}
	else {
		printf("Aspect ratio not set in system settings\x0Aor error trying to get the value!");
		printf("\x0AThings might go VERY wrong.");
		AspectRatio = "2";
	}
	return AspectRatio;
}
