#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int REAL(execve)(const char *filename, char *const argv[], char *const envp[]);
int REAL(execv)(const char *filename, char *const argv[]);

INIT_START(exec)
	INIT_FUNC(execve, LIBC)
INIT_END()

int execve(const char *filename, char *const argv[], char *const envp[]) {
	fprintf(stderr, "execve(%s)\n", filename);
	exec_init();

	clearenv();
	int i;
	for (i=0; envp[i]; i++) {
		if (strstr(envp[i], "LD_PRELOAD="LIBPATH)) {
			real_execve(filename, argv, envp);
		} else {
			putenv(envp[i]);
		}
	}
	putenv("LD_PRELOAD="LIBPATH);

	return execv(filename, argv);
}

int execv(const char *filename, char *const argv[]) {
	unsetenv("LD_PRELOAD");
	putenv("LD_PRELOAD="LIBPATH);
	return real_execv(filename, argv);
}
