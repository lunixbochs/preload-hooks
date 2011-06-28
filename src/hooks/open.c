int REAL(open)(const char* path, int flags, ...);
INIT_START(open)
	INIT_FUNC(open, LIBC)
INIT_END()

static int mopen(const char* path, int flags, mode_t mode) {
	open_init();
	return real_open(path, flags, mode);
}

static int vopen(const char* path, int flags, va_list arg) {
	mode_t mode = 0;
	if (flags & O_CREAT) {
		mode = va_arg(arg, mode_t);
		va_end(arg);
	}

	return mopen(path, flags, mode);
}

int open(const char* path, int flags, ...) {
	VA_PASS(arg, flags);
	return vopen(path, flags, arg);
}

int open64(const char* path, int flags, ...) {
	VA_PASS(arg, flags);
	return vopen(path, flags | O_LARGEFILE, arg);
}

