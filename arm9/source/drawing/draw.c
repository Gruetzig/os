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

#include "draw.h"

struct {
	u8 *top_left;
	u8 *top_right;
	u8 *bottom;
} *fb;

FrameBufs fbs[2];

void InitScreenFbs(int argc, char *argv[]) {
	struct {
		u8 *top_left;
		u8 *top_right;
		u8 *bottom;
	} *fb = (void *)argv[1];


	fbs[0].top_left = fb[0].top_left;
	fbs[1].top_left = fb[1].top_left;
	fbs[0].bottom = fb[0].bottom;
	fbs[1].bottom = fb[1].bottom;
}
