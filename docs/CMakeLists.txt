cmake_minimum_required(VERSION 3.10)
project(docs)

set(DOXYGEN_PROJECT_NAME "SFML CMake Example")
set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/)
set(DOXYGEN_CALLER_GRAPH NO)
set(DOXYGEN_CALL_GRAPH NO)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXTRACT_STATIC YES)
set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_INLINE_SOURCES NO)

find_package(Doxygen REQUIRED dot)
doxygen_add_docs(doxygen-docs ${PROJECT_SOURCE_DIR}/../)