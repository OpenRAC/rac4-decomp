/* cflags: -O2 -G8 */
#include "common.h"
int func_004765F0(int);
int func_004863F0(int,int);
void func_004869D8(s64,s64);
int func_004869E0(int,int);
void func_00486D58(int object) {
    int data = func_004765F0(object);
    if (!data) return;
    if (*(u16 *)(object + 0x34) & 1) return;
    if (!func_004765F0(object)) return;
    if (*(u32 *)(func_004765F0(object) + 4) & 0x100) return;
    if (*(float *)(data + 0xF8) > 0.0f) {
        switch (*(int *)(data + 0xFC)) {
        case 0:
        case 13:
        case 14:
            func_004863F0(object,data);
            break;
        case 1:
            func_004869D8(object,data);
            break;
        }
    } else if (*(float *)(data + 0xCC) > 0.0f) {
        func_004869E0(object,data);
        *(float *)(data + 0xCC) = 0.0f;
    }
}
