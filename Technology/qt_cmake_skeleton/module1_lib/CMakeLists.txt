project(module1_lib)

set(HEADER_FILES
        module1.h)
set(SOURCE_FILES
        module1.cpp)

add_library(module1_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
