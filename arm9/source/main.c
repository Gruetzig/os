#include "types.h"
#include "drawing/drawing.h"
#include "utils/utils.h"
#include "buttons.h"

u8* screen;

void main(int argc, char *argv[])
{
	InitScreenFbs(argc, argv);
	ClearScreenFull(true, true);
	int color = COLOR_WHITE;
	screen = GetScreen(1);
	DrawCircle(50, 50, 20, color, screen);
  	while (true) {//Main Loop 
	
		if (HID_PAD & BUTTON_START) {
			poweroff();
		}
	}
	
}
