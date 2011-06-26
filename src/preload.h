#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>

#if defined(RTLD_NEXT)
#define LIBC RTLD_NEXT
#else
#define LIBC ((void*) -1L)
#endif

#define REAL_DEF(func) static int (*real_##func)
#define INIT_START(prefix)\
	static int prefix##_start = 0;\
	static void prefix##_init() {\
		if (!prefix##_start) {

#define INIT_FUNC(func, lib) assert(real_##func = dlsym(lib, #func));
#define INIT_END() }}

#define VA_PASS(name, arg) va_list name; va_start(name, arg)
