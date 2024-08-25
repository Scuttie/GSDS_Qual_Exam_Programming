#include <stdio.h>
#include <stdlib.h>
#include "electronics.h"

int main() {
  Electronics* e1 = new TV(600);
  Electronics* e2 = new Cellphone(160);
  Laptop * e3 = new Laptop(330);
  Desktop * e4 = new Desktop(400);

  Computer * laptopGPU = new Computer(50);
  Computer * GPU1 = new Computer(50);
  Computer * GPU2 = new Computer(20);
  
  e3->AddGPU(laptopGPU);
  e4->AddGPU(GPU1);
  e4->AddGPU(GPU2);
  
  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();
  e4->PrintSelf();
  

  delete e1;
  delete e2;
  delete e3;
  delete e4;
  delete laptopGPU;
  delete GPU1;
  delete GPU2;

  return EXIT_SUCCESS;
}
