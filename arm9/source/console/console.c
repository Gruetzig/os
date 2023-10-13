#include "console.h"

char consoleBuf[PRINTBUFMAX];
u32 consoleBufPos = 0;

s32 strlen(char* string) {
    for (int i = 0;i < PRINTBUFMAX;i++) {
        if (string[i] == '\0') return i;
    }
    return -1;
}

static inline void consoleBufAppend(char character) {
    consoleBuf[consoleBufPos] = character;
    consoleBufPos++;
}

void pushString(char* string, s32 len) {
    for (int i = 0;i < len;i++) {
        consoleBufAppend(string[i]);
    }
    consoleBuf[consoleBufPos+1] = '\0';
}

void this_printf(char* string) {
    s32 buflen = strlen(string);
    pushString(string, buflen);
}

void drawConsole() {
    u16 charposx = 0; 
    u16 charposy = 0;
    for (int i = 0;consoleBuf[i] != '\0' || i < PRINTBUFMAX;i++) {
        if (consoleBuf[i] == '\n') {
            charposy++;
            charposx = 0;
        } else if (consoleBuf[i] == '\r') {
            charposx = 0;
        } else {
            drawCharacter(true, (charposx * CHAR_SPACING_X), (charposy * CHAR_SPACING_Y), 0xFFFFFF, consoleBuf[i]);
            charposx++;
        }
    }
}    
