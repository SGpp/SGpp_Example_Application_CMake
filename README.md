# SGpp_Example_Application_CMake

[![Build Status](https://travis-ci.org/SGpp/SGpp_Example_Application_CMake.svg?branch=master)](https://travis-ci.org/SGpp/SGpp_Example_Application_CMake)

## Purpose of this repository

This repository is meant to serve as a starting point for people who want to use [SG++](https://github.com/SGpp/SGpp) in a project of their own. 
It demonstrates how to use git submodules to include SG++ as an external dependency and how to use cmake
to both build SG++ and the project itself.

Feel free to use the code in this repository as you see fit!

There is also [another variant](https://github.com/SGpp/SGpp_Example_Application_SCons) of this example application which is using SCons instead of CMake.

## How to build

To build this application, you need to fullfill all [required dependencies](https://github.com/SGpp/SGpp/wiki/Linux-(GCC-Clang-ICC)#dependencies) of SG++. 

### 1. Clone repository
`git clone https://github.com/SGpp/SGpp_Example_Application_CMake.git my_example`

`cd my_example`
### 2. Checkout SGpp submodule
`git submodule update --init external_dependencies/SGpp`

The submodule is not checked out during a normal git clone. Thus, we do it this way.

### 3. Move to build directory
`mkdir -p build`

`cd build`

We will use a subfolder within the project root as a build directory. Of course this can be changed to another directory.

### 4. Run cmake
`cmake ..`

This command will both configure the project as well as build SG++. As this compiles SG++ from scratch, this will take time! The unit tests, however, are switched off to save time. In this example, we build all modules of SG++ in order to demonstrate how to include the headers and link the libraries of all SG++ modules with your own application. Thus, you can reduce the compile time further by deactivating modules (see section below) that you do not need for your own project.

Note that with this setup SG++ will only be built when the cmake command is called.
Thus, if the SG++ submodule itself is set to another commit, the cmake command needs to be run again.

### 5. Run make
`make`

This command will build the actual example application. It will not build SG++ again in order to save compilation time.
After this is done, you can call the application within the build directory with
`./quadrature`

## How to modify the SG++ build
The SG++ version used can simply be changed by going to the (checked out) submodule folder external_dependencies/SGpp and changing the commit there as one would in a normal git repository. Afterwards, the cmake command needs to be run again as described above.

Most likely you want to change the configuration used by SG++, for example by deactivating modules you do not need or by activating a wrapper for another language like Python.
To deactivate one of the modules, edit the scons command, which is being called in the CMakelists.txt file, to deactivate the module. For example, you need to change SG_DATADRIVEN=0 and remove the line linking to the library libsgppdatadriven.so to deactivate the SG++ datadriven module.

To see all ways to configure scons for SG++, go to the (checked out) submodule directory and run
`scons -h`

or visit the respective [SG++ Wiki page](https://github.com/SGpp/SGpp/wiki/Linux-(GCC-Clang-ICC)#compilation-with-scons) for more information.


## About the utilized example
The application itself shows how to integrate functions in SG++, using both direct integration of a sparse grid function and the use of Monte Carlo integration.
It is heavily based on the SG++ example [quadrature.cpp](https://github.com/SGpp/SGpp/blob/master/base/examples/quadrature.cpp) (see also the [full example doc]( http://sgpp.sparsegrids.org/example_quadrature_cpp.html) from the [SG++ doxygen documentation](http://sgpp.sparsegrids.org/index.html)). However, unlike the quadrature example alone, this repository further shows how to build your own projects utilizing SG++.
