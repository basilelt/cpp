#include "NetworkInfrastructure.hpp"
#include "Router.hpp"
#include "Switch.hpp"
#include "Server.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

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
                                                                                      maxDevices(_maxDevices),
                                                                                      devices(_devices)
{
    sortAndUniqueDevices();
}

/* Constructeur de copie */
NetworkInfrastructure::NetworkInfrastructure(const NetworkInfrastructure &ni) : NetworkInfrastructure(ni.name,
                                                                                                      ni.maxDevices,
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
        maxDevices = ni.maxDevices;
        devices = ni.devices;
        sortAndUniqueDevices();
    }
    return *this;
}

void NetworkInfrastructure::sortAndUniqueDevices()
{
    // Remove duplicates based on hostname
    std::set<std::string> hostnames;
    auto it = devices.begin();
    while (it != devices.end())
    {
        if (hostnames.count((*it)->getHostname()))
        {
            it = devices.erase(it);
        }
        else
        {
            hostnames.insert((*it)->getHostname());
            ++it;
        }
    }
    // Sort by hostname
    std::sort(devices.begin(), devices.end(),
              [](NetworkDevice *a, NetworkDevice *b)
              { return a->getHostname() < b->getHostname(); });
}

/* Getters et Setters */
std::string NetworkInfrastructure::getName() const
{
    return name;
}

int NetworkInfrastructure::getMaxDevices() const
{
    return maxDevices;
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
    maxDevices = _maxDevices;
}

void NetworkInfrastructure::setDevices(const std::vector<NetworkDevice *> &_devices)
{
    devices = _devices;
    sortAndUniqueDevices();
}

void NetworkInfrastructure::listDevices() const
{
    std::cout << "Devices in infrastructure " << name << ":" << std::endl;
    for (const auto *device : devices)
    {
        std::cout << "- " << device->getHostname() << std::endl;
    }
}

void NetworkInfrastructure::addDevice(NetworkDevice *device)
{
    if (devices.size() >= static_cast<size_t>(maxDevices))
        return;
    auto it = std::find_if(devices.begin(), devices.end(),
                           [device](NetworkDevice *d)
                           { return d->getHostname() == device->getHostname(); });
    if (it == devices.end())
    {
        devices.push_back(device);
        sortAndUniqueDevices();
    }
}

void NetworkInfrastructure::searchDeviceByHostname(const std::string &hostname) const
{
    // Binary search since devices are sorted by hostname
    int left = 0;
    int right = devices.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        std::string midHostname = devices[mid]->getHostname();

        if (midHostname == hostname)
        {
            std::cout << "Device found: " << devices[mid]->getHostname() << std::endl;
            return;
        }
        else if (midHostname < hostname)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << "Device not found: " << hostname << std::endl;
}

void NetworkInfrastructure::removeDeviceByHostname(const std::string &hostname)
{
    auto it = std::find_if(devices.begin(), devices.end(),
                           [&hostname](NetworkDevice *d)
                           { return d->getHostname() == hostname; });
    if (it != devices.end())
    {
        devices.erase(it);
    }
}

void NetworkInfrastructure::averagePowerConsumptionByType() const
{
    std::map<std::string, std::pair<double, int>> typeStats;
    for (const auto *device : devices)
    {
        std::string type;
        if (dynamic_cast<const Router *>(device))
            type = "Router";
        else if (dynamic_cast<const Switch *>(device))
            type = "Switch";
        else if (dynamic_cast<const Server *>(device))
            type = "Server";
        else
            type = "Unknown";

        typeStats[type].first += device->getPowerConsumption();
        typeStats[type].second++;
    }

    std::cout << "Average power consumption by type:" << std::endl;
    for (const auto &[type, stats] : typeStats)
    {
        double avg = stats.second > 0 ? stats.first / stats.second : 0.0;
        std::cout << type << ": " << avg << " W" << std::endl;
    }
}

std::ostream &NetworkInfrastructure::PrintOn(std::ostream &os) const
{
    os << "NetworkInfrastructure: " << name << std::endl;
    os << "Max Devices: " << maxDevices << std::endl;
    os << "Current Devices: " << devices.size() << std::endl;
    listDevices();
    return os;
}
