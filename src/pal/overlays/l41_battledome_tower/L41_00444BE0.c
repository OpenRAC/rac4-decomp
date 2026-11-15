#include "common.h"

typedef struct {
    u8 unknown[0x80];
    s32 value;
    s32 flags;
} Payload;

typedef struct {
    u8 unknown[0xAC];
    Payload *payload;
} Object;

extern void *func_L01_006BA588(Object *, s32, s32, s32);
extern void func_0053DE58(void *, void *, s32);

void func_L41_00444BE0(Object *object) {
    s32 value;
    s32 flags;
    void *packet = func_L01_006BA588(object, 0, 0, 250);
    Payload *payload = object->payload;
    if (packet != 0) {
        value = payload->value;
        func_0053DE58(packet, &value, 4);
        flags = payload->flags;
        func_0053DE58(packet, &flags, 4);
    }
}
