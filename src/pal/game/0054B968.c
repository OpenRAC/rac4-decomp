#include "common.h"
extern char *func_0054B080(int);
extern int func_0054BBF0(char *, int, int), func_0054B180(char *, int), func_0054B5A0(char *, int);
int func_0054B968(char *p, int id)
{
    if (((u32)id - 1) < 6) {
        int index = *(unsigned char *)(func_0054B080(id) + 8);
        func_0054BBF0(p, index, 1);
        if (func_0054B180(p, id) || id == 0) {
            *(unsigned char *)(p + index * 0x44 + 0xA40) = id;
            func_0054B5A0(p, id);
            return 1;
        }
    }
    return 0;
}
