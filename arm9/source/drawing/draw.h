/* Copyright (C) 2023 Gruetzig

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "types.h"

#ifndef DRAW_H
#define DRAW_H


typedef struct framebuffers{
	u8 *top_left;
	u8 *top_right;
	u8 *bottom;
} FrameBufs;

extern FrameBufs fbs[2];

#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH_TOP 400
#define SCREEN_WIDTH_BOTTOM 320

#endif