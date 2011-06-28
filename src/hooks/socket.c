int REAL(socket)(int domain, int type, int protocol);
INIT_START(socket)
	INIT_FUNC(socket, LIBC)
INIT_END()

int socket(int domain, int type, int protocol) {
	socket_init();
	return real_socket(domain, type, protocol);
}

