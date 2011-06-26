#include <sys/stat.h>

#define STAT_ARGS(type) int ver, const char *path, struct type *buf
#define FSTAT_ARGS(type) int ver, int filedes, struct type *buf

REAL_DEF(__xstat)(STAT_ARGS(stat));
REAL_DEF(__xstat64)(STAT_ARGS(stat64));
REAL_DEF(__fxstat)(FSTAT_ARGS(stat));
REAL_DEF(__fxstat64)(FSTAT_ARGS(stat64));
REAL_DEF(__lxstat)(STAT_ARGS(stat));
REAL_DEF(__lxstat64)(STAT_ARGS(stat64));

REAL_DEF(lstat)(const char *path, struct stat *buf);

INIT_START(stat)
	INIT_FUNC(__xstat, LIBC);
	INIT_FUNC(__xstat64, LIBC);
	INIT_FUNC(__fxstat, LIBC);
	INIT_FUNC(__fxstat64, LIBC);
	INIT_FUNC(__lxstat, LIBC);
	INIT_FUNC(__lxstat64, LIBC);
INIT_END()

int __xstat(STAT_ARGS(stat)) {
	printf("__xstat(%i, \"%s\", ?)\n", ver, path);
	stat_init();
	return real___xstat(ver, path, buf);
}

int __xstat64(STAT_ARGS(stat64)) {
	printf("__xstat64(%i, \"%s\", ?)\n", ver, path);
	stat_init();
	return real___xstat64(ver, path, buf);
}

int __fxstat(FSTAT_ARGS(stat)) {
	printf("__fxstat(%i, %i, ?)\n", ver, filedes);
	stat_init();
	return real___fxstat(ver, filedes, buf);
}

int __fxstat64(FSTAT_ARGS(stat64)) {
	printf("__fxstat64(%i, %i, ?)\n", ver, filedes);
	stat_init();
	return real___fxstat64(ver, filedes, buf);
}

int __lxstat(int ver, const char *path, struct stat *buf) {
	printf("__lxstat(%i, \"%s\", ?)\n", ver, path);
	stat_init();
	
	return real___lxstat(ver, path, buf);
}

int __lxstat64(STAT_ARGS(stat64)) {
	printf("__lxstat64(%i, \"%s\", ?)\n", ver, path);
	stat_init();
	return real___lxstat64(ver, path, buf);
}
