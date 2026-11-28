#ifndef PAL_OBJECT_CALLBACK_H
#define PAL_OBJECT_CALLBACK_H

typedef struct PalObjectCallbackNode PalObjectCallbackNode;
typedef void (*PalObjectCallback)(void *object);

void func_00449A28(PalObjectCallbackNode **head, PalObjectCallback callback, void *object);

#endif
