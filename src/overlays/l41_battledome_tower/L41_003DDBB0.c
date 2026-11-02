#include "common.h"

extern void *func_L01_006B4FC0(void *, void *, void *, s32);
extern void func_00611808(void *, void *, s32);

// Fetch a 0xFA-typed handle for the object and push a 4-byte value into it.
void func_L41_003DDBB0(void *object, s32 value) {
	void *handle = func_L01_006B4FC0(object, 0, 0, 250);

	if (handle != 0) {
		s32 local = value;
		func_00611808(handle, &local, 4);
	}
}
