#include "Server.hpp"
#include <iostream>
#include <string>
#include "NetworkDevice.hpp"

/* Constructeur par défaut */
Server::Server() : NetworkDevice(), cpuCores(0)
{
}

/* Constructeur avec paramètres */
Server::Server(int _cpuCores) : NetworkDevice(), cpuCores(_cpuCores)
{
}

/* Constructeur de copie */
Server::Server(const Server &s) : NetworkDevice(s), cpuCores(s.cpuCores)
{
}

/* Destructeur */
Server::~Server()
{
}

/* Opérateur d'affectation */
Server &Server::operator=(const Server &s)
{
    if (&s != this)
    {
        NetworkDevice::operator=(s);
        cpuCores = s.cpuCores;
    }
    return *this;
}

/* Getters et Setters */
int Server::getCpuCores() const
{
    return cpuCores;
}

void Server::setCpuCores(int _cpuCores)
{
    cpuCores = _cpuCores;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &Server::printInfo(std::ostream &os) const
{
    os << "Server: " << std::endl;
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
    os << "CPU cores: " << cpuCores << std::endl;
    os << std::endl;
    return os;
}

std::ostream &Server::PrintOn(std::ostream &os) const
{
    return printInfo(os);
}
