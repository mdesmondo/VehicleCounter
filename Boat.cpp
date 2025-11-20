#include "Boat.h"

int Boat::boatCount = 0;

Boat::Boat(const string& mod, int yr, double speed, double displ,
           const string& hull, int capacity, bool motor)
    : WaterVehicle(mod, yr, speed, displ, hull), 
      passengerCapacity(capacity), hasMotor(motor) {
    boatCount++;
}

Boat::~Boat() {
    boatCount--;
}

string Boat::toString() const {
    ostringstream oss;
    oss << "Лодка марки: " << getModel()
        << ", Год: " << getYear()
        << ", Максимальная скорость: " << getMaxSpeed() << " узлов"
        << ", Водоизмещение: " << getDisplacement() << " т"
        << ", Вместимость: " << passengerCapacity << " чел."
        << ", Мотор: " << (hasMotor ? "Да" : "Нет");
    return oss.str();
}

int Boat::getPassengerCapacity() const {
    return passengerCapacity;
}

bool Boat::getHasMotor() const {
    return hasMotor;
}

void Boat::setPassengerCapacity(int capacity) {
    passengerCapacity = capacity;
}

void Boat::setHasMotor(bool motor) {
    hasMotor = motor;
}

int Boat::getBoatCount() {
    return boatCount;
}
