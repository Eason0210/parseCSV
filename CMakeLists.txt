cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

set(BOOST_ROOT "/opt/local/include/boost")

find_package(Boost 1.76.0 COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(main main.cpp)
    target_link_libraries(main ${Boost_LIBRARIES})
endif(Boost_FOUND)
