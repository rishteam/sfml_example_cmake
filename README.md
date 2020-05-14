//! @mainpage Main Page
# SFML Example CMake

[![Build Status](https://travis-ci.org/rishteam/sfml_example_cmake.svg?branch=master)](https://travis-ci.org/rishteam/sfml_example_cmake)

* Environment
  * msys2 mingw32 with CMake

> Notice: Need to build SFML for static linking by yourself
> because the package manager doesn't provide the version of static linking.

```
pacman -S mingw32/mingw-w64-i686-cppcheck mingw32/mingw-w64-i686-doxygen mingw32/mingw-w64-i686-graphviz mingw32/mingw-w64-i686-cmake
```

## Docs

https://rish.com.tw/sfml_example_cmake

## Build

```bash
mkdir build && cd build
cmake -G "MSYS Makefiles" ..
make
```

* screenshot

![](https://i.imgur.com/bqQsp53.png)
