/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"
#include "pal/l00_hash_table.h"

typedef struct {
    u8 f0[0xC];
    void (*initialize)(void *);
    u8 f10[0x28];
    s32 size;
    void (*prepare)(void *, void *);
    void *context;
} BufferConfig;

typedef struct {
    BufferConfig *config;
    u8 f4[4];
    s32 size;
    void *buffer;
} BufferState;

extern void *func_0011A518(void *, s32, s32);
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);

/* Configure the state buffer and run its initialization callbacks. */
s32 func_L00_00519990(BufferState *state, BufferConfig *config) {
    if (config == NULL) {
        config = state->config;
    } else {
        state->config = config;
    }

    if (config == NULL) {
        func_L00_004F89C8(6, 0x71, 0x75, NULL, 0);
        return 0;
    }

    if (state->buffer == NULL || state->size < config->size) {
        if (state->buffer != NULL) {
            func_L00_004FB228(state->buffer);
        }
        state->buffer = func_L00_004FB1D8(config->size);
        if (state->buffer == NULL) {
            func_L00_004F89C8(6, 0x71, 0x21, NULL, 0);
            return 0;
        }
        func_0011A518(state->buffer, 0, config->size);
    }
    state->size = config->size;

    if (config->prepare != NULL) {
        config->prepare(state->buffer, config->context);
    }
    config->initialize(state->buffer);
    return 1;
}
