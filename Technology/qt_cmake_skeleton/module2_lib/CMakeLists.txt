project(module2_lib)

set(HEADER_FILES
        module2.h)
set(SOURCE_FILES
        module2.cpp)

add_library(module2_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
