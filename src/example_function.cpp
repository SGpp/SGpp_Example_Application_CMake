#include <example_function.hpp>

// function to interpolate
double f(int dim, double* x, void* clientdata) {
  double res = 1.0;

  for (int i = 0; i < dim; i++) {
    res *= 4.0 * x[i] * (1.0 - x[i]);
  }

  return res;
}

