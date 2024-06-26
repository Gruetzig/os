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
#include "pxi.h"
#include "print.h"
#include "console.h"

int main(int argc, char *argv[]) {
    PXI_Init();
    printf("Hello from ARM11");
    drawConsole();
    PXI_Synchronize(0x87);
    PXI_SendBuffer("Hello from ARM11", 17);
    printf("Hello from ARM11");
    drawConsole();
	while (1);
    return 0;
}