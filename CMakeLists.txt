cmake_minimum_required(VERSION 3.16)
project(Code_Problems C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Cada .c/.cpp vira um executável próprio (fora do "all"), só para o CLion
# reconhecer os headers e a configuração de compilação de cada arquivo.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.c" "${CMAKE_SOURCE_DIR}/*.cpp")
foreach(src ${SOURCES})
    if(src MATCHES "/(\\.idea|cmake-build-[^/]*|\\.git)/")
        continue()
    endif()
    file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}" "${src}")
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" target "${rel}")
    add_executable(${target} EXCLUDE_FROM_ALL "${src}")
    target_compile_definitions(${target} PRIVATE LOCAL)
    target_include_directories(${target} PRIVATE "${CMAKE_SOURCE_DIR}/include")
endforeach()
