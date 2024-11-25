## Shared Libraries

Shared (Dynamic) Libraries
- .so is the default extension for shared libraries in Linux systems.
- Respectively, the extension being used in Windows is mostly .dll (Dynamic Linking Library).
- The ‘.so’ ending indicates a shared object. A name of a .so library is known as “soname” and almost always it is prefixed by “lib” . Usually, the .so library can be followed by a period and a version number (the “real name”), but then a symlink is being used for just up to the .so ending (the “linker name”).
- For macOS (Darwin) systems the shared libraries ending used to be ‘.dylib’.

## Dynamic Loading of Libraries

1. **dlopen()**
   1. dlopen() returns just a pointer (a handler) of a binary file (like a shared library or an executable). It has 2 parameters: The first one is a string (actually a char*) of the name of the binary (e.g.: the shared library name). The second is a constant int – the mode flag, which generally defines how we can access referenced symbols. Just to mention 2 of them: RTL_LAZY, and RTL_NOW. RTL_LAZY generally instructs the dlopen() to resolve symbols only if the code references them, and upon code execution. If a symbol is never referenced, then it is never resolved. Note that RTL_LAZY is OK for function references, but for references to variables, better to use the RTL_NOW to resolve them immediately, upon library loading.

2. **dlsym()**
   1. It gets/returns the address of a symbol (inside the loaded object/binary/library open via dlopen). It has 2 parameters: The first, is the pointer (a handler) of the shared object loaded. The second is a string (actually a char*) of the name of the symbol.
   2. The pointer returned from the dlsym is a void pointer. When the symbol concerns a function, and we want to get access to this function, we have to convert the void pointer to the appropriate pointer type of that function.

3. **dlerror()**
   1. It returns a human readable string describing the most recent error that occurred from dlopen(), dlsym() or dlclose() since the last call to dlerror().

4. **dlclose()**
   1. Unloads the binary object/library (loaded via dlopen) and frees the memory