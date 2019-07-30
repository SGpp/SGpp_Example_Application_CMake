
#include <sgpp_base.hpp>
#include <iostream>

#include <example_function.hpp>


int main() {
  double x[2] = {2, 2};
  double erg = f(2, x, x);
  std::cout << "Hello function: " << erg << std::endl;
}
