#include "common.h"
extern char *func_00549B18(int);
extern int func_0054A688(char *, int, int), func_00549C18(char *, int), func_0054A038(char *, int);
int func_0054A400(char *p, int id)
{
    if (((u32)id - 1) < 6) {
        int index = *(unsigned char *)(func_00549B18(id) + 8);
        func_0054A688(p, index, 1);
        if (func_00549C18(p, id) || id == 0) {
            *(unsigned char *)(p + index * 0x44 + 0xA40) = id;
            func_0054A038(p, id);
            return 1;
        }
    }
    return 0;
}
