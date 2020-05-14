## macro that handles creation of unit test executable
macro (create_test target)
    ## To allow absolute header paths in includes
    include_directories(${PROJECT_SOURCE_DIR}/src)

    ## To create a target that can run via ctest
    add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro (create_test)

## macro that prepends the a string to the beginning of another string
macro( prepend_path _srcs _path )
    unset( _tmp )
    foreach( src ${_srcs} )
        list( append _tmp ${_path}/${src} )
    endforeach( src ${_srcs} )
    set( _srcs ${_tmp} )
endmacro( prepend_path _srcs )