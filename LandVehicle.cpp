#include "LandVehicle.h"

int LandVehicle::LandVehicleCount = 0;

LandVehicle::LandVehicle(const string& mod, int yr, double mxSpeed, int wheels, const string& fuel) :
    Vehicle(mod, yr, mxSpeed), numberWheels(wheels), fuelType(fuel) {
    LandVehicleCount++;
}

LandVehicle::~LandVehicle() {
    LandVehicleCount--;
}

string LandVehicle::toString() const {
    ostringstream oss;
    oss << "Наземный транспорт марки: " << getModel()
        << "Год: " << getYear()
        << "Максимальная скорость: " << getMaxSpeed() << "км/ч"
        << "Количество колес: " << getNumberWheels()
        << "Тип топлива: " << getFuelType();
    return oss.str();
}

int LandVehicle::getNumberWheels() const {
    return numberWheels;
}
string LandVehicle::getFuelType() const {
    return fuelType;
}
void LandVehicle::setNumberWheels(const int& wheels) {
    numberWheels = wheels;
}
void LandVehicle::setFuelType(const string& fuel) {
    fuelType = fuel;
}

int LandVehicle::getLandVehicleCount() {
    return LandVehicleCount;
}