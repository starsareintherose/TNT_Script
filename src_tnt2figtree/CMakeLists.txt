cmake_minimum_required(VERSION 3.0)

project(tnt2figtree)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CMAKE_CXX_STANDARD 11)

add_executable(tnt2figtree tnt2figtree.cpp)

target_compile_options(tnt2figtree PRIVATE -Wall -Wextra -pedantic)

install(TARGETS tnt2figtree DESTINATION /usr/bin)
install(FILES ../LICENSE DESTINATION /usr/share/licenses/tnt2figtree)
install(FILES README.md DESTINATION /usr/share/doc/tnt2figtree)
