#include "NetworkInfrastructure.hpp"
#include <iostream>
#include <string>

/* Constructeur par défaut */
NetworkInfrastructure::NetworkInfrastructure() : NetworkInfrastructure("",
                                                                       0,
                                                                       std::vector<NetworkDevice *>())
{
}

/* Constructeur avec paramètres */
NetworkInfrastructure::NetworkInfrastructure(const std::string &_name,
                                             int _maxDevices,
                                             std::vector<NetworkDevice *> _devices) : name(_name),
                                                                                      MAX_DEVICES(_maxDevices),
                                                                                      devices(_devices)
{
}

/* Constructeur de copie */
NetworkInfrastructure::NetworkInfrastructure(const NetworkInfrastructure &ni) : NetworkInfrastructure(ni.name,
                                                                                                      ni.MAX_DEVICES,
                                                                                                      ni.devices)
{
}

/* Destructeur */
NetworkInfrastructure::~NetworkInfrastructure()
{
}

/* Opérateur d'affectation */
NetworkInfrastructure &NetworkInfrastructure::operator=(const NetworkInfrastructure &ni)
{
    if (&ni != this)
    {
        name = ni.name;
        MAX_DEVICES = ni.MAX_DEVICES;
        devices = ni.devices;
    }
    return *this;
}

/* Getters et Setters */
std::string NetworkInfrastructure::getName() const
{
    return name;
}

int NetworkInfrastructure::getMaxDevices() const
{
    return MAX_DEVICES;
}

std::vector<NetworkDevice *> NetworkInfrastructure::getDevices() const
{
    return devices;
}

void NetworkInfrastructure::setName(const std::string &_name)
{
    name = _name;
}

void NetworkInfrastructure::setMaxDevices(int _maxDevices)
{
    MAX_DEVICES = _maxDevices;
}

void NetworkInfrastructure::setDevices(const std::vector<NetworkDevice *> &_devices)
{
    devices = _devices;
}
