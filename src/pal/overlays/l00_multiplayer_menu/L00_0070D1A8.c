#include "common.h"

typedef struct MenuFlags { u8 pad[4]; u8 flags[2]; } MenuFlags;

typedef struct MenuRequest {
    s32 entry;
    s32 mode;
    s32 value;
    char prefix[15];
    char text[0x180];
} MenuRequest;

extern s32 func_0011AB04(const char *);
extern char *func_0011A9EC(char *, const char *);
extern char *func_0011AFC8(char *, const char *, s32);
extern void func_L00_005C2988(char *, const char *, s32);
extern s32 func_L00_0070D860(char *, s32 *, char **);
extern MenuFlags *func_L00_0070D838(s32);
extern void func_L00_0070DA00(MenuRequest *);

void func_L00_0070D1A8(s32 *arg0) {
    char input[16];
    char parsed[0x180];
    MenuRequest req;
    s32 entry;
    char *text;
    MenuFlags *data;
    s32 mode;

    __builtin_memcpy(input, arg0 + 8, 14);
    input[14] = 0;
    func_L00_005C2988(parsed, (char *)arg0 + 0x2F, func_0011AB04((char *)arg0 + 0x2F));
    if (func_L00_0070D860(parsed, &entry, &text) != 0) {
        data = func_L00_0070D838(entry);
        mode = 2;
        if (*(s32 *)((u8 *)arg0 + 0x1C) == 0) {
            mode = 0;
        } else if (*(s32 *)((u8 *)arg0 + 0x1C) == 1) {
            mode = 1;
        }
        if (mode < 2 && data->flags[*(s32 *)((u8 *)arg0 + 0x1C)] != 0) {
            req.entry = entry;
            req.mode = mode;
            req.value = *(s32 *)((u8 *)arg0 + 0x18);
            func_0011A9EC(req.prefix, input);
            func_0011AFC8(req.text, text, 0x180);
            req.text[0x17F] = 0;
            func_L00_0070DA00(&req);
        }
    }
}
