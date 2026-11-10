#include "common.h"

typedef struct {
    s32 type, size, offset, state;
} Descriptor;
extern Descriptor D_003D8130[], D_003D8310[];
extern s32 func_004693D0(const Descriptor *);
extern s32 func_004696E8(const u8 *, const u8 *, s32, Descriptor *);
extern void func_00469D68(void);
void func_004660F8(const u8 *packet)
{
    s32 first = func_004693D0(D_003D8130);
    s32 second = func_004693D0(D_003D8310);
    s32 index;
    const u8 *next;
    s32 storedFirst = *(const s32 *)packet;
    if (storedFirst == first && *(const s32 *)(packet + 4) == second) {
        packet += 8;
        next = packet + storedFirst;
        func_004696E8(packet, next, 0, D_003D8130);
        packet = next;
        index = 0;
        do {
            const u8 *end = packet + second;
            func_004696E8(packet, end, index, D_003D8310);
            index++;
            packet = end;
        } while (index < 15);
        func_00469D68();
    }
}
