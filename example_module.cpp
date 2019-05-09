#include "pybind11/pybind11.h"

double add(double a, double b)
{
  return a+b;
}

PYBIND11_MODULE(example_module, m){
  m.def("add", add);
}
