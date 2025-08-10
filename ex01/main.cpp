#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.CIN = 42;
    data.name = "Hello World";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original CIN: " << data.CIN << ", name: " << data.name << std::endl;

    // Sérialisation
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    // Désérialisation
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized CIN: " << ptr->CIN << ", name: " << ptr->name << std::endl;

    // Vérification
    if (ptr == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers do not match!" << std::endl;

    return 0;
}
