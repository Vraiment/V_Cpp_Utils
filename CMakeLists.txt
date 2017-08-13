# Basic project configuration
CMAKE_MINIMUM_REQUIRED(VERSION 3.9.0)
PROJECT(VCppUtils VERSION 0.0.1)

# Set the relevant variables for dirs
SET(V_CPP_UTILS_SRC_DIR "${VCppUtils_SOURCE_DIR}/src")
SET(V_CPP_UTILS_TST_DIR "${VCppUtils_SOURCE_DIR}/tst")
SET(V_CPP_UTILS_OUTPUT_DIR ".")
SET(V_CPP_UTILS_OUTPUT_SRC_DIR "${V_CPP_UTILS_OUTPUT_DIR}/src")

# Set C++ config file
CONFIGURE_FILE(
    "${V_CPP_UTILS_SRC_DIR}/VCppConfig.hpp.in"
    "${V_CPP_UTILS_OUTPUT_SRC_DIR}/VCppConfig.hpp"
)

# Add unit tests
ADD_SUBDIRECTORY("tst")
