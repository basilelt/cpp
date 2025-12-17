#include "Switch.hpp"
#include <iostream>
#include <string>
#include "NetworkDevice.hpp"

/* Constructeur par défaut */
Switch::Switch() : NetworkDevice(), portCount(0)
{
}

/* Constructeur avec paramètres */
Switch::Switch(int _portCount) : NetworkDevice(), portCount(_portCount)
{
}

/* Constructeur de copie */
Switch::Switch(const Switch &s) : NetworkDevice(s), portCount(s.portCount)
{
}

/* Destructeur */
Switch::~Switch()
{
}

/* Opérateur d'affectation */
Switch &Switch::operator=(const Switch &s)
{
    if (&s != this)
    {
        NetworkDevice::operator=(s);
        portCount = s.portCount;
    }
    return *this;
}

/* Getters et Setters */
int Switch::getPortCount() const
{
    return portCount;
}

void Switch::setPortCount(int _portCount)
{
    portCount = _portCount;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &Switch::printInfo(std::ostream &os) const
{
    os << "Switch: " << std::endl;
    os << "Hostname: " << hostname << std::endl;
    os << "IP address: " << ipAddress << std::endl;
    os << "Location: " << location << std::endl;
    os << "Vendor: " << vendor << std::endl;
    os << "OS version: " << osVersion << std::endl;
    os << "Installed in: " << year << std::endl;
    if (isCritical)
        os << "This device is critical)" << std::endl;
    else
        os << "This device is not critical)" << std::endl;
    os << "Power consumption: " << powerConsumption << " W" << std::endl;
    os << "Port count: " << portCount << std::endl;
    os << std::endl;
    return os;
}
