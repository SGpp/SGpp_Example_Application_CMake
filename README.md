## Purpose of this repository

This repository is meant as a starting point for people who want to use SG++ in a project of their own. 
It demonstrates how to use git submodules to include SG++ as an external dependency and how to use cmake
to both build SG++ and the project itself.

## How to build

### 1. Clone repository
> git clone https://github.com/SGpp/SGpp_Example_Application_CMake.git my_example

> cd my_example
### 2. Checkout SGpp submodule
> git submodule update --init external_dependencies/SGpp

The submodule is not checked out during a normal git clone, thus we do it this way.
### 3. Move to build directory
> mkdir -p build

> cd build

We will use a subfolder within the project root as a build directory. Of course this can be changed to another directory.
### 4. Run cmake
> cmake ..

This command will both configure the project as well as build SG++.
Note that with this setup SG++ will only be built when the cmake command is called.
Thus, if the SG++ submodule itself is set to another commit, the cmake command needs to be run again.

### 5. Run make
> make

This command will build the actual example application. It will not build SG++ again in order to save compilation time.
