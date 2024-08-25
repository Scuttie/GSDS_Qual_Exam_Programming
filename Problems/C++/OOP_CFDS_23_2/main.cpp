#include <cstdlib>
#include <iostream>
#include "shape.h"

int main() {
  Square sq(5.0f);
  Equilateral eq(4.0f);

  sq.print();
  eq.print();

  Shape *s1 = &sq; // Shape의 Pointer이지만 Square object를 가리키고 있음.
  Shape *s2 = &eq; // Shape의 Pointer이지만 Equi- object를 가리키고 있음.

  s1->print(); // print()는 Shape의 format을 따름. 하지만 area()는 square에서 override한 format을 따름
  s2->print(); // print()는 Shape의 format을 따름. 하지만 area()는 square에서 override한 format을 따름

  return EXIT_SUCCESS;
}