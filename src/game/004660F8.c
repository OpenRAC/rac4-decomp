#include "common.h"

typedef struct {
    s32 type, size, offset, state;
} Descriptor;
extern Descriptor D_003D80F0[], D_003D82D0[];
extern s32 func_00468B40(const Descriptor *);
extern s32 func_00468E58(const u8 *, const u8 *, s32, Descriptor *);
extern void func_004694B0(void);
void func_004660F8(const u8 *packet)
{
    s32 first = func_00468B40(D_003D80F0);
    s32 second = func_00468B40(D_003D82D0);
    s32 index;
    const u8 *next;
    s32 storedFirst = *(const s32 *)packet;
    if (storedFirst == first && *(const s32 *)(packet + 4) == second) {
        packet += 8;
        next = packet + storedFirst;
        func_00468E58(packet, next, 0, D_003D80F0);
        packet = next;
        index = 0;
        do {
            const u8 *end = packet + second;
            func_00468E58(packet, end, index, D_003D82D0);
            index++;
            packet = end;
        } while (index < 15);
        func_004694B0();
    }
}
