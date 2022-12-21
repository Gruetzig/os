#include "types.h"
#include "drawing/drawing.h"

u8* screen;

void main(int argc, char *argv[])
{
	InitScreenFbs(argc, argv);
	ClearScreenFull(true, true);
	int color = COLOR_WHITE;
	screen = GetScreen(1);
	int i;
	for (i=0;i<10;i++) {
		DrawCircle(50, 50, i, color, screen);
	}
  	
}
