/* cflags: -O2 -G8 */
#include "common.h"
extern void func_0011A518(void *, int, int);
extern float func_L00_0069F928(int);
extern void func_L00_00769F98(void *, int, int, float, float, float);
void func_L00_00769EB8(int a, int b, int c, void *d, int e, float f)
{
    char data[80];
    float x;
    float y;
    void **table;
    func_0011A518(data, 0, 80);
    x = func_L00_0069F928(c);
    table = *(void ***)((char *)d + 88);
    y = ((float (*)(void *))table[72])(d);
    func_L00_00769F98(data, a, b, y, x, f);
    if (e)
        ((void (*)(void *, void *))(*(void ***)((char *)d + 88))[10])(d, data);
    else
        ((void (*)(void *, void *))(*(void ***)((char *)d + 88))[58])(d, data);
}
