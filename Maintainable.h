#ifndef LAB5_MAINTAINABLE_H
#define LAB5_MAINTAINABLE_H

#include <string>

class Maintainable {
public:
    virtual ~Maintainable() {};
    virtual void performMaintenance() = 0;
    virtual string getMaintenanceStatus() const = 0;
};

#endif