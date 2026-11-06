/* cflags:  */
#include "common.h"

extern void *func_0046DD08(int, int, int);
extern s32 func_L01_005715B0(void *, void *);
extern void func_L01_005713D8(void *);
extern void func_L01_005ACCA0(void *);
extern void func_0046C6B0(void *);
extern void func_L01_0058CDE8(void *);
extern void func_00474368(void *, int, int);

// Same sequence as func_L01_003D6868, but moves to state 0xD.
void func_L01_00493008(void *object) {
    unsigned char *linked = *(unsigned char **)((char *)object + 0xAC);
    void *callback = func_0046DD08(0x20ED, 0x12, 8);
    if (callback != 0) ((void (*)(void))(*(void **)((char *)callback + 4)))();
    if (*(int *)(linked + 0x324) != 0 && *(int *)(linked + 0x320) != 0)
        func_L01_005715B0(*(void **)(linked + 0x324), object);
    func_L01_005713D8(object);
    func_L01_005ACCA0(object);
    if (linked[0x460] != 0) {
        func_0046C6B0(object);
        return;
    }
    linked[0x48B] = 0;
    func_L01_0058CDE8(object);
    func_00474368(object, 0xD, -1);
}
