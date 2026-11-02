#include "common.h"
extern float func_00472F70(void);
extern void *func_00414D48(void *, float, float, void *, unsigned char, unsigned char);
/* Spawn the object using a generated third vector component. */
void *func_00414EC0(void *p, unsigned char a, unsigned char b, float x, float y)
{
    float v[4];
    v[2] = func_00472F70();
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[3] = 0.0f;
    return func_00414D48(p, x, y, v, a, b);
}
