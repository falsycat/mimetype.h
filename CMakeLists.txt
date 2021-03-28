cmake_minimum_required(VERSION 3.18)

project(mimetype.h C)
include(CTest)

add_library(mimetype.h)
target_compile_options(mimetype.h
  PRIVATE
    -Wall -Wextra -Werror -Wno-missing-field-initializers
)
target_include_directories(mimetype.h SYSTEM
  PUBLIC .
)
target_sources(mimetype.h
  PRIVATE mimetype.c
  PUBLIC  mimetype.h
)

if(BUILD_TESTING)
  add_executable(mimetype-test)
  target_sources(mimetype-test
    PRIVATE test.c
  )
  target_link_libraries(mimetype-test
    PRIVATE mimetype.h
  )
  add_test(
    NAME    mimetype-test
    COMMAND $<TARGET_FILE:mimetype-test>
  )
endif()
