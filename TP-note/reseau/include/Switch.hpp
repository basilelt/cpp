#ifndef SWITCH_H
#define SWITCH_H

#include "NetworkDevice.hpp"

class Switch : public NetworkDevice
{
public:
    Switch();               /* constructeur par défaut */
    Switch(int);            /* constructeur avec paramètres */
    Switch(const Switch &); /* constructeur de copie */
    virtual ~Switch();      /* destructeur */

    virtual Switch &operator=(const Switch &); /* opérateur d'affectation */

    virtual int getPortCount() const;
    virtual void setPortCount(int);

    /* Override car ancêtre */
    virtual std::ostream &printInfo(std::ostream &) const override;

private:
    int portCount;
};

#endif /* Switch_hpp */