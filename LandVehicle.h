#ifndef LAB5_LANDVEHICLE_H
#define LAB5_LANDVEHICLE_H

#include "Vehicle.h"


class LandVehicle: public Vehicle {
private:
    int numberWheels;
    string fuelType;
    static int LandVehicleCount;
protected:
    LandVehicle(const string& mod, int yr, double mxSpeed, int wheels, const string& fuel);
public:
    virtual ~LandVehicle();

    string toString() const override;

    int getNumberWheels() const;
    string getFuelType() const;

    void setNumberWheels(const int& numberWheels);
    void setFuelType(const string& fuelType);

    static int getLandVehicleCount();
};


#endif //LAB5_LANDVEHICLE_H