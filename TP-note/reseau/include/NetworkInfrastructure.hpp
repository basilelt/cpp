#ifndef NetworkInfrastructure_H
#define NetworkInfrastructure_H

#include "Base.hpp"
#include <string>
#include <vector>
#include "NetworkDevice.hpp"

class NetworkInfrastructure : public Base
{
public:
    NetworkInfrastructure();                                               /* constructeur par défaut */
    NetworkInfrastructure(std::string, int, std::vector<NetworkDevice *>); /* constructeur avec paramètres */
    NetworkInfrastructure(const NetworkInfrastructure &);                  /* constructeur de copie */
    virtual ~NetworkInfrastructure();                                      /* destructeur */

    virtual NetworkInfrastructure &operator=(const NetworkInfrastructure &); /* opérateur d'affectation */

    virtual std::string getName() const;
    virtual int getMaxDevices() const;
    virtual std::vector<NetworkDevice *> getDevices() const;
    virtual void setName(const std::string &);
    virtual void setMaxDevices(int);
    virtual void setDevices(const std::vector<NetworkDevice *> &);

private:
    std::string name;                     // nom de l'infrastructure
    static int MAX_DEVICES;               // capacité maximale
    std::vector<NetworkDevice *> devices; // équipements réseau
};

#endif /* NetworkInfrastructure_hpp */