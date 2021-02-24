# Notes on sanitizer use Thread sanitizer is incompatible with address or leak or undefined
# behaviour sanitizers Memory sanitizer is incompatible with address or leak or thread sanitizers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  set(SANITIZERS "")

  # TODO(nn): Make this a enum, since these options are mutually exclusive
  option(SANITIZER_BUNDLE "   Enable sanitizer compilation option for address, leak and undefined behavior" OFF)
  option(SANITIZER_BUNDLE2 "   Enable sanitizer compilation option for thread" OFF)
  option(SANITIZER_BUNDLE3 "   Enable sanitizer compilation option for memory" OFF)
  
  if(SANITIZER_BUNDLE)
    message("Enabling sanitizers for address, leak and undefined behavior")
    list(
      APPEND
      SANITIZERS
      "address"
      "leak"
      "undefined"
    )
  endif()
  if(SANITIZER_BUNDLE2)
    message("Enabling thread sanitizers")
    list(APPEND SANITIZERS "thread")
  endif()

  if(SANITIZER_BUNDLE3 AND CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    message("Enabling memory sanitizers")
    list(APPEND SANITIZERS "memory")
  endif()

endif()

target_compile_options(${PROJECT_NAME} INTERFACE -fsanitize=${SANITIZERS})
target_link_options(${PROJECT_NAME} INTERFACE -fsanitize=${SANITIZERS})
