#include <iostream>
#include <vector>
#include <limits>
#include <typeinfo>
#include "Vehicle.h"
#include "LandVehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "WaterVehicle.h"
#include "Boat.h"
#include "ServiceVehicle.h"

using namespace std;

void displayMenu();
void addVehicle(vector<Vehicle*>& vehicles);
void displayAllVehicles(const vector<Vehicle*>& vehicles);
void displayVehicleByIndex(const vector<Vehicle*>& vehicles);
void countByExactType(const vector<Vehicle*>& vehicles);
void countByBaseType(const vector<Vehicle*>& vehicles);
void findBySpeed(const vector<Vehicle*>& vehicles);
void findByFuelType(const vector<Vehicle*>& vehicles);
void showStatistics();
void clearInput();
void deleteAllVehicles(vector<Vehicle*>& vehicles);

int main() {
    vector<Vehicle*> vehicles;
    char choice;
    string inputString;

    cout << "  СИСТЕМА УПРАВЛЕНИЯ ТРАНСПОРТОМ" << endl;

    while (true) {
        displayMenu();
        cin >> inputString;

        if (inputString.length() == 1) {
            choice = inputString[0];
        } else {
            cout << "Введите один символ!" << endl;
        }

        switch (choice) {
            case '1':
                addVehicle(vehicles);
                break;
            case '2':
                displayAllVehicles(vehicles);
                break;
            case '3':
                displayVehicleByIndex(vehicles);
                break;
            case '4':
                countByExactType(vehicles);
                break;
            case '5':
                countByBaseType(vehicles);
                break;
            case '6':
                findBySpeed(vehicles);
                break;
            case '7':
                findByFuelType(vehicles);
                break;
            case '8':
                showStatistics();
                break;
            case '0':
                cout << "\nВыход из программы..." << endl;
                deleteAllVehicles(vehicles);
                return 0;
            default:
                cout << "\nНеверный выбор! Попробуйте снова.\n" << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\n========== ГЛАВНОЕ МЕНЮ ==========" << endl;
    cout << "1. Добавить транспортное средство" << endl;
    cout << "2. Показать все объекты" << endl;
    cout << "3. Показать конкретный объект" << endl;
    cout << "4. Количество по точному типу" << endl;
    cout << "5. Количество с учетом наследования" << endl;
    cout << "6. Поиск по скорости (общая характеристика)" << endl;
    cout << "7. Поиск по типу топлива (специфичная)" << endl;
    cout << "8. Статистика" << endl;
    cout << "0. Выход" << endl;
    cout << "===================================" << endl;
    cout << "Ваш выбор: ";
}

void addVehicle(vector<Vehicle*>& vehicles) {
    char type;
    cout << "\n=== Выберите тип транспортного средства ===" << endl;
    cout << "1. Car (Легковой автомобиль)" << endl;
    cout << "2. Motorcycle (Мотоцикл)" << endl;
    cout << "3. Boat (Лодка)" << endl;
    cout << "4. ServiceVehicle (Служебное ТС)" << endl;
    cout << "Выбор: ";
    string inputStr;
    cin >> inputStr;
    if (inputStr.length() == 1) {
        type = inputStr[0];
    } else {
        cout << "Введите один символ!" << endl;
    }
    cin >> type;
    clearInput();

    string model, fuel;
    int year;
    double speed;

    cout << "\n--- Общие характеристики ---" << endl;
    cout << "Модель/Марка: ";
    getline(cin, model);
    cout << "Год выпуска: ";
    cin >> year;
    cout << "Максимальная скорость: ";
    cin >> speed;

    try {
        switch (type) {
            case '1': { // Car
                clearInput();
                cout << "\n--- Характеристики автомобиля ---" << endl;
                cout << "Тип топлива (Petrol/Diesel/Gas): ";
                getline(cin, fuel);
                int doors;
                double litrage;
                cout << "Количество дверей: ";
                cin >> doors;
                cout << "Объем двигателя (л): ";
                cin >> litrage;

                vehicles.push_back(new Car(model, year, speed, 4, fuel, doors, litrage));
                cout << "\nCar успешно добавлен!" << endl;
                break;
            }
            case '2': { // Motorcycle
                clearInput();
                cout << "\n--- Характеристики мотоцикла ---" << endl;
                cout << "Тип топлива: ";
                getline(cin, fuel);
                bool sidecar;
                string motoType;
                cout << "Есть коляска? (1-Да/0-Нет): ";
                cin >> sidecar;
                clearInput();
                cout << "Тип мотоцикла (Sport/Cruiser/Touring): ";
                getline(cin, motoType);

                vehicles.push_back(new Motorcycle(model, year, speed, fuel, sidecar, motoType));
                cout << "\nMotorcycle успешно добавлен!" << endl;
                break;
            }
            case '3': { // Boat
                double displacement;
                string hull;
                int capacity;
                bool motor;

                cout << "\n--- Характеристики лодки ---" << endl;
                cout << "Водоизмещение (тонн): ";
                cin >> displacement;
                clearInput();
                cout << "Тип корпуса (Wood/Fiberglass/Metal): ";
                getline(cin, hull);
                cout << "Вместимость (человек): ";
                cin >> capacity;
                cout << "Есть мотор? (1-Да/0-Нет): ";
                cin >> motor;

                vehicles.push_back(new Boat(model, year, speed, displacement, hull, capacity, motor));
                cout << "\nBoat успешно добавлен!" << endl;
                break;
            }
            case '4': { // ServiceVehicle
                clearInput();
                cout << "\n--- Характеристики служебного ТС ---" << endl;
                cout << "Тип топлива: ";
                getline(cin, fuel);
                string serviceType;
                cout << "Тип службы (Ambulance/Police/Fire): ";
                getline(cin, serviceType);

                vehicles.push_back(new ServiceVehicle(model, year, speed, fuel, serviceType));
                cout << "\nServiceVehicle успешно добавлен!" << endl;
                break;
            }
            default:
                cout << "\nНеверный тип транспортного средства!" << endl;
        }
    } catch (const exception& e) {
        cout << "\nОшибка при создании объекта: " << e.what() << endl;
    }
}

void displayAllVehicles(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст! Добавьте транспортные средства." << endl;
        return;
    }

    cout << "\n========== ВСЕ ТРАНСПОРТНЫЕ СРЕДСТВА ==========" << endl;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << "[" << i << "] " << vehicles[i]->toString() << endl;
    }
    cout << "===============================================" << endl;
    cout << "Всего объектов в массиве: " << vehicles.size() << endl;
}

