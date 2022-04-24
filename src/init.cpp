#include <gccore.h>
#include <stdio.h>
#include <wiiuse/wpad.h>
/*!
    \fn
    \brief Intialize the graphics, Wii Remotes, GameCube controllers, and virtual console.

    \param xfb A reference to the framebuffer to use.
    \param rmode A reference to the video mode to use.
    
    \returns Nothing
*/
void init(void *&xfb, GXRModeObj *&rmode) {
    // Initialise the GPU
	VIDEO_Init();

    // Initialize the Wii Remotes
	WPAD_Init();

    // Initialize the GC controllers
    // PAD_Init();

    // Get the prefered video mode from the system settings
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate a frame buffer
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the virtual console
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video hardware for displaying graphics to the screen.
	VIDEO_Configure(rmode);

	// Tell the GPU where the framebuffer is at in RAM.
	VIDEO_SetNextFramebuffer(xfb);

	// Make the screen visible
	VIDEO_SetBlack(FALSE);

	// Flush the video config down the GPU toilet
	VIDEO_Flush();

	// Wait for vsync
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) {
        VIDEO_WaitVSync();
    }

    // Set the cursor position to row 2 column 0
	printf("\x1b[2;0H");
}
