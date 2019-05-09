cmake_minimum_required(VERSION 3.14)
project(pybind11_example)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs "${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}" REQUIRED )
if (PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
    message("-- Using python: " ${PYTHONLIBS_VERSION_STRING})
endif()

add_subdirectory(external/pybind11)

pybind11_add_module(example_module example_module.cpp)


enable_testing()

add_test(
    NAME
        example_module_test
    COMMAND
        ${PYTHON_EXECUTABLE} -m pytest ${CMAKE_SOURCE_DIR}/test
    WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}

)
