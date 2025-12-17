#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include "Base.hpp"
#include <string>

class NetworkDevice : public Base
{
public:
    NetworkDevice(); /* constructeur par défaut */
    NetworkDevice(std::string,
                  std::string,
                  std::string,
                  std::string,
                  std::string,
                  int,
                  double,
                  bool);                  /* constructeur avec paramètres */
    NetworkDevice(const NetworkDevice &); /* constructeur de copie */
    virtual ~NetworkDevice();             /* destructeur */

    virtual NetworkDevice &operator=(const NetworkDevice &); /* opérateur d'affectation */

    virtual std::string getHostname() const;
    virtual std::string getIpAdress() const;
    virtual std::string getLocation() const;
    virtual std::string getVendor() const;
    virtual std::string getOsVersion() const;
    virtual int getYear() const;
    virtual double getPowerConsumption() const;
    virtual bool getIsCritical() const;
    virtual void setHostname(const std::string &);
    virtual void setIpAddress(const std::string &);
    virtual void setLocation(const std::string &);
    virtual void setVendor(const std::string &);
    virtual void setOsVersion(const std::string &);
    virtual void setYear(int);
    virtual void setPowerConsumption(double);
    virtual void setIsCritical(bool);

    virtual void ping() const;
    virtual std::ostream &printInfo(std::ostream &) const;
    virtual std::ostream &PrintOn(std::ostream &) const override;

protected:
    std::string hostname;
    std::string ipAddress;
    std::string location;
    std::string vendor;
    std::string osVersion;
    int year;
    double powerConsumption;
    bool isCritical;
};

#endif /* NetworkDevice_hpp */