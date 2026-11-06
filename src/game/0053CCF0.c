#include "common.h"
extern void *func_0053C9F0(char *, int, int);
extern char *func_0053C920(char *, int, int, int);
extern void func_0053CAA8(void *, const void *, int);
void func_0053CCF0(char *p, int value, unsigned short type, int extra)
{
    char *event;
    int data;
    if (type == 6 || type == 13) {
        if (*(int *)(p + 0x304))
            return;
        *(int *)(p + 0x304) = 1;
    }
    if (func_0053C9F0(p, type, 0))
        return;
    event = func_0053C920(p, type, 0, -1);
    data = value;
    func_0053CAA8(event, &data, 4);
    *(int *)(event + 0x50) = extra;
    *(int *)(p + 0x320) = 0;
}
