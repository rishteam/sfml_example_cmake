# SFML Example CMake

* Environment
  * msys2 mingw32 with CMake

> Notice: Need to build SFML for static linking by yourself
> because the package manager doesn't provide the version of static linking.

```
pacman -S cppcheck doxygen graphviz
```

## Build

```bash
mkdir build && cd build
cmake -G "MSYS Makefiles" ..
make
```

* screenshot

![](https://i.imgur.com/bqQsp53.png)
