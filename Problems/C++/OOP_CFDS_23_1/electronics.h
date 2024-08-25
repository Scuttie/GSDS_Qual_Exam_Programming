#pragma once

// Fill in here
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Electronics{
    protected:
        float Size;
    public:
        Electronics(int size) : Size(size){};
        virtual ~Electronics(){};

        void SetSize(int size);
        int GetSize();
        virtual void PrintSelf() = 0;
};

class TV : public Electronics{
    public:
        TV(int size) : Electronics(size){};

        virtual void PrintSelf() override;
};

class Computer : public Electronics{
    public:
        Computer(int size) : Electronics(size){};
        
        virtual void PrintSelf() override;
};

class Cellphone : public Electronics{
    public:
        Cellphone(int size) : Electronics(size){};

        virtual void PrintSelf() override;
};

class Laptop : public Computer{
    private:
        int gpus = 0;
        Electronics *laptopGPU; // gpu object 저장 (gpu도 computer class 상속받음 : main.cpp 파일 참고)
    public:
        Laptop(int size) : Computer(size){};
        
        virtual void PrintSelf() override;
        void AddGPU(Electronics *aGPU);
};

class Desktop : public Computer{
    private:
        int gpus = 0;
        Electronics *GPU1;
        Electronics *GPU2;

    public:
        Desktop(int size) : Computer(size){};

        virtual void PrintSelf() override;
        void AddGPU(Electronics *aGPU);
};