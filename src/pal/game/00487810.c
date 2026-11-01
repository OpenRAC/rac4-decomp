/* cflags: -O2 -G8 */
#include "common.h"
int func_00476ED0(int);
int func_00486E28(int,int);
void func_00487440(s64,s64);
int func_00487448(int,int);
void func_00487810(int object) {
    int data = func_00476ED0(object);
    if (!data) return;
    if (*(u16 *)(object + 0x34) & 1) return;
    if (!func_00476ED0(object)) return;
    if (*(u32 *)(func_00476ED0(object) + 4) & 0x100) return;
    if (*(float *)(data + 0xF8) > 0.0f) {
        switch (*(int *)(data + 0xFC)) {
        case 0:
        case 13:
        case 14:
            func_00486E28(object,data);
            break;
        case 1:
            func_00487440(object,data);
            break;
        }
    } else if (*(float *)(data + 0xCC) > 0.0f) {
        func_00487448(object,data);
        *(float *)(data + 0xCC) = 0.0f;
    }
}
