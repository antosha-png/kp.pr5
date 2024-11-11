#include <stdio.h>
#include <string.h>

#ifdef _Linux
#include <dlfcn.h>
#define LIB_HANDLE void*
#define LOAD_LIBRARY(name) dlopen(name, RTLD_LAZY)
#define LOAD_FUNCTION(lib, func) dlsym(lib, func)
#define CLOSE_LIBRARY(lib) dlclose(lib)
#else
#include <windows.h>
#define LIB_HANDLE HMODULE
#define LOAD_LIBRARY(name) LoadLibrary(name)
#define LOAD_FUNCTION(lib, func) GetProcAddress(lib, func)
#define CLOSE_LIBRARY(lib) FreeLibrary(lib)
#endif

#define SIZE 11
#define CNT 4

void LoadRun(const char* const s);



