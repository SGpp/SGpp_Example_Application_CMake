## Purpose of this repository

This repository is meant as a starting point for people who want to use SG++ in a project of their own. 
It demonstrates how to use git submodules to include SG++ as an external dependency and how to use cmake
to both build SG++ and the project itself.

## How to build

#### 1. Clone repository
> git clone https://github.com/SGpp/SGpp_Example_Application_CMake.git my_example

> cd my_example
#### 2. Checkout SGpp submodule
> git submodule update --init external_dependencies/SGpp

The submodule is not checked out during a normal git clone. Thus, we do it this way.
#### 3. Move to build directory
> mkdir -p build

> cd build

We will use a subfolder within the project root as a build directory. Of course this can be changed to another directory.
#### 4. Run cmake
> cmake ..

This command will both configure the project as well as build SG++.
Note that with this setup SG++ will only be built when the cmake command is called.
Thus, if the SG++ submodule itself is set to another commit, the cmake command needs to be run again.

#### 5. Run make
> make

This command will build the actual example application. It will not build SG++ again in order to save compilation time.

## How to modify the build
The SG++ version used can simply be changed by going to the (checked out) submodule folder external_dependencies/SGpp and changing the commit there as one would in a normal git repository.

Most likely you want to change the configuration used by SG++, for example by deactivating modules you do not need or by activating a wrapper for another language like Python.
This can be done in the CMakeLists.txt. In this example, we build all modules of SG++ in order to demonstrate how to include the headers and link libraries with your own application.

To deactivate a module, edit the scons command, which is called in the CMakelists.txt file, to deactivate a module. For example, you need to change SG_DATADRIVEN=0 and remove the line linking to the library libsgppdatadriven.so to deactivate the SG++ datadriven module.

To see all ways to configure scons for SG++, go to the (checked out) submodule directory and run
> scons -h

or visit [SG++ Github page](https://github.com/SGpp/SGpp) for more information.


## About the utilized example
The application itself shows how to integrate functions in SG++, using both direct integration of a sparse grid function and the use of Monte Carlo integration.
It is heavily based on the SG++ example [quadrature.cpp](https://github.com/SGpp/SGpp/blob/master/base/examples/quadrature.cpp). However, unlike the quadrature example alone, this repository further shows how to build your own projects utilizing SG++.