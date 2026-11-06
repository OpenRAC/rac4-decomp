#include "common.h"
float D_00220FEC = 0.18f, D_00220FF0 = 0.82f, D_00220FF4 = 0.18f, D_00220FF8 = 0.89f;
extern int D_001D3F40[];
extern void func_00449E98(int, int, int, int, u64);
void func_0054CBE0(void)
{
    float w = (float)D_001D3F40[0];
    float h = (float)D_001D3F40[1];
    func_00449E98((int)(h * D_00220FF4), (int)(h * D_00220FF8), (int)(w * D_00220FEC), (int)(w * D_00220FF0), 0x64191919);
}
