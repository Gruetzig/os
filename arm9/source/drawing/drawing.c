#include "drawing.h"

static u32 *top_screen0 = NULL;
static u32 *top_screen1 = NULL;
static u32 *bot_screen0 = NULL;
static u32 *bot_screen1 = NULL;

void InitScreenFbs(int argc, char *argv[]) //lel
{
	if (argc >= 2) {
		/* newer entrypoints */
		struct {
			u32 *top_left;
			u32 *top_right;
			u32 *bottom;
		} *fb = (void *)argv[1];
		top_screen0 = fb[0].top_left;
		top_screen1 = fb[1].top_left;
		bot_screen0 = fb[0].bottom;
		bot_screen1 = fb[1].bottom;
	} else {
		/* outdated entrypoints */
		top_screen0 = (u32 *)0x23FFFE00;
		top_screen1 = (u32 *)0x23FFFE00;
		bot_screen0 = (u32 *)0x23FFFE08;
		bot_screen1 = (u32 *)0x23FFFE08;
	}
}

void ClearScreen(u32 *screen, int width, int color) //stolen from firm_linux_loader
{
	if (color == COLOR_TRANSPARENT)
		color = COLOR_BLACK;

	for (int i = 0; i < (width * SCREEN_HEIGHT); i++) {
		*(screen++) = color >> 16;      // B
		*(screen++) = color >> 8;       // G
		*(screen++) = color & 0xFF;     // R
	}
}

void ClearScreenFull(bool clear_top, bool clear_bottom) //stolen from firm_linux_loader
{
	if (clear_top) {
		ClearScreen(top_screen0, SCREEN_WIDTH_TOP, COLOR_BLACK);
		ClearScreen(top_screen1, SCREEN_WIDTH_TOP, COLOR_BLACK);
	}
	if (clear_bottom) {
		ClearScreen(bot_screen0, SCREEN_WIDTH_BOT, COLOR_BLACK);
		ClearScreen(bot_screen1, SCREEN_WIDTH_BOT, COLOR_BLACK);
	}
}
u32* GetScreen(int screen) {
	if (screen == 1) return top_screen0; 
	if (screen == 2) return bot_screen0;
	if (screen == 3) return top_screen1;
	if (screen == 4) return bot_screen1;
	return 0;
}

void DrawPixel(int x, int y, int color, u32 *screen) { //stolen from GodMode9 :))
	int xDisplacement = (x * BYTES_PER_PIXEL * SCREEN_HEIGHT);
	int yDisplacement = ((SCREEN_HEIGHT - y - 1) * BYTES_PER_PIXEL);
	u32 *screenPos = screen + xDisplacement + yDisplacement;
	*(screenPos + 0) = color >> 16;         // B
	*(screenPos + 1) = color >> 8;          // G
	*(screenPos + 2) = color & 0xFF;        // R

}

void DrawCircle(int x, int y, int r, int color, u32 *screen) {
  int or[2] = {x + r, y + r};
  int ul[2] = {x - r, y - r};
  int dx;
  int dy;
  for (dx = ul[0]; dx < or[0]; dx++) {
    for (dy = ul[1]; dy < or[1]; dy++) {
      if (((x - dx) * (x - dx) + (y - dy) * (y - dy)) <= r*r) {
        DrawPixel(dx, dy, color, screen);
      }
    }
  }
}

void DrawRecFull(int x, int y, int w, int h, int color, u32 *screen) {
	int i;
	int j;
	for (i=x;i<=x+w;i++) {
		for (j=y;j<=y+h;y++) {
			DrawPixel(i, j, color, screen);
		}
	}
}
