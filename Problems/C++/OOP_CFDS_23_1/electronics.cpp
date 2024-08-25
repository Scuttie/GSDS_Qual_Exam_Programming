#include "electronics.h"

// Fill in here
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// setsize(setter), getsize(getter) : parent class 것 상속받아서 그냥 쓰면 됨. override할 필요 없음
void Electronics::SetSize(int size){
    Size = size;
}

int Electronics::GetSize(){
    return Size;
}

void TV::PrintSelf(){
    int s = GetSize();
    float price = s * 1.8;
    cout << "It is a TV, Size=" << s << ", Price=" << price << endl;
};


void Computer::PrintSelf(){
    int s = GetSize();
    float price = s * 0.6;
    cout << "It is a Computer, Size=" << s << ", Price=" << price << endl;
};

void Cellphone::PrintSelf(){
    int s = GetSize();
    float price = s * 0.7;
    cout << "It is a Cellphone, Size=" << s << ", Price=" << price << endl;
};

void Laptop::PrintSelf() {
    int s = GetSize();
    float price = s * 0.6;

    if (gpus == 1) { // Gpu 하나 있으면 가격 두배 
        price *= 2;
    }

    cout << "It is a Laptop, Size=" << s << ", Price=" << price << endl;
}

void Laptop::AddGPU(Electronics *aGPU) {
    if (gpus == 0) {
        laptopGPU = aGPU;
        gpus++;
    }
}

void Desktop::PrintSelf(){
    int s = GetSize();
    float price, totalPrice;

    if (gpus == 0){
        price = s * 0.6;
    }
    else if (gpus == 1){        
        price = (s * 0.6) * 1.8; // GPU 있기만 하면 가격 1.8배
        totalPrice = price + GPU1 -> GetSize() * 0.6; // GPU 가격 더해줌
    }
    else if (gpus == 2){
        price = (s * 0.6) * 1.8;
        totalPrice = price + GPU1 -> GetSize() * 0.6 + GPU2 -> GetSize() * 0.6;
    }

    cout << "It is a Desktop with " << gpus<< " GPU(s), Size=" << s <<", Price= " << price <<", Total Price = " << totalPrice << endl;
};

void Desktop::AddGPU(Electronics *aGPU){
    if (gpus == 0) {
        GPU1 = aGPU; // desktop은 gpu 가격도 반영해서 가격 책정 : gpu object 기록
        gpus ++;
    } else if (gpus == 1) {
        GPU2 = aGPU;
        gpus ++;
    }
};