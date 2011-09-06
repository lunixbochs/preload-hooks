#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

static struct dirent *(*real_readdir)(DIR *dir);
INIT_START(proc)
	INIT_FUNC(readdir, LIBC)
INIT_END()

struct dirent *readdir(DIR *dir) {
	proc_init();
	struct dirent *result = real_readdir(dir);

	if (result != NULL) {
		int cwd = open(".", O_RDONLY);
		int fd = dirfd(dir);
		fchdir(fd);

		struct stat st;
		if (stat(result->d_name, &st) == 0) {
			while (getuid() != st.st_uid && getgid() != st.st_gid) {
				result = real_readdir(dir);

				if (result == NULL) break;
				if (stat(result->d_name, &st) == -1) break;
			}
		}
		fchdir(cwd);
		close(cwd);
	}
	return result;
}

