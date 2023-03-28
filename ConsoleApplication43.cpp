#include <iostream>
#include <string>

//  Визначення ієрархії класів
class Engine {
public:
    virtual ~Engine() {};
    virtual void output() = 0;
};

class PerpetualMotionMachine : public Engine { //Вічний двигун
public:
    void output() override {
        std::cout << "Perpetual motion machines do not exist." << std::endl;
    }
};

class InternalCombustionEngine : public Engine { //Двигун внутрішнього згорання.
private:
    double engineVolume; // Об'єм двигуна
    double enginePower;  // Потужність двигуна
    double fuelConsumption; // Використання бензину
public:
    InternalCombustionEngine(double volume, double power, double consumption)
        : engineVolume(volume), enginePower(power), fuelConsumption(consumption) {}

    void output() override {
        std::cout << "Internal combustion engine:" << std::endl;
        std::cout << "  Engine volume: " << engineVolume << " l" << std::endl;
        std::cout << "  Engine power: " << enginePower << " hp" << std::endl;
        std::cout << "  Fuel consumption: " << fuelConsumption << " l/100km" << std::endl;
    }
};

class ElectricMotor : public Engine { //Електро Двигун
private:
    double motorPower; // Потужність двигуна 
    double voltage;  // Напруга 
    int numberOfPhases;  // Кількість фаз
public:
    ElectricMotor(double power, double v, int phases)
        : motorPower(power), voltage(v), numberOfPhases(phases) {}

    void output() override {
        std::cout << "Electric motor:" << std::endl;
        std::cout << "  Motor power: " << motorPower << " kW" << std::endl;
        std::cout << "  Voltage: " << voltage << " V" << std::endl;
        std::cout << "  Number of phases: " << numberOfPhases << std::endl;
    }
};
#include <vector>

int main() {
    std::vector<Engine*> engines;
    engines.push_back(new InternalCombustionEngine(1.6, 105, 6.2));
    engines.push_back(new ElectricMotor(90, 400, 3));
    engines.push_back(new PerpetualMotionMachine());

    for (Engine* engine : engines) {
        engine->output();
        std::cout << std::endl;
    }

    for (Engine* engine : engines) {
        delete engine;
    }

    return 0;
}
