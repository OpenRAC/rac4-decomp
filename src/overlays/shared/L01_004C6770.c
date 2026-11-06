#include "common.h"

extern void func_L01_004C67F0(void);
extern void func_L01_004C6A60(void *);
extern void func_L01_004C6C08(void *);
extern void func_L01_004C6DC8(void *);
extern void func_L01_004C7920(void *, int);
extern void func_L01_004C7970(void *);
extern void func_L01_004C7980(void *);

// Per-frame update: nothing without a +0xAC block; state 0 runs
// func_L01_004C67F0 only, other states run the six update calls.
void func_L01_004C6770(void *object) {
    if (*(void **)((char *)object + 0xAC) == 0) return;
    if (*(unsigned char *)((char *)object + 0x20) == 0) {
        func_L01_004C67F0();
        return;
    }
    func_L01_004C6A60(object);
    func_L01_004C6C08(object);
    func_L01_004C6DC8(object);
    func_L01_004C7920(object, 1);
    func_L01_004C7970(object);
    func_L01_004C7980(object);
}
