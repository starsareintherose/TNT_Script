cmake_minimum_required(VERSION 3.0)

project(tnt2winclada)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CMAKE_CXX_STANDARD 11)

add_executable(tnt2winclada tnt2winclada.cpp)

target_compile_options(tnt2winclada PRIVATE -Wall -Wextra -pedantic)

install(TARGETS tnt2winclada DESTINATION /usr/bin)
install(FILES ../LICENSE DESTINATION /usr/share/licenses/tnt2winclada)
install(FILES README.md DESTINATION /usr/share/doc/tnt2winclada)
