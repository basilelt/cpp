#ifndef SERVER_H
#define SERVER_H

#include "NetworkDevice.hpp"

class Server : public NetworkDevice
{
public:
    Server();               /* constructeur par défaut */
    Server(int);            /* constructeur avec paramètres */
    Server(const Server &); /* constructeur de copie */
    virtual ~Server();      /* destructeur */

    virtual Server &operator=(const Server &); /* opérateur d'affectation */

    virtual int getCpuCores() const;
    virtual void setCpuCores(int);

    /* Override car ancêtre */
    virtual std::ostream &printInfo(std::ostream &) const override;

private:
    int cpuCores; // nombre de cœurs CPU
};

#endif /* Server_hpp */