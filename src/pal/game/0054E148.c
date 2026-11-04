#include "common.h"
float D_0022108C = 0.18f, D_00221090 = 0.82f, D_00221094 = 0.16f, D_00221098 = 0.88f;
extern int D_001D3FC0[];
extern void func_0044A540(int, int, int, int, u64);
void func_0054E148(void)
{
    float w = (float)D_001D3FC0[0];
    float h = (float)D_001D3FC0[1];
    func_0044A540((int)(h * D_00221094), (int)(h * D_00221098), (int)(w * D_0022108C), (int)(w * D_00221090), 0x64191919);
}
