if(COMPILE_FOR_NON_UNIX)
    message("Compile for non unix")
else()
    message("Compile for unix")
endif()
configure_file(platformconfig.h.in platformconfig.h @ONLY)

# Clears COMPILE_FOR_NON_UNIX between cmake runs
unset(COMPILE_FOR_NON_UNIX CACHE)
