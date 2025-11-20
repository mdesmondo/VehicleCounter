#ifndef VEHICLE_H
#define VEHICLE_H

using namespace std;
#include <string>
#include <sstream>

class Vehicle {
private:
    string model;
    int year;
    double maxSpeed;
    static int totalVehicleCount;
protected:
    Vehicle(const string &model, int year, double maxSpeed);
public:
    virtual ~Vehicle();
    virtual string toString() const = 0;

    string getModel() const;
    int getYear() const;
    double getMaxSpeed() const;

    void setModel(const string &model);
    void setYear(int year);
    void setMaxSpeed(double maxSpeed);

    static int getTotalVehicleCount();
    static void plusVehicleCount();
    static void minusVehicleCount();
};

#endif