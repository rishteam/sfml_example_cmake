cmake_minimum_required(VERSION 3.10)

project(SFMLTest CXX)

include(cmake/StandardProjectSettings.cmake)
# Project option
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if (ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
option(ENABLE_DOXYGEN "Enable doxygen doc builds of source" ON)
if(ENABLE_DOXYGEN)
    add_subdirectory(docs)
endif()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

# Add executable
add_executable(SFMLTest
    src/main.cpp
)
target_include_directories(SFMLTest PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(SFMLTest project_options project_warnings)

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

## Copy files
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
# Copy dlls to build
if(MSYS)
    file(GLOB BINARY_DEP_DLLS "${CMAKE_SOURCE_DIR}/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()