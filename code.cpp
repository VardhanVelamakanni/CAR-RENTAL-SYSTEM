#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Car {
public:
    std::string brand;
    std::string model;
    double dailyRate;
    int quantity; // Number of available cars

    Car(const std::string& brand, const std::string& model, double dailyRate, int quantity)
        : brand(brand), model(model), dailyRate(dailyRate), quantity(quantity) {}
};

class CarRentalSystem {
private:
    std::vector<Car> cars;

public:
    CarRentalSystem() {
        // Initialize some cars
        initializeCars();
    }

    void initializeCars() {
        // Car brands and models
        std::vector<std::string> brands = {"Toyota", "Honda", "Ford", "Suzuki", "Mahindra", "Tata", "Volvo", "Volkswagen", "MG"};
        std::vector<std::vector<std::string>> models = {
            {"Camry", "Corolla", "Rav4"},
            {"Accord", "Civic", "Pilot"},
            {"Mustang", "Fusion", "Explorer"},
            {"Swift", "Baleno", "Vitara"},
            {"Scorpio", "XUV500", "Thar"},
            {"Altroz", "Tiago", "Harrier"},
            {"XC90", "S60", "V60"},
            {"Golf", "Passat", "Tiguan"},
            {"Hector", "ZS EV", "Gloster"}
        };

        // Set up cars with random daily rates and quantities
        for (size_t i = 0; i < brands.size(); ++i) {
            for (const auto& model : models[i]) {
                cars.emplace_back(brands[i], model, 30.0 + i * 5.0, 5);
            }
        }
    }

    void displayAvailableCarBrands() const {
        std::cout << "Available Car Brands:" << std::endl;
        std::vector<std::string> uniqueBrands;
        for (const Car& car : cars) {
            if (std::find(uniqueBrands.begin(), uniqueBrands.end(), car.brand) == uniqueBrands.end()) {
                uniqueBrands.push_back(car.brand);
                std::cout << car.brand << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void displayAvailableModelsForBrand(const std::string& brand) const {
        std::cout << "Available Models for " << brand << ":" << std::endl;
        for (const Car& car : cars) {
            if (car.brand == brand) {
                std::cout << car.model << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void displayAvailableCars() const {
        std::cout << "Available Cars:" << std::endl;
        for (const Car& car : cars) {
            std::cout << car.brand << " " << car.model << " - ₹" << car.dailyRate << " per day | Available: " << car.quantity << std::endl;
        }
        std::cout << std::endl;
    }

    double rentCar(const std::string& brand, const std::string& model, int days) {
        for (Car& car : cars) {
            if (car.brand == brand && car.model == model && car.quantity > 0) {
                double totalRent = car.dailyRate * days;
                std::cout << "Cost per day for " << car.brand << " " << car.model << ": ₹" << car.dailyRate << std::endl;
                std::cout << "You have rented a " << car.brand << " " << car.model << " for " << days << " days." << std::endl;
                std::cout << "Total Rent: ₹" << totalRent << std::endl;

                car.quantity--; // Reduce the available quantity

                return totalRent;
            }
        }
        std::cout << "Car not available for rent or out of stock." << std::endl;
        return 0.0;
    }

    void returnCar(const std::string& brand, const std::string& model) {
        for (Car& car : cars) {
            if (car.brand == brand && car.model == model) {
                std::cout << "You have returned a " << car.brand << " " << car.model << "." << std::endl;

                car.quantity++; // Increase the available quantity

                return;
            }
        }
        std::cout << "Invalid return. Car not found or already returned." << std::endl;
    }

    const std::vector<Car>& getCars() const {
        return cars;
    }
};

int main() {
    CarRentalSystem rentalSystem;

    std::cout << "Welcome to Creative Car Rentals!" << std::endl;
    rentalSystem.displayAvailableCarBrands();

    std::string chosenBrand, chosenModel;
    int rentalDays;

    std::cout << "Enter the brand of the car you want to rent: ";
    std::cin >> chosenBrand;

    // Validate the chosen brand
    bool validBrand = false;
    for (const Car& car : rentalSystem.getCars()) {
        if (car.brand == chosenBrand) {
            validBrand = true;
            break;
        }
    }

    if (!validBrand) {
        std::cout << "Invalid brand. Please choose from the available brands." << std::endl;
        return 1;
    }

    // Display available models for the chosen brand
    rentalSystem.displayAvailableModelsForBrand(chosenBrand);

    std::cout << "Enter the model of the car you want to rent: ";
    std::cin >> chosenModel;

    std::cout << "Enter the number of days you want to rent the car (max 7 days): ";
    std::cin >> rentalDays;

    if (rentalDays <= 0 || rentalDays > 7) {
        std::cout << "Invalid number of days. Please enter a number between 1 and 7." << std::endl;
        return 1;
    }

    double totalRent = rentalSystem.rentCar(chosenBrand, chosenModel, rentalDays);

    std::cout << "Thank you for choosing Creative Car Rentals!" << std::endl;
    std::cout << "Your total rent is: ₹" << totalRent << std::endl;

    return 0;
}