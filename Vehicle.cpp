#include "Vehicle.h"

int Vehicle::totalVehicleCount = 0;

Vehicle::Vehicle(const string &mod, int yr, double mxSpeed)
    : model(mod), year(yr), maxSpeed(mxSpeed) {
    plusVehicleCount();
}

Vehicle::~Vehicle() {
    minusVehicleCount();
}

string Vehicle::getModel() const {
    return model;
}
int Vehicle::getYear() const {
    return year;
}
double Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

void Vehicle::setModel(const string &mod) {
    model = mod;
}
void Vehicle::setYear(int yr) {
    year = yr;
}
void Vehicle::setMaxSpeed(double mxSpeed) {
    maxSpeed = mxSpeed;
}

int Vehicle::getTotalVehicleCount() {
    return totalVehicleCount;
}

void Vehicle::plusVehicleCount() {
    totalVehicleCount += 1;
}
void Vehicle::minusVehicleCount() {
    totalVehicleCount -= 1;
}