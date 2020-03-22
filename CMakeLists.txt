cmake_minimum_required(VERSION 3.10)

project(SFMLTest)

set(CMAKE_CXX_STANDARD 14)

if(APPLE)
    set(SFML_STATIC_LIBRARIES False)
    set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1")
elseif(MSYS)
    set(SFML_STATIC_LIBRARIES True)
    set(SFML_DIR "/mingw32/lib/cmake/SFML")
else()
    message(WARNING "Not supported")
endif()

# Add executable
add_executable(SFMLTest
    src/main.cpp
)
target_include_directories(SFMLTest
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(SFMLTest
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)

if(MSYS)
    target_link_libraries(SFMLTest
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        # -mconsole / -mwindows
    )
endif()

# Copy files
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
# file(GLOB BINARY_DEP_DLLS
#     "${CMAKE_SOURCE_DIR}/bin/*.dll"
# )
# file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
