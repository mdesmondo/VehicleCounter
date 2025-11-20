#ifndef LAB5_CAR_H
#define LAB5_CAR_H
#include "LandVehicle.h"


class Car : public LandVehicle {
private:
    int doorsCount;
    double engineLitrage;
    static int carCount;

public:
    Car(const string& mod, int yr, double speed, int wheels, const string& fuel, int doors, double engineL);
    Car() = delete;

    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;

    virtual ~Car();

    string toString() const override;

    int getDoorsCount() const;
    double getEngineLitrage() const;

    void setDoorsCount(int doors);
    void setEngineLitrage(double litrage);

    static int getCarCount();
};
#endif //LAB5_CAR_H