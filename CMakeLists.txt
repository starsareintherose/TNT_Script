cmake_minimum_required(VERSION 3.0)

project(tnt_script)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src_tnt2winclada)
add_subdirectory(src_tnt2figtree)

install(FILES guoyi.run DESTINATION /usr/share/tnt/tnt_scripts)
install(FILES LICENSE DESTINATION /usr/share/licenses/tnt-guoyi-script)
install(FILES README.md DESTINATION /usr/share/doc/tnt-guoyi-script)
