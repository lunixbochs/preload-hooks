#include <sys/types.h>

int REAL(__xmknod)(const char *pathname, mod_t mode, dev_t dev);
INIT_START(mknod)
	INIT_FUNC(__xmknod, LIBC)
INIT_END()

int __xmknod(const char *pathname, mod_t mode, dev_t dev) {
	mknod_init();
	return real___xmknod(ver, pathname, mode, dev);
}

