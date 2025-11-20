#ifndef LAB5_SERVICEVEHICLE_H
#define LAB5_SERVICEVEHICLE_H

#include "LandVehicle.h"
#include "Maintainable.h"

// Закрытое наследование от Maintainable
class ServiceVehicle : public LandVehicle, private Maintainable {
private:
    string serviceType; // скорая, полиция, пожарная
    bool needsMaintenance;
    static int serviceVehicleCount;

public:
    ServiceVehicle(const string& mod, int yr, double speed, const string& fuel, const string& service);
    virtual ~ServiceVehicle();
    
    string toString() const override;
    
    // публичные обертки для закрытых методов Maintainable
    void doMaintenance();
    string checkStatus() const;
    
    string getServiceType() const;
    void setServiceType(const string& service);
    
    static int getServiceVehicleCount();

private:
    // реализация закрытых методов интерфейса
    void performMaintenance() override;
    string getMaintenanceStatus() const override;
};

#endif //LAB5_SERVICEVEHICLE_H