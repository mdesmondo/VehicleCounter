#include "ServiceVehicle.h"

int ServiceVehicle::serviceVehicleCount = 0;

ServiceVehicle::ServiceVehicle(const string& mod, int yr, double speed,
                               const string& fuel, const string& service)
    : LandVehicle(mod, yr, speed, 4, fuel), 
      serviceType(service), 
      needsMaintenance(false) {
    serviceVehicleCount++;
}

ServiceVehicle::~ServiceVehicle() {
    serviceVehicleCount--;
}

string ServiceVehicle::toString() const {
    ostringstream oss;
    oss << "Служебное ТС марки: " << getModel()
        << ", Год: " << getYear()
        << ", Максимальная скорость: " << getMaxSpeed() << " км/ч"
        << ", Тип топлива: " << getFuelType()
        << ", Тип службы: " << serviceType
        << ", Статус: " << (needsMaintenance ? "Требует ТО" : "Исправно");
    return oss.str();
}

void ServiceVehicle::doMaintenance() {
    performMaintenance();
}

string ServiceVehicle::checkStatus() const {
    return getMaintenanceStatus();
}

void ServiceVehicle::performMaintenance() {
    needsMaintenance = false;
}

string ServiceVehicle::getMaintenanceStatus() const {
    if (needsMaintenance) {
        return "Требуется обслуживание";
    }
    return "В хорошем состоянии";
}

string ServiceVehicle::getServiceType() const {
    return serviceType;
}

void ServiceVehicle::setServiceType(const string& service) {
    serviceType = service;
}

int ServiceVehicle::getServiceVehicleCount() {
    return serviceVehicleCount;
}
