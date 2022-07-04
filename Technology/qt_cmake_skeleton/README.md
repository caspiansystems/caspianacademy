# C++ Project Skeleton: Qt Creator + CMake + GooglTest
This repo directory presents a C++ project skeleton in Qt Creator where project dependencies are managed by CMake. Google test is used for unit testing framework and it is added to the project as a submodule (simply another subdirectory) such that it is compiled as a static library together with the project. The folder structure provided in this example will look like this:
```
.
└── qt_cmake_skeleton/
    ├── module1_lib/
    │   ├── CMakeLists.txt
    │   ├── module1.cpp
    │   └── module1.h
    ├── module2_lib/
    │   ├── CMakeLists.txt
    │   ├── module2.cpp
    │   └── module2.h
    ├── unit_tests/
    │   ├── googletest
    │   ├── CMakeLists.txt
    │   ├── test_module1.cpp
    │   └── test_module2.cpp
    ├── CMakeLists.txt
    ├── main.cpp
    ├── mainwindow.cpp
    ├── mainwindow.h
    └── mainwindow.ui
```
Please note that if the core business logic are implemented inside the modules, then they can be made independent of the Qt GUI application. One can even write the code in "standard" C++ without using Qt C++ functionalities inside those modules. That would make the back-end code independent of the development environment (Qt creator in this case). Moreover, using CMake project structure and GoogleTest, makes it possible to  develop and test the modules in the favorite development environment in different platforms such as Windows, Linux and macOS. 

https://www.caspiansystems.dk/