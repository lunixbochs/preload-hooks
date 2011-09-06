#include <stdlib.h>
#include <errno.h>

int REAL(setenv)(const char *envname, const char *envval, int overwrite);
int REAL(putenv)(char *string);
INIT_START(setenv)
	INIT_FUNC(setenv, LIBC)
	INIT_FUNC(putenv, LIBC)
INIT_END()

int setenv(const char *envname, const char *envval, int overwrite) {
	printf("setenv(%s, %s, %i)\n", envname, envval, overwrite);
	setenv_init();
	if (strncmp(envname, "LD_PRELOAD", 10) == 0) {
		errno = EINVAL;
		return -1;
	}

	return real_setenv(envname, envval, overwrite);
}

int putenv(char *string) {
	printf("putenv(%s)\n", string);
	if (strncmp(string, "LD_PRELOAD=", 11) == 0) {
		errno = ENOMEM;
		return -1;
	}

	return real_putenv(string);
}

