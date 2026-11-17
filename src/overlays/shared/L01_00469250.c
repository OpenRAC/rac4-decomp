#include "common.h"

extern void func_L00_005F1520(int);
extern void func_L01_00468F58(void *);

void func_L01_00469250(void *arg0) {
    void *temp = *(void **)((char *)arg0 + 0xAC);

    *(short *)((char *)temp + 0x4FE) = -1;
    func_L00_005F1520((int)arg0);
    func_L01_00468F58(arg0);
}
