#include "Router.hpp"
#include <iostream>
#include <string>
#include "NetworkDevice.hpp"

/* Constructeur par défaut */
Router::Router() : NetworkDevice(), routingTableSize(0)
{
}

/* Constructeur avec paramètres */
Router::Router(int _routingTableSize) : NetworkDevice(), routingTableSize(_routingTableSize)
{
}

/* Constructeur de copie */
Router::Router(const Router &r) : NetworkDevice(r), routingTableSize(r.routingTableSize)
{
}

/* Destructeur */
Router::~Router()
{
}

/* Opérateur d'affectation */
Router &Router::operator=(const Router &r)
{
    if (&r != this)
    {
        NetworkDevice::operator=(r);
        routingTableSize = r.routingTableSize;
    }
    return *this;
}

/* Getters et Setters */
int Router::getRoutingTableSize() const
{
    return routingTableSize;
}

void Router::setRoutingTableSize(int _routingTableSize)
{
    routingTableSize = _routingTableSize;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &Router::printInfo(std::ostream &os) const
{
    os << "Router: " << std::endl;
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
    os << "CPU cores: " << routingTableSize << std::endl;
    os << std::endl;
    return os;
}
