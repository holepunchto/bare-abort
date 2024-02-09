cmake_minimum_required(VERSION 3.25)

project(bare_abort C)

include(bare)

add_bare_module(bare_abort)

target_sources(
  ${bare_abort}
  PRIVATE
    binding.c
)
