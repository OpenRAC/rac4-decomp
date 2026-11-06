#include "common.h"

/* Reads the signed word at offset 0x440 of the linked object. */
s32 func_L10_004D5E10(void *arg0)
{
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0xAC) + 0x440);
}
