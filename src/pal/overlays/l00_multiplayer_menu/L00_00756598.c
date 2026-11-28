#include "common.h"
#include "pal/dialog_71d890.h"
#include "pal/global_002234A4.h"
#include "pal/multiplayer_menu.h"
#include "pal/request_761c88.h"

extern s32 D_00223508;

extern s32 func_L00_007697C0(s32 identifier);
extern const char *func_0045E850(s32 id);
extern s32 func_L00_00780F40(void *state, char *text, s32 option);
extern void func_L00_005C2930(char *dst, char *src, s32 n);
extern s32 func_L00_0070D8B0(PalRequest761C88 *);

/* Submit the text request and show the corresponding confirmation or error. */
void func_L00_00756598(s32 value, char *text)
{
    PalRequest761C88 request;
    struct Context *context = D_00220DD4;
    s32 result = func_L00_00780F40(*(void **)((u8 *)D_002234A4 + 0x68), text, 0);

    if (result != 0) {
        s32 finished;
        request.word_08 = value;
        request.word_04 = 1;
        request.word_00 = D_00223508;
        func_L00_005C2930(request.text_1b, text, 0x180);
        request.text_1b[383] = 0;
        finished = 0;
        do {
            result = func_L00_0070D8B0(&request);
            if (result == 0) {
                const char *label = func_0045E850(0x2ED6);
                if (func_L00_0071D890(0.6f, context, (s32)label, (s32)func_0045E850(0x3430), 24, 0, 0, 0) == 16) {
                    finished = 1;
                }
            } else {
                finished = 1;
            }
        } while (!finished);
    } else {
        const char *label = func_0045E850(0x3114);
        func_L00_0071D890(0.6f, context, (s32)label, (s32)func_0045E850(0x3115), 4, 0, 0, 0);
    }
    if (result) {
        func_L00_007697C0(0xC3);
    }
}
