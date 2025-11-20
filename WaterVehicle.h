#ifndef LAB5_WATERVEHICLE_H
#define LAB5_WATERVEHICLE_H

#include "Vehicle.h"

class WaterVehicle : public Vehicle {
private:
    double displacement; // водоизмещение в тоннах
    string hullType; // тип корпуса
    static int waterVehicleCount;
    
protected:
    WaterVehicle(const string& mod, int yr, double speed, double displ, const string& hull);
    
public:
    virtual ~WaterVehicle();
    
    string toString() const override;
    
    double getDisplacement() const;
    string getHullType() const;
    
    void setDisplacement(double displ);
    void setHullType(const string& hull);
    
    static int getWaterVehicleCount();
};

#endif //LAB5_WATERVEHICLE_H
