/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void *D_002233A4;
extern char D_00220EA0[], D_00220EA8[], D_00220EB0[];
extern int func_004534D0(void *);
extern int func_L00_00767A50(void *, int);
extern void *func_0011AFC8(void *, const void *, unsigned int);
extern int func_0011D920(char *, const char *, ...);
extern int func_L00_00772630(void *, int, int, int *);
extern int func_L00_00725150(void *, int);
#define FIELD(p, t, n) (*(t *)((char *)(p) + (n)))
typedef void (*SetTextMethod)(void *, const char *);
typedef void (*ClearMethod)(void *);
#define SETTEXT(p, s) FIELD(FIELD(p, void *, 0x58), SetTextMethod, 0xE8)(p, s)
#define CLEAR(p) FIELD(FIELD(p, void *, 0x58), ClearMethod, 0xE4)(p)
void func_L00_00725188(void *self) {
    char tag[16];
    char name[16];
    char text[16];

    int stats[100];
    void *profile;
    void *widget;
    void *widget6;
    void *widget5;
    void *widget4;
    void *widget3;
    void *widget2;
    void *widget1;
    int first, second;
    profile = FIELD(D_002233A4, void *, 0x3C);
    func_004534D0((char *)self + 0x370);
    if (FIELD(self, int, 0x370) <= 0) {
        func_L00_00767A50(profile, 0);
        widget = FIELD(self, void *, 0xC0);
        FIELD(self, int, 0x370) = 0x384;
        SETTEXT(widget, (char *)profile + 4);
        func_0011AFC8(tag, (char *)profile + 44, 4);
        tag[4] = 0;
        func_0011D920(name, D_00220EA0, tag);
        widget1 = FIELD(self, void *, 0xD4);
        SETTEXT(widget1, name);
        if (func_L00_00772630(FIELD(D_002233A4, void *, 0x50), FIELD(profile, int, 0), 1, stats)) {
            func_0011D920(text, D_00220EA8, stats[2], stats[3]);
            widget2 = FIELD(self, void *, 0xCC);
            SETTEXT(widget2, text);
            func_0011D920(text, D_00220EA8, stats[0], stats[1]);
            widget3 = FIELD(self, void *, 0xD0);
            SETTEXT(widget3, text);
        } else {
            widget4 = FIELD(self, void *, 0xCC);
            CLEAR(widget4);
            widget5 = FIELD(self, void *, 0xD0);
            CLEAR(widget5);
        }
        first = func_L00_00725150(profile, 4);
        second = func_L00_00725150(profile, 10);
        func_0011D920(text, D_00220EB0, first, second);
        widget6 = FIELD(self, void *, 0xC8);
        SETTEXT(widget6, text);
    }
}
