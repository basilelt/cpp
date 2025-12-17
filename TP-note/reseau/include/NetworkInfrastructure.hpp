#ifndef NetworkInfrastructure_H
#define NetworkInfrastructure_H

#include "Base.hpp"
#include <string>
#include <vector>
#include "NetworkDevice.hpp"

class NetworkInfrastructure : public Base
{
public:
    NetworkInfrastructure();                                                       /* constructeur par défaut */
    NetworkInfrastructure(const std::string &, int, std::vector<NetworkDevice *>); /* constructeur avec paramètres */
    NetworkInfrastructure(const NetworkInfrastructure &);                          /* constructeur de copie */
    virtual ~NetworkInfrastructure();                                              /* destructeur */

    virtual NetworkInfrastructure &operator=(const NetworkInfrastructure &); /* opérateur d'affectation */

    virtual std::string getName() const;
    virtual int getMaxDevices() const;
    virtual std::vector<NetworkDevice *> getDevices() const;
    virtual void setName(const std::string &);
    virtual void setMaxDevices(int);
    virtual void setDevices(const std::vector<NetworkDevice *> &);

    virtual void listDevices() const;
    virtual void addDevice(NetworkDevice *);
    virtual void searchDeviceByHostname(const std::string &) const; // O(log n)
    virtual void removeDeviceByHostname(const std::string &hostname);
    virtual void averagePowerConsumptionByType() const;
    virtual std::ostream &PrintOn(std::ostream &) const override;

private:
    void sortAndUniqueDevices();

    std::string name;                     // nom de l'infrastructure
    int maxDevices;                       // capacité maximale
    std::vector<NetworkDevice *> devices; // équipements réseau
};

#endif /* NetworkInfrastructure_hpp */