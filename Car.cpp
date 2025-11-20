#include "Car.h"

int Car::carCount = 0;

Car::Car(const string& mod, int yr, double speed, int wheels, const string& fuel, int doors, double litrage) :
    LandVehicle(mod, yr, speed, 4, fuel), doorsCount(doors), engineLitrage(litrage) {
    carCount++;
}

Car::~Car() {
    carCount--;
}

string Car::toString() const {
    ostringstream oss;
    oss << "Машина марки: " << getModel()
        << ", Год: " << getYear()
        << ", Максимальная скорость: " << getMaxSpeed()
        << ", Тип топлива: " << getFuelType()
        << ", Количество дверей: " << getDoorsCount()
        << ", Объем двигателя: " << getEngineLitrage();
    return oss.str();
}

int Car::getDoorsCount() const {
    return doorsCount;
}
double Car::getEngineLitrage() const {
    return engineLitrage;
}
void Car::setDoorsCount(const int doors) {
    doorsCount = doors;
}
void Car::setEngineLitrage(const double litrage) {
    engineLitrage = litrage;
}

int Car::getCarCount() {
    return carCount;
}