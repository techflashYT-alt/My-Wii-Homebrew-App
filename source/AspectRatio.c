#include "head/StdC_Headers.h"
#include "head/WiiHeaders.h"

char* checkAspect() {
    char* AspectRatio;
	if (CONF_GetAspectRatio() == CONF_ASPECT_16_9) {
        AspectRatio = "16:9";
		if (debugMode) {
			printf("Aspect ratio: %s\r\n", AspectRatio);
		}
	}
	else if (CONF_GetAspectRatio() == CONF_ASPECT_4_3) {
            AspectRatio = "4:3";
			if (debugMode) {
				printf("Aspect ratio: %s\r\n", AspectRatio);
			}
	}
	else {
		printf("Aspect ration not set in system settings\x0Aor error trying to get the value!");
		printf("\x0AThings might go VERY wrong.");
		AspectRatio = "Unknown";
	}
    return AspectRatio;
}
