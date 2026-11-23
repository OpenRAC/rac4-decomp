/* Not matching yet: PAL WIP; level_01 .text 0x00427C80, 308B. Not part of the build. */
/*
 * One supported native-normalized u8 local/default trial emits304B versus true308B; native two
 * ANDI normalizations are optimized away and status-register/branch allocation still differs.
 * Explicit required outer-pointer call also schedules a0 restore where native has NOP. Independent
 * level41 exact-call-target binding issue remains for the shared extern. No additional supported
 * source/dataflow distinction remains within
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: aa9483fc74b2c39cfc1be10fc8cd914ce7e0290bcdbcb5afcfc227dd4539149a
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00427C80 nonmatching/pal/shared/func_L01_00427C80.c --diff
 */
#include "common.h"

s32 func_00540958(void *);
s32 func_L01_004279B0(void *);

s32 func_L01_00427C80(void *arg0, void *arg1, s32 arg2) {
    s32 temp_v1;
    s32 var_s3;
    s32 var_v0;
    u8 predicate;
    void *temp_v0;

    var_s3 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x25D4))) != 0x14) {
        var_v0 = 0;
        if (!((*(f32 *)((s8 *)(arg0) + (0x2E20))) <= 0.0f)) {
            temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x25CC)));
            if ((temp_v1 != 0x39) && (temp_v1 != 0x68) && (temp_v1 != 0x6A) && (temp_v1 != 0x76) && (temp_v1 != 0x7A) && (temp_v1 != 0x7B) && (temp_v1 != 0x7E) && (temp_v1 != 0x7F) && (temp_v1 != 0x94)) {
                var_v0 = 0;
                if (temp_v1 != 0x99) {
                    var_v0 = 0;
                    if (func_00540958(arg0) == 0) {
                        temp_v0 = (*(void **)((s8 *)(arg0) + (0x2EFC)));
                        predicate = 0;
                        if (temp_v0 != NULL) {
                            if ((*(u8 *)((s8 *)(temp_v0) + (0x27B))) != 0) {
                                predicate = (*(s32 *)((s8 *)(arg0) + (0x25CC))) == 0x31;
                            }
                        }
                        var_v0 = 0;
                        if (predicate == 0) {
                            var_v0 = 0;
                            if (((*(s32 *)((s8 *)(arg0) + (0x2EF4))) == 0) && ((arg2 == 0) || (var_v0 = 0, (func_L01_004279B0(arg1) == 0)))) {
                                var_s3 = 1;
                                goto block_22;
                            }
                        }
                    }
                }
            } else {
                goto block_22;
            }
        }
    } else {
block_22:
        var_v0 = var_s3;
    }
    return var_v0;
}
