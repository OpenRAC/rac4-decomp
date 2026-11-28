#include "common.h"

#include "pal/global_002234A4.h"

typedef struct {
    u16 x00;
    u8 pad02[0x13];
    char x15[0x11];
    u8 x26[16];
} Request;

typedef struct {
    u8 pad00[0x64];
    char *x64;
} Context;

extern u16 D_00221A18[];
extern void func_0015D4A8(void);
extern char *func_0011A9EC(char *, char *);
extern s32 func_01ED7AF0(void *, void (*callback)(void), s32);
extern void func_0015B558(s32);

static inline void prepare_request(Request *request)
{
    Context *context = D_002234A4;
    char *name = context->x64;
    request->x00 = D_00221A18[0];
    func_0011A9EC(request->x15, name);
}

/* Submit the set request once and mark it active. */
s32 func_L00_007819A8(u8 *object)
{
    Request request;
    s32 i;
    s32 result = 0;

    if (object[0x2F5C] == 0) {
        prepare_request(&request);
        {
            u8 *byte;
            i = 15;
            byte = (u8 *)&request + sizeof(request) - 1;
            do {
                *byte-- = 0xFF;
            } while (--i >= 0);
        }
        func_0015B558(func_01ED7AF0(&request, func_0015D4A8, 0));
        object[0x2F5C] = 1;
        result = 1;
    }
    return result;
}

/* Submit the clear request when the flag is active. */
s32 func_L00_00781A48(u8 *object)
{
    Request request;
    s32 i;
    s32 result = 0;

    if (object[0x2F5C] != 0) {
        prepare_request(&request);
        {
            u8 *byte;
            i = 15;
            byte = (u8 *)&request + sizeof(request) - 1;
            do {
                *byte-- = 0;
            } while (--i >= 0);
        }
        func_0015B558(func_01ED7AF0(&request, func_0015D4A8, 0));
        object[0x2F5C] = 0;
        result = 1;
    }
    return result;
}
