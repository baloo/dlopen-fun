#include <dlfcn.h>
#include <stddef.h>

int main(void) {
	void * lib = dlopen("./hello.la", RTLD_NOW);

	if (lib != NULL) dlclose(lib);
}
