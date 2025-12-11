#include "EnergyCard.hpp"
#include <iostream>

int main()
{
    EnergyCard ec1;
    EnergyCard ec2("Electric");

    std::cout << "Default EnergyCard:" << std::endl;
    ec1.displayInfo(std::cout) << std::endl;

    std::cout << "Electric EnergyCard:" << std::endl;
    ec2.displayInfo(std::cout) << std::endl;

    return 0;
}