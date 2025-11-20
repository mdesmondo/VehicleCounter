#include "WaterVehicle.h"

int WaterVehicle::waterVehicleCount = 0;

WaterVehicle::WaterVehicle(const string& mod, int yr, double speed, double displ, const string& hull)
    : Vehicle(mod, yr, speed), displacement(displ), hullType(hull) {
    waterVehicleCount++;
}

WaterVehicle::~WaterVehicle() {
    waterVehicleCount--;
}

string WaterVehicle::toString() const {
    ostringstream oss;
    oss << "Водный транспорт марки: " << getModel()
        << ", Год: " << getYear()
        << ", Максимальная скорость: " << getMaxSpeed() << " узлов"
        << ", Водоизмещение: " << displacement << " т"
        << ", Тип корпуса: " << hullType;
    return oss.str();
}

double WaterVehicle::getDisplacement() const {
    return displacement;
}

string WaterVehicle::getHullType() const {
    return hullType;
}

void WaterVehicle::setDisplacement(double displ) {
    displacement = displ;
}

void WaterVehicle::setHullType(const string& hull) {
    hullType = hull;
}

int WaterVehicle::getWaterVehicleCount() {
    return waterVehicleCount;
}
