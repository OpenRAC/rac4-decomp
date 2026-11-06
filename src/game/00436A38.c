#include "common.h"

typedef struct {
    u8 prefix[0x44];
    s32 kind, count;
} Config;
typedef struct {
    u8 prefix[0xAC];
    Config *config;
} Object;
typedef struct {
    u8 prefix[0x14];
    u32 flags;
    u8 unused18;
    u8 count;
} Message;

void func_00436A38(Object *object, Message *message)
{
    Config *config = object->config;
    switch (config->kind) {
    case 3:
        message->flags |= 0x800000;
        break;
    case 7:
        message->flags |= 0x80;
        break;
    case 8:
        message->flags |= 0x40;
        break;
    case 6:
        message->flags |= 0x100;
        break;
    case 5:
        message->flags |= 0x400;
        break;
    }
    if (config->count > 0) {
        message->flags |= 0x20;
        message->count += config->count;
    }
}
