cmake_minimum_required(VERSION 3.25)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)

project(bare_abort C)

add_bare_module(bare_abort)

target_sources(
  ${bare_abort}
  PRIVATE
    binding.c
)
