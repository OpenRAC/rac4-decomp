#include "common.h"

extern s32 func_L01_0056CDB0(void *);
extern void func_L01_0056E7F8(void *);
extern void func_L01_005A8928(void *);
extern void func_00591BD8(void *, int, int);
extern void func_L01_00588B08(void *);
extern void func_00586E80(void *);

// Run the three update calls and set state 0x15 (8), then run func_L01_00588B08
// when the +0x458 flag is clear, or func_00586E80 when flag is zero.
void func_L01_00494EF8(void *object, int flag) {
    unsigned char *linked = *(unsigned char **)((char *)object + 0xAC);
    func_L01_0056CDB0(object);
    func_L01_0056E7F8(object);
    func_L01_005A8928(object);
    func_00591BD8(object, 0x15, 8);
    if (linked[0x458] == 0) func_L01_00588B08(object);
    else if (flag == 0) func_00586E80(object);
}
