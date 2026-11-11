#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);

/* copies a string into the object's buffer and counts its length */
void func_L00_0071AB68(u8 *object, char *value) {
    u8 *cursor = object + 0x28C;
    *(char **)(object + 0x288) = value;
    func_0011AFC8((char *)cursor, value, 0xC8);
    *(s32 *)(object + 0x354) = 0;
    if (*cursor != 0) {
        do {
            cursor++;
            *(s32 *)(object + 0x354) += 1;
        } while (*cursor != 0);
    }
}
