#include "common.h"

extern void *func_L01_006B4FC0(void *, int, int, int);
extern void func_00611808(void *, void *, int);

// Write the given 32-bit value into the object through a sink made from it.
void func_L41_00417780(void *object, int value) {
    void *sink = func_L01_006B4FC0(object, 0, 0, 0xFA);
    int local = value;
    func_00611808(sink, &local, 4);
}
