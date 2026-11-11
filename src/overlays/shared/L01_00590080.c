#include "common.h"

extern float func_L01_00590080(float scale);
extern int func_001633D0(void);

/* from rac3-decomp's func_L01_00443AC0 */
float func_L01_00590080(float scale)
{
  float r = ((float) (0xFFF & (func_001633D0() >> 16))) * (1.0f / 4096.0f);
  float new_var;
  new_var = r * r;
  new_var = 1.0f - new_var;
  return new_var * scale;
}
