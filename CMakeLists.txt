cmake_minimum_required(VERSION 3.10)

project(SFMLTest)

set(CMAKE_CXX_STANDARD 14)

# Add executable
add_executable(SFMLTest
src/main.cpp
)
target_include_directories(SFMLTest
PRIVATE ${PROJECT_SOURCE_DIR}/include
)

if(APPLE)
    set(SFML_STATIC_LIBRARIES False)
    set(SFML_DIR "/usr/local/Cellar/sfml/2.5.1")
    target_compile_definitions(SFMLTest PUBLIC "GL_SILENCE_DEPRECATION")
elseif(MSYS)
    set(SFML_STATIC_LIBRARIES True)
    set(SFML_DIR "/mingw32/lib/cmake/SFML")
else()
    message(FATAL_ERROR "Not supported")
endif()

# Add SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(SFMLTest
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)

# Add ImGui-SFML
find_package(ImGui-SFML REQUIRED)
if(NOT ImGui-SFML_FOUND)
    message(FATAL_ERROR "ImGui-SFML not found")
endif()
target_link_libraries(SFMLTest
    ImGui-SFML::ImGui-SFML
)

find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()
target_include_directories(SFMLTest
    PUBLIC ${OPENGL_INCLUDE_DIRS}
)
target_link_libraries(SFMLTest
    ${OPENGL_LIBRARIES}
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
