project(unit_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${PROJECT_NAME} 
        test_module1.cpp
        test_module2.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC	
        module1_lib
        module2_lib)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main)