void displayVehicleByIndex(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст!" << endl;
        return;
    }

    size_t index;
    cout << "\nВведите индекс объекта (0-" << vehicles.size() - 1 << "): ";
    cin >> index;

    if (index < vehicles.size()) {
        cout << "\n========== ИНФОРМАЦИЯ ОБ ОБЪЕКТЕ ==========" << endl;
        cout << vehicles[index]->toString() << endl;
        cout << "===========================================" << endl;
    } else {
        cout << "\nНеверный индекс!" << endl;
    }
}

void countByExactType(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст!" << endl;
        return;
    }

    int vehicleCount = 0, landCount = 0, waterCount = 0;
    int carCount = 0, motoCount = 0, boatCount = 0, serviceCount = 0;

    for (size_t i = 0; i < vehicles.size(); ++i) {
        if (typeid(*vehicles[i]) == typeid(Vehicle)) {
            vehicleCount++;
        } else if (typeid(*vehicles[i]) == typeid(LandVehicle)) {
            landCount++;
        } else if (typeid(*vehicles[i]) == typeid(WaterVehicle)) {
            waterCount++;
        } else if (typeid(*vehicles[i]) == typeid(Car)) {
            carCount++;
        } else if (typeid(*vehicles[i]) == typeid(Motorcycle)) {
            motoCount++;
        } else if (typeid(*vehicles[i]) == typeid(Boat)) {
            boatCount++;
        } else if (typeid(*vehicles[i]) == typeid(ServiceVehicle)) {
            serviceCount++;
        }
    }

    cout << "\n========== КОЛИЧЕСТВО ПО ТОЧНОМУ ТИПУ ==========" << endl;
    cout << "Без учета наследования" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Vehicle:        " << vehicleCount << endl;
    cout << "LandVehicle:    " << landCount << endl;
    cout << "WaterVehicle:   " << waterCount << endl;
    cout << "Car:            " << carCount << endl;
    cout << "Motorcycle:     " << motoCount << endl;
    cout << "Boat:           " << boatCount << endl;
    cout << "ServiceVehicle: " << serviceCount << endl;
    cout << "================================================" << endl;
}

