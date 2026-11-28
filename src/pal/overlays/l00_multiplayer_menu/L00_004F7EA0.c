/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef void (*EventCallback)(void *);
typedef void (*EventNotification)(s32, s32, s32 *, s32, u64, s32);

typedef struct {
    u8 pad00[0x04];
    EventCallback f04;
    u8 pad08[0x18 - 0x08];
    EventCallback f18;
    u8 pad1C[0x40 - 0x1C];
    EventCallback f40;
    u8 pad44[0x84 - 0x44];
    void (*f84)(void *, u32, s32, EventNotification);
    EventCallback f88;
    EventCallback f8C;
    u8 pad90[0xCC - 0x90];
    EventCallback fCC;
    u8 padD0[0xD8 - 0xD0];
    EventCallback fD8;
} EventCallbacks;

extern EventCallbacks D_00466800;
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);

#define REPORT_UNREGISTERED_CALLBACK(code) func_L00_004F89C8(26, (code), 14, NULL, 0)

void func_L00_004F7EA0(void *object)
{
    if (D_00466800.f04 != NULL) {
        D_00466800.f04(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x70);
    }
}

void func_L00_004F7FC0(void *object)
{
    if (D_00466800.f18 != NULL) {
        D_00466800.f18(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x88);
    }
}

void func_L00_004F8128(void *object)
{
    if (D_00466800.f40 != NULL) {
        D_00466800.f40(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x7C);
    }
}

void func_L00_004F84E0(void *object, u32 value, s32 argument, EventNotification notify)
{
    if (D_00466800.f84 != NULL) {
        D_00466800.f84(object, value, argument, notify);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x8F);
    }
}

void func_L00_004F8528(void *object)
{
    if (D_00466800.f88 != NULL) {
        D_00466800.f88(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x98);
    }
}

void func_L00_004F8570(void *object)
{
    if (D_00466800.f8C != NULL) {
        D_00466800.f8C(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x89);
    }
}

void func_L00_004F8720(void *object)
{
    if (D_00466800.fCC != NULL) {
        D_00466800.fCC(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x86);
    }
}

void func_L00_004F87B0(void *object)
{
    if (D_00466800.fD8 != NULL) {
        D_00466800.fD8(object);
    } else {
        REPORT_UNREGISTERED_CALLBACK(0x88);
    }
}
