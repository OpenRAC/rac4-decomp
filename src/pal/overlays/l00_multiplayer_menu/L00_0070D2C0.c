#include "common.h"

typedef struct MenuFlags {
    u8 pad[4];
    u8 flags[2];
} MenuFlags;

typedef struct MenuRequest {
    s32 entry;
    s32 mode;
    s32 value;
    char prefix[15];
    char text[0x180];
} MenuRequest;

extern s32 func_0011AB04(const char *);
extern char *func_0011AFC8(char *, const char *, s32);
extern void func_L00_005C2988(char *, const char *, s32);
extern s32 func_L00_0070D860(char *, s32 *, char **);
extern MenuFlags *func_L00_0070D838(s32);
extern void func_L00_0070DA00(MenuRequest *);

void func_L00_0070D2C0(s32 *arg0) {
    char parsed[0x40];
    MenuRequest req;
    s32 entry;
    char *text;
    MenuFlags *data;
    s32 mode;

    func_L00_005C2988(parsed, (char *)arg0 + 0x2C, func_0011AB04((char *)arg0 + 0x2C));
    if (func_L00_0070D860(parsed, &entry, &text) != 0) {
        data = func_L00_0070D838(entry);
        mode = 2;
        if (arg0[2] == 0) {
            mode = 0;
        } else if (arg0[2] == 1) {
            mode = 1;
        }
        if (mode < 2 && data->flags[arg0[2]] != 0) {
            req.entry = entry;
            req.mode = mode;
            req.value = arg0[1];
            func_0011AFC8(req.prefix, (char *)arg0 + 0xC, 14);
            req.prefix[14] = 0;
            func_0011AFC8(req.text, text, 0x180);
            req.text[0x17F] = 0;
            func_L00_0070DA00(&req);
        }
    }
}
