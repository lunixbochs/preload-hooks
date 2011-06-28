#include <sys/stat.h>

#define STAT_ARGS(type) int ver, const char *path, struct type *buf
#define FSTAT_ARGS(type) int ver, int filedes, struct type *buf

int REAL(__xstat)(STAT_ARGS(stat));
int REAL(__xstat64)(STAT_ARGS(stat64));
int REAL(__fxstat)(FSTAT_ARGS(stat));
int REAL(__fxstat64)(FSTAT_ARGS(stat64));
int REAL(__lxstat)(STAT_ARGS(stat));
int REAL(__lxstat64)(STAT_ARGS(stat64));

INIT_START(stat)
	INIT_FUNC(__xstat, LIBC);
	INIT_FUNC(__xstat64, LIBC);
	INIT_FUNC(__fxstat, LIBC);
	INIT_FUNC(__fxstat64, LIBC);
	INIT_FUNC(__lxstat, LIBC);
	INIT_FUNC(__lxstat64, LIBC);
INIT_END()

int __xstat(STAT_ARGS(stat)) {
	stat_init();
	return real___xstat(ver, path, buf);
}

int __xstat64(STAT_ARGS(stat64)) {
	stat_init();
	return real___xstat64(ver, path, buf);
}

int __fxstat(FSTAT_ARGS(stat)) {
	stat_init();
	return real___fxstat(ver, filedes, buf);
}

int __fxstat64(FSTAT_ARGS(stat64)) {
	stat_init();
	return real___fxstat64(ver, filedes, buf);
}

int __lxstat(int ver, const char *path, struct stat *buf) {
	stat_init();
	return real___lxstat(ver, path, buf);
}

int __lxstat64(STAT_ARGS(stat64)) {
	stat_init();
	return real___lxstat64(ver, path, buf);
}
