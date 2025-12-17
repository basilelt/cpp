#include "NetworkDevice.hpp"
#include <iostream>
#include <string>

/* Constructeur par défaut */
NetworkDevice::NetworkDevice() : NetworkDevice(
                                     "",
                                     "",
                                     "",
                                     "",
                                     "",
                                     0,
                                     0.0,
                                     false)
{
}

/* Constructeur avec paramètres */
NetworkDevice::NetworkDevice(
    std::string _hostname,
    std::string _ipAdress,
    std::string _location,
    std::string _vendor,
    std::string _osVersion,
    int _year,
    double _powerConsumption,
    bool _isCritical) : hostname(_hostname),
                        ipAdress(_ipAdress),
                        location(_location),
                        vendor(_vendor),
                        osVersion(_osVersion),
                        year(_year),
                        powerConsumption(_powerConsumption),
                        isCritical(_isCritical)
{
}

/* Constructeur de copie */
NetworkDevice::NetworkDevice(const NetworkDevice &p) : NetworkDevice(
                                                           p.hostname,
                                                           p.ipAdress,
                                                           p.location,
                                                           p.vendor,
                                                           p.osVersion,
                                                           p.year,
                                                           p.powerConsumption,
                                                           p.isCritical)
{
}

/* Destructeur */
NetworkDevice::~NetworkDevice()
{
}

/* Opérateur d'affectation */
NetworkDevice &NetworkDevice::operator=(const NetworkDevice &nd)
{
    if (&nd != this)
    {
        hostname = nd.hostname;
        ipAdress = nd.ipAdress;
        location = nd.location;
        vendor = nd.vendor;
        osVersion = nd.osVersion;
        year = nd.year;
        powerConsumption = nd.powerConsumption;
        isCritical = nd.isCritical;
    }
    return *this;
}

/* Getters et Setters */
std::string NetworkDevice::getHostname() const
{
    return hostname;
}

std::string NetworkDevice::getIpAdress() const
{
    return ipAdress;
}

std::string NetworkDevice::getLocation() const
{
    return location;
}

std::string NetworkDevice::getVendor() const
{
    return vendor;
}

std::string NetworkDevice::getOsVersion() const
{
    return osVersion;
}

int NetworkDevice::getYear() const
{
    return year;
}

double NetworkDevice::getPowerConsumption() const
{
    return powerConsumption;
}

bool NetworkDevice::getIsCritical() const
{
    return isCritical;
}

void NetworkDevice::setHostname(const std::string &_hostname)
{
    hostname = _hostname;
}

void NetworkDevice::setIpAdress(const std::string &_ipAdress)
{
    ipAdress = _ipAdress;
}

void NetworkDevice::setLocation(const std::string &_location)
{
    location = _location;
}

void NetworkDevice::setVendor(const std::string &_vendor)
{
    vendor = _vendor;
}

void NetworkDevice::setOsVersion(const std::string &_osVersion)
{
    osVersion = _osVersion;
}

void NetworkDevice::setYear(int _year)
{
    year = _year;
}

void NetworkDevice::setPowerConsumption(double _powerConsumption)
{
    powerConsumption = _powerConsumption;
}

void NetworkDevice::setIsCritical(bool _isCritical)
{
    isCritical = _isCritical;
}

void NetworkDevice::ping() const
{
    std::cout << "Pinging " << ipAdress;
    std::cout << "..." << std::endl;

    // test ici
    std::cout << "Reply from " << ipAdress;
    std::cout << ": bytes=32 time=20ms TTL=64";
    std::cout << std::endl;
}

std::ostream &NetworkDevice::printInfo(std::ostream &os) const
{
    os << "NetworkDevice(";
    os << hostname << ", ";
    os << ipAdress << ", ";
    os << location << ", ";
    os << vendor << ", ";
    os << osVersion << ", ";
    os << year << ", ";
    os << powerConsumption << ", ";
    os << isCritical << ")";
    os << std::endl;
    return os;
}