/* cflags: -Wuninitialized -Wa,-G0 */
#include "pal/decomp.h"
typedef int stack_output_s128 __attribute__((mode(TI)));
typedef char stack_output_alignment[(__alignof__(stack_output_s128)==16)?1:-1];
typedef char stack_output_width[(sizeof(stack_output_s128)==16)?1:-1];
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
typedef solver_s128 s128; typedef solver_u128 u128;
typedef char m2c_fpr_width[(sizeof(f32)==4)?1:-1];

M2C_UNK func_00453CE8(void *);                      /* extern */
void func_0046D258(void *, int, void *);             /* extern */
s32 func_0047F640(M2C_UNK);                         /* extern */
M2C_UNK func_L01_004710F0(void *, M2C_UNK *, s32, f32); /* extern */
M2C_UNK func_L01_00471338(void *, s128);            /* extern */
extern M2C_UNK D_00222C50;

/* Update the active record using one initialized temporary vector. */
void func_L01_00471480(void *arg0) {
    stack_output_s128 stack_value;
    s32 var_2;
    void *temp_16;

    temp_16 = M2C_FIELD(arg0, void **, 0xAC);
    if (M2C_FIELD(temp_16, s32 *, 0xA4) != 0) {
        func_0046D258(arg0, 1, &stack_value);
        func_00453CE8(temp_16 + 0xA8);
        if (M2C_FIELD(temp_16, s32 *, 0xA8) < 0xC) {
            if (M2C_FIELD(temp_16, s32 *, 0xA4) == 2) {
                var_2 = func_0047F640(0x80);
            } else {
                var_2 = 0x803040;
            }
            func_L01_004710F0(&stack_value, &D_00222C50, var_2, 0.349999994f);
        }
        if (((u32) M2C_FIELD(temp_16, s32 *, 0xA8) - 1U) < 0x31U) {
            func_L01_00471338(arg0, stack_value);
        }
    }
}
