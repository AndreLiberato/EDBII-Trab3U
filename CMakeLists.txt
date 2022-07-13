cmake_minimum_required(VERSION 3.5)
project(Avl_TrabEDII VERSION 0.1 LANGUAGES CXX)

# set the compiling flags

add_compile_options(
  -g
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -ansi
  -Ofast
  -fsanitize=address,undefined
  -lm
)

add_link_options(-fsanitize=address,undefined)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 17)
#--------------------------------

### [1] Application target
## configura o diretório contendo os .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

## Cria um executável com nome "calc".
add_executable(avltree)

target_sources(
  avltree
  PRIVATE
    src/main.cpp
    src/AvlTree.cpp
    src/Util.cpp
)

# The end
