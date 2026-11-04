#include "common.h"
void func_L00_00506368(void **arg0, void *arg1, void **arg2) {
    void *temp_v1;
    void *temp_v1_2;

    if (arg1 != *arg2) {
        if (arg1 == *arg0) {
            *arg0 = (*(void **)((u8 *)(arg1) + 0xC));
        }
        temp_v1 = (*(void **)((u8 *)(arg1) + 0x10));
        if (temp_v1 != NULL) {
            (*(void **)((u8 *)(temp_v1) + 0xC)) = (void *) (*(void **)((u8 *)(arg1) + 0xC));
        }
        temp_v1_2 = (*(void **)((u8 *)(arg1) + 0xC));
        if (temp_v1_2 != NULL) {
            (*(void **)((u8 *)(temp_v1_2) + 0x10)) = (void *) (*(void **)((u8 *)(arg1) + 0x10));
        }
        (*(void **)((u8 *)(*arg2) + 0xC)) = arg1;
        (*(void **)((u8 *)(arg1) + 0x10)) = (void *) *arg2;
        (*(void **)((u8 *)(arg1) + 0xC)) = NULL;
        *arg2 = arg1;
    }
}
