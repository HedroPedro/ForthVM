#include "main.h"

int main(int argc, const char *argv[]) {
	argc--;
	vm_init();
	if (argc == 0) {
		repl();
		exit(EXIT_SUCCESS);
	}
}
