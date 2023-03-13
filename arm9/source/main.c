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
	DrawRecFull(10, 10, 50, 50, color, screen);
  	while (true) {//Main Loop 
	
		if (HID_PAD & BUTTON_START) {
			poweroff();
		}
	}
	
}
