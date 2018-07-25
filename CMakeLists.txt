cmake_minimum_required (VERSION 2.6)
project (gp)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -std=c++11 -pg")
if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE RelWithDebInfo) 
endif()

include(FindPkgConfig)
include(GNUInstallDirs)

############################# LOAD EIGEN #############################
if(PKG_CONFIG_FOUND)
    pkg_check_modules(EIGEN eigen3)
    if(NOT EIGEN_FOUND)
       message(FATAL_ERROR "EIGEN could not be found")
    endif()
    include_directories(${EIGEN_INCLUDE_DIRS})    
endif()

############################# LOAD OPPT #############################
if(PKG_CONFIG_FOUND)
    pkg_check_modules(OPPT oppt)
    if(NOT OPPT_FOUND)
       message(FATAL_ERROR "OPPT could not be found")
    endif()
    include_directories(${OPPT_INCLUDE_DIRS})
    link_directories(${OPPT_LIBRARY_DIRS})    
endif()

############################# LOAD GAZEBO #############################
include(${CMAKE_CURRENT_LIST_DIR}/FindGazebo.cmake)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

############################# LOAD BOOST #############################
find_package(Boost ${BOOST_MIN_VERSION} 
             REQUIRED 
             system 
             thread 
             timer 
             filesystem 
             serialization 
             program_options             
             unit_test_framework)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})    
endif ()

add_executable(gp
               ${CMAKE_CURRENT_LIST_DIR}/main.cpp
               ${CMAKE_CURRENT_LIST_DIR}/GP.cpp)
               
target_link_libraries (gp                   
                       ${OPPT_LIBRARIES}
                       ${EIGEN_LIBRARIES}
                       ${Boost_LIBRARIES})
