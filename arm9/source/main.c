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
#include "buttons.h"
#include "console.h"
#include "print.h"
#include "i2c.h"
#include "pxi.h"

void poweroff() {
	i2cWriteRegister(I2C_DEV_MCU, 0x20, 1 << 0);
	while (1);
}

int main(int argc, char *argv[]) {
    PXI_Init();
    InitScreenFbs(argc, argv);
    printf("Hello from ARM9\n");
    drawConsole();
    u32 size = 0;
    char *buf = PXI_RecvBuffer(&size);
    printf("Eh: %d %d", buf, size);
    drawConsole();
	while (!(HID_PAD & BUTTON_START));
    poweroff();
    return 0;
}
