# Set minimum CMake version [1]
cmake_minimum_required(VERSION 3.9)

# Define the project and package name [1]
set(PACKAGE "V1720")
project(${PACKAGE} CXX)

# Find the ROOT package [1, 2]
find_package(ROOT REQUIRED)

# set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
# set(CMAKE_BUILD_RPATH "${CMAKE_BINARY_DIR}")
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# Include ROOT macros if using an older version (typically 6.16 or earlier) [3]
# find_package(ROOT) generally includes these automatically in modern versions.
# include("${ROOT_DIR}/modules/RootNewMacros.cmake")

# Specify headers and source files [4, 5]
set(HEADERS "V1720FileSetup.h")
set(SOURCES "V1720FileSetup.cxx")

# 1. Create the shared library target [1, 5, 6]
add_library(${PACKAGE} SHARED ${SOURCES} ${HEADERS})

# 2. Generate the ROOT dictionary [7, 8]
# The MODULE option attaches the dictionary to our existing library target [8, 9]
# The LinkDef file naming follows your requirement [10]
ROOT_GENERATE_DICTIONARY(
    ${PACKAGE}Dict
    ${HEADERS} 
    MODULE ${PACKAGE} 
    LINKDEF ${PACKAGE}_LinkDef.h
)

# 3. Configure includes and link against ROOT libraries [1, 9, 11]
# target_include_directories ensures rootcling finds headers during the build [1]
target_include_directories(${PACKAGE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PACKAGE} PUBLIC ROOT::Core ROOT::RIO)

# 4. Install artifacts [12, 13]
# You must install the .so, .rootmap, and .pcm files together for ROOT to load them [14, 15]
install(TARGETS ${PACKAGE} DESTINATION lib/)

# For ROOT 6, PCM and rootmap files must stay in the same directory as the library [12, 15]
if (${ROOT_VERSION} VERSION_GREATER_EQUAL 6.0)
    install(FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/lib${PACKAGE}_rdict.pcm"
        "${CMAKE_CURRENT_BINARY_DIR}/lib${PACKAGE}.rootmap"
        DESTINATION lib/
    )
endif()