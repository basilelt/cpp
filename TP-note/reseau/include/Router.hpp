#ifndef ROUTER_H
#define ROUTER_H

#include "NetworkDevice.hpp"

class Router : public NetworkDevice
{
public:
    Router();               /* constructeur par défaut */
    Router(int);            /* constructeur avec paramètres */
    Router(const Router &); /* constructeur de copie */
    virtual ~Router();      /* destructeur */

    virtual Router &operator=(const Router &); /* opérateur d'affectation */

    virtual int getRoutingTableSize() const;
    virtual void setRoutingTableSize(int);

    /* Override car ancêtre */
    virtual std::ostream &printInfo(std::ostream &) const override;

private:
    int routingTableSize;
};

#endif /* Router_hpp */