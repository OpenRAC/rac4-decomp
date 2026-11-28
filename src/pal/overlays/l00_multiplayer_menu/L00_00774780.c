#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

typedef struct {
    u16 operation;
    u8 pad02[0x13];
    char name[0x13];
    s32 option;
} Request;

typedef struct {
    u8 pad00[0x10];
    s32 result;
    s32 previousResult;
    u8 pad18[0x4C];
    char *name;
} Context;

extern char *func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B558(s32 value);
extern s32 func_0015B568(void);
extern s32 func_01ED6E48(void *, void *, s32);
extern void func_0015D200(void);
extern u16 D_002218C8[];

s32 func_L00_00774780(u8 *state)
{
    Request request;
    s32 ok;
    Context *context;

    ok = 1;
    context = D_002234A4;
    *(s32 *)(state + 0xF94) = 0;
    request.operation = D_002218C8[0];
    func_0011A9EC(request.name, context->name);
    request.option = D_001721E0.region20.words.f124;
    state[0x12] = 1;
    *(s32 *)(state + 0x18) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B558(func_01ED6E48(&request, (void *)func_0015D200, 0));
    if (func_0015B568() != 0) {
        context->result = 0x39;
        if (context->previousResult == 0)
            context->previousResult = 0x39;
        ok = 0;
    }
    return ok;
}
