#pragma once
#include<iostream>
#include <stdint.h>

struct Data
{
    int         CIN;
    std::string name;
    std::string adress;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &affect);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};