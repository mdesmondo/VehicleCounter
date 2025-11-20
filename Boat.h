#ifndef LAB5_BOAT_H
#define LAB5_BOAT_H

#include "WaterVehicle.h"

class Boat : public WaterVehicle {
private:
    int passengerCapacity;
    bool hasMotor;
    static int boatCount;
    
public:
    Boat(const string& mod, int yr, double speed, double displ, 
         const string& hull, int capacity, bool motor);
    
    virtual ~Boat();
    
    string toString() const override;
    
    int getPassengerCapacity() const;
    bool getHasMotor() const;
    
    void setPassengerCapacity(int capacity);
    void setHasMotor(bool motor);
    
    static int getBoatCount();
};

#endif //LAB5_BOAT_H
