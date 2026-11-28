#include "common.h"
#include "pal/global_002234A4.h"

typedef struct {
    u8 pad[0x64];
    char *name;
} PalMenuRequestContext;

typedef struct {
    u16 operation;
    u8 pad02[0x13];
    char name[0x13];
    s32 count;
    s32 value;
} PalMenuRequest;

typedef struct {
    u8 active;
    u8 pad01[7];
    u8 pending;
    u8 pad09[3];
    s32 timestamp;
    u8 pad10[4];
    s32 value;
} PalMenuRequestSlot;

typedef struct {
    u8 pad000[0x440];
    PalMenuRequestSlot f440;
    u8 pad458[0x20];
    PalMenuRequestSlot f478;
} PalMenuRequestSlots;

extern u16 D_002218A0[];
char *func_0011A9EC(char *, char *);
u64 func_0012E370(void);
u64 func_0012FEB0(u64, u64);
void func_0015CE68(void);
void func_0015CEE0(void);
void func_0015B558(s32);
s32 func_0015B568(void);
s32 func_01ED4B98(u8 *, s32, s32);
s32 func_01ED4C18(u8 *, s32, s32);

static inline void initialize_menu_request(PalMenuRequest *request) {
    PalMenuRequestContext *context;
    char *name;

    context = D_002234A4;
    name = context->name;
    request->operation = D_002218A0[0];
    func_0011A9EC(request->name, name);
}

s32 func_L00_0076F668(u8 *state) {
    PalMenuRequestSlots *slots = (PalMenuRequestSlots *)state;
    PalMenuRequest request;
    s32 ok;

    ok = 1;
    if (slots->f440.active != 0) {
        initialize_menu_request(&request);
        slots->f440.pending = 1;
        request.count = 1;
        request.value = slots->f440.value;
        slots->f440.timestamp = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B558(func_01ED4C18((u8 *)&request, (s32)func_0015CEE0, 0));
        if (func_0015B568() != 0) {
            ok = 0;
        }
    }
    return ok;
}

s32 func_L00_0076FB48(u8 *state) {
    PalMenuRequestSlots *slots = (PalMenuRequestSlots *)state;
    PalMenuRequest request;
    s32 ok;

    ok = 1;
    if (slots->f478.active != 0) {
        initialize_menu_request(&request);
        slots->f478.pending = 1;
        request.count = 1;
        request.value = slots->f478.value;
        slots->f478.timestamp = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B558(func_01ED4B98((u8 *)&request, (s32)func_0015CE68, 0));
        if (func_0015B568() != 0) {
            ok = 0;
        }
    }
    return ok;
}