void countByBaseType(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст!" << endl;
        return;
    }

    cout << "\n=== Выберите базовый тип для подсчета ===" << endl;
    cout << "1. Vehicle (все объекты)" << endl;
    cout << "2. LandVehicle (все наземные)" << endl;
    cout << "3. WaterVehicle (все водные)" << endl;
    cout << "4. Car (включая производные)" << endl;
    cout << "Выбор: ";

    int choice;
    cin >> choice;

    int count = 0;
    const char* typeName;

    for (size_t i = 0; i < vehicles.size(); ++i) {
        switch (choice) {
            case 1:
                if (dynamic_cast<Vehicle*>(vehicles[i])) {
                    count++;
                }
                typeName = "Vehicle";
                break;
            case 2:
                if (dynamic_cast<LandVehicle*>(vehicles[i])) {
                    count++;
                }
                typeName = "LandVehicle";
                break;
            case 3:
                if (dynamic_cast<WaterVehicle*>(vehicles[i])) {
                    count++;
                }
                typeName = "WaterVehicle";
                break;
            case 4:
                if (dynamic_cast<Car*>(vehicles[i])) {
                    count++;
                }
                typeName = "Car";
                break;
            default:
                cout << "\nНеверный выбор!" << endl;
                return;
        }
    }

    cout << "\n========================================" << endl;
    cout << "Тип: " << typeName << endl;
    cout << "Количество (с учетом наследования): " << count << endl;
    cout << "========================================" << endl;
}

void findBySpeed(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст!" << endl;
        return;
    }

    double minSpeed;
    cout << "\nВведите минимальную скорость (км/ч): ";
    cin >> minSpeed;

    cout << "\n========== ПОИСК ПО СКОРОСТИ >= " << minSpeed << " км/ч ==========" << endl;
    cout << "Общая характеристика (определена для ВСЕХ типов)" << endl;
    cout << "--------------------------------------------------------" << endl;

    bool found = false;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i]->getMaxSpeed() >= minSpeed) {
            cout << vehicles[i]->toString() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
    cout << "========================================================" << endl;
}

void findByFuelType(const vector<Vehicle*>& vehicles) {
    if (vehicles.empty()) {
        cout << "\nМассив пуст!" << endl;
        return;
    }

    clearInput();
    string fuelType;
    cout << "\nВведите тип топлива для поиска: ";
    getline(cin, fuelType);

    cout << "\n========== ПОИСК ПО ТИПУ ТОПЛИВА: " << fuelType << " ==========" << endl;
    cout << "Специфичная характеристика (только для LandVehicle)" << endl;
    cout << "----------------------------------------------------" << endl;

    bool found = false;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        LandVehicle* lv = dynamic_cast<LandVehicle*>(vehicles[i]);

        if (lv && lv->getFuelType() == fuelType) {
            cout << lv->toString() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
    cout << "=====================================================" << endl;
}

void showStatistics() {
    cout << "\n========== СТАТИСТИКА ==========" << endl;
    cout << "Подсчет через статические поля классов" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Всего Vehicle:      " << Vehicle::getTotalVehicleCount() << endl;
    cout << "LandVehicle:        " << LandVehicle::getLandVehicleCount() << endl;
    cout << "Car:                " << Car::getCarCount() << endl;
    cout << "Motorcycle:         " << Motorcycle::getMotorcycleCount() << endl;
    cout << "WaterVehicle:       " << WaterVehicle::getWaterVehicleCount() << endl;
    cout << "Boat:               " << Boat::getBoatCount() << endl;
    cout << "ServiceVehicle:     " << ServiceVehicle::getServiceVehicleCount() << endl;
    cout << "======================================================" << endl;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void deleteAllVehicles(vector<Vehicle*>& vehicles) {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        delete vehicles[i];
    }
    vehicles.clear();
}
