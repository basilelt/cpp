#include <iostream>
#include <vector>
#include "NetworkInfrastructure.hpp"
#include "NetworkDevice.hpp"
#include "Router.hpp"
#include "Switch.hpp"
#include "Server.hpp"

int main()
{
    NetworkDevice device1;
    device1.printInfo(std::cout);
    std::cout << std::endl;

    NetworkDevice device2("core-sw-00", "10.0.0.1", "Datacenter A", "Cisco", "IOS-XE", 2020, 420.0, true);
    device2.printInfo(std::cout);
    std::cout << std::endl;

    device1.setHostname("core-sw-00");
    device1.setIpAddress("10.0.0.2");
    device1.setLocation("Datacenter A");
    device1.setVendor("Cisco");
    device1.setOsVersion("IOS-XE");
    device1.setYear(2020);
    device1.setPowerConsumption(420.0);
    device1.setIsCritical(false);
    device1.printInfo(std::cout);
    std::cout << std::endl;

    device1.ping();
    std::cout << std::endl;

    
    Server server1;
    server1.printInfo(std::cout);
    std::cout << std::endl;

    Server server2(16);
    server2.setHostname("Server");
    server2.setIpAddress("10.0.0.1");
    server2.setLocation("Datacenter A");
    server2.setVendor("Intel");
    server2.setOsVersion("Linux");
    server2.setYear(2020);
    server2.setPowerConsumption(420.0);
    server2.setIsCritical(true);
    server2.printInfo(std::cout);
    std::cout << std::endl;


    Router router1;
    router1.printInfo(std::cout);
    std::cout << std::endl;

    Router router2(500);
    router2.setHostname("core-sw-01");
    router2.setIpAddress("10.0.0.1");
    router2.setLocation("Datacenter A");
    router2.setVendor("Cisco");
    router2.setOsVersion("IOS-XE");
    router2.setYear(2020);
    router2.setPowerConsumption(420.0);
    router2.setIsCritical(true);
    router2.printInfo(std::cout);
    std::cout << std::endl;


    Switch switch1;
    switch1.printInfo(std::cout);
    std::cout << std::endl;

    Switch switch2(48);
    switch2.setHostname("core-sw-02");
    switch2.setIpAddress("10.0.0.1");
    switch2.setLocation("Datacenter A");
    switch2.setVendor("Cisco");
    switch2.setOsVersion("IOS-XE");
    switch2.setYear(2020);
    switch2.setPowerConsumption(80.0);
    switch2.setIsCritical(false);
    switch2.printInfo(std::cout);
    std::cout << std::endl;


    NetworkInfrastructure infra("infra", 10, {});
    std::cout << "Infrastructure Name: " << infra.getName() << std::endl;
    std::cout << "Max Devices: " << infra.getMaxDevices() << std::endl;
    std::cout << std::endl;

    infra.addDevice(&router2);
    infra.addDevice(&switch2);
    infra.addDevice(&server2);
    infra.listDevices();
    std::cout << std::endl;

    infra.searchDeviceByHostname("core-sw-01");
    std::cout << std::endl;

    infra.averagePowerConsumptionByType();
    std::cout << std::endl;

    infra.removeDeviceByHostname("core-sw-02");
    std::cout << "After removal (core-sw-02):" << std::endl;
    infra.listDevices();
    std::cout << std::endl;

    return 0;
}
