#include "common.h"

extern void *func_L00_005DEBD0(int, int, int);
extern void func_L01_0056E9D0(int, void *);
extern void func_L01_0056E7F8(void *);
extern void func_L01_005A8928(void *);
extern void func_L00_005DD4A0(void *);
extern void func_L01_00588B08(void *);
extern void func_L01_00591BD8(void *, int, int);

// Same sequence as func_L01_003D6868, but moves to state 0xD.
void func_L01_00491810(void *object) {
    unsigned char *linked = *(unsigned char **)((char *)object + 0xAC);
    void *callback = func_L00_005DEBD0(0x20ED, 0x12, 8);
    if (callback != 0) ((void (*)(void))(*(void **)((char *)callback + 4)))();
    if (*(int *)(linked + 0x324) != 0 && *(int *)(linked + 0x320) != 0)
        func_L01_0056E9D0(*(int *)(linked + 0x324), object);
    func_L01_0056E7F8(object);
    func_L01_005A8928(object);
    if (linked[0x460] != 0) {
        func_L00_005DD4A0(object);
        return;
    }
    linked[0x48B] = 0;
    func_L01_00588B08(object);
    func_L01_00591BD8(object, 0xD, -1);
}
