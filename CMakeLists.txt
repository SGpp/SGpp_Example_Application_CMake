cmake_minimum_required(VERSION 3.0.2)

#================================================================================================================================================
# Setup and build SGpp as a dependency of the actual application project
#================================================================================================================================================

# For building SGpp in parallel
include(ProcessorCount)
ProcessorCount(N)
if (N EQUAL 0)
	set(N 1)
	MESSAGE(WARNING "Could not determine number of CPU cores! SGpp will be build with -j 1")
endif()

# Check whether SGpp module is initialised and issue error if not
find_path(SGPP_DIR NAMES "SConstruct" PATHS "${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp")
if ((NOT SGPP_DIR) OR (NOT EXISTS ${SGPP_DIR}))
	MESSAGE(FATAL_ERROR "Could not find the SConstruct file within the SGpp directory!\n"
		            "To fix this error, clone to SGpp submodule by running the following command within the project root directory:\n"
			    "git submodule update --init external_dependencies/SGpp")
endif()

# Build SGpp (only happens during configure time to save time during the project compilation) 
# We only build the base module for this example. The other modules can be activated by modifying the scons command below:
execute_process(COMMAND "scons" "SG_BASE=1" "SG_DATADRIVEN=1" "SG_COMBIGRID=1" "SG_OPTIMIZATION=1" # Flags for which SGpp modules to build
			"SG_QUADRATURE=1" "SG_SOLVER=1" "SG_PDE=1" "SG_MISC=1"                     # Flags for which SGpp modules to build
			"SG_JAVA=0" "SG_PYTHON=0" "SG_MATLAB=0"                                    # Which language wrappers should be created
			"RUN_BOOST_TESTS=0" "RUN_PYTHON_TESTS=0"                                   # Do not run any unit tests
			"OPT=1"                                                                    # Create optimized build
			"PRINT_INSTRUCTIONS=0" "VERBOSE=0" "-j${N}"                                # Convienience flags for silent and fast build
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp")

# Set SGpp headers directories (one per SGpp module).
set(SGPP_BASE_INCLUDE_DIR external_dependencies/SGpp/base/src)
set(SGPP_DATADRIVEN_INCLUDE_DIR external_dependencies/SGpp/datadriven/src)
set(SGPP_COMBIGRID_INCLUDE_DIR external_dependencies/SGpp/combigrid/src)
set(SGPP_OPTIMIZATION_INCLUDE_DIR external_dependencies/SGpp/optimization/src)
set(SGPP_QUADRATURE_INCLUDE_DIR external_dependencies/SGpp/quadrature/src)
set(SGPP_SOLVER_INCLUDE_DIR external_dependencies/SGpp/solver/src)
set(SGPP_PDE_INCLUDE_DIR external_dependencies/SGpp/pde/src)
set(SGPP_MISC_INCLUDE_DIR external_dependencies/SGpp/misc/src)

# Include SGpp directories. List may be shortened depending on what SGpp modules you want to use
include_directories(${SGPP_BASE_INCLUDE_DIR})
include_directories(${SGPP_DATADRIVEN_INCLUDE_DIR})
include_directories(${SGPP_COMBIGRID_INCLUDE_DIR})
include_directories(${SGPP_OPTIMIZATION_INCLUDE_DIR})
include_directories(${SGPP_QUADRATURE_INCLUDE_DIR})
include_directories(${SGPP_SOLVER_INCLUDE_DIR})
include_directories(${SGPP_PDE_INCLUDE_DIR})
include_directories(${SGPP_MISC_INCLUDE_DIR})

# Link libraries
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppbase.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppdatadriven.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppcombigrid.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppoptimization.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppquadrature.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppsolver.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgpppde.so)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/SGpp/lib/sgpp/libsgppmisc.so)

#================================================================================================================================================
# Setup application
#================================================================================================================================================

# Application name
project(SGpp_Example_Application)

# Headers of the current application
include_directories(include)

# Sources of the current application
set(SOURCES src/main_quadrature.cpp src/example_function.cpp)

add_executable(quadrature ${SOURCES})
