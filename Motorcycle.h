#ifndef LAB5_MOTORCYCLE_H
#define LAB5_MOTORCYCLE_H

#include "LandVehicle.h"

class Motorcycle : public LandVehicle {
private:
    bool hasSidecar;
    string motorcycleType;
    static int motorcycleCount;

public:
    Motorcycle(const string& mod, int yr, double speed, const string& fuel,
               bool sidecar, const string& type);

    virtual ~Motorcycle();

    string toString() const override;

    bool getHasSidecar() const;
    string getMotorcycleType() const;

    void setHasSidecar(bool sidecar);
    void setMotorcycleType(const string& type);

    static int getMotorcycleCount();
};

#endif //LAB5_MOTORCYCLE_H
