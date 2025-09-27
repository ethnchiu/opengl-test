# OpenGL Test
A basic C++ and OpenGL project template using CMake and Conan for dependency management.

## Prerequisites
- A C++ Compiler: (e.g., GCC, Clang, or MSVC)
- CMake: Version 3.15 or newer
- Python & Pip: To install Conan
- Conan: Version 2.0 or newer

## Building and Running
Follow these steps to configure, compile, and run the project. All commands should be run from the project's root directory.

1. Install Conan Dependencies
This command reads conanfile.txt, downloads the necessary libraries (like GLFW), and prepares them for CMake.

```console
conan install . --output-folder=build --build=missing
```

2. Configure the Project with CMake
This generates the build files in the build directory and points CMake to the Conan-managed dependencies.

```console
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
```

3. Compile the Code
This uses the generated build files to compile your source code into an executable.

```console
cmake --build build
```

4. Run the Executable
The final application will be inside the build directory.

```console
./build/opengl_test
```

## Managing Dependencies
To add, update, or remove a library, edit the conanfile.txt file and then rebuild the project.

### Adding a New Library
1. Find the package you want to add using conan search or through the [ConanCenter](https://gemini.google.com/app/ab76682b4f14fc93#:~:text=to%20add%20from-,ConanCenter,-.%20For%20example%2C%20let%27s).

```console
conan search package_name
```

2. Edit the conanfile.txt and add the new library under the [requires] section.

```txt
[requires]
glfw/3.4
new_package/version

[generators]
CMakeDeps
CMakeToolchain
```

3. Re-run the install and configure steps to download the new library and update the CMake project.

```console
# Step 1: Install the new Conan package
conan install . --output-folder=build --build=missing

# Step 2: Re-run CMake to find the new package
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
```

4. Update CMakeLists.txt to use the new library.

```txt
# Find the new package
find_package(new_package REQUIRED)

# ...

# Link the new library to your executable
target_link_libraries(my_app PRIVATE glfw new_package)
```

5. Re-compile the project.

```console
cmake --build build
```
