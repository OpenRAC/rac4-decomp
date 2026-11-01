#ifndef PAL_L00_RECORD_ITERATION_H
#define PAL_L00_RECORD_ITERATION_H

typedef struct PalL00Records PalL00Records;
typedef void (*PalL00RecordCallback)(void *value, void *context);

void func_L00_004F9140(PalL00Records *records, PalL00RecordCallback callback, void *context);

#endif
