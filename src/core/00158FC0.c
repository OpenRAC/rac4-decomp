#include "common.h"

/* Increments the counter that a gp-relative pointer table selects, then calls func_00157F98. */
extern s32 func_00157F98(void);
s32 *D_0021DCC8[2] = { 0, 0 };
s32 D_0021DCE8 = 0;

void func_00158FC0(void)
{
	s32 *p;

	p = D_0021DCC8[D_0021DCE8];
	*p += 1;
	func_00157F98();
}
