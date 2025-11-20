#include "Motorcycle.h"

int Motorcycle::motorcycleCount = 0;

Motorcycle::Motorcycle(const string& mod, int yr, double speed, const string& fuel,
                       bool sidecar, const string& type)
    : LandVehicle(mod, yr, speed, 2, fuel), hasSidecar(sidecar), motorcycleType(type) {
    motorcycleCount++;
}

Motorcycle::~Motorcycle() {
    motorcycleCount--;
}

string Motorcycle::toString() const {
    ostringstream oss;
    oss << "Мотоцикл марки: " << getModel()
        << ", Год: " << getYear()
        << ", Максимальная скорость: " << getMaxSpeed() << " км/ч"
        << ", Тип топлива: " << getFuelType()
        << ", Тип: " << motorcycleType
        << ", Коляска: " << (hasSidecar ? "Да" : "Нет");
    return oss.str();
}

bool Motorcycle::getHasSidecar() const {
    return hasSidecar;
}

string Motorcycle::getMotorcycleType() const {
    return motorcycleType;
}

void Motorcycle::setHasSidecar(bool sidecar) {
    hasSidecar = sidecar;
}

void Motorcycle::setMotorcycleType(const string& type) {
    motorcycleType = type;
}

int Motorcycle::getMotorcycleCount() {
    return motorcycleCount;
}
