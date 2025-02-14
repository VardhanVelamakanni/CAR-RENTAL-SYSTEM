# Car Rental System

## Overview
The **Car Rental System** is a simple C++ console application that allows users to rent and return cars from a predefined list of available vehicles. The system provides information about different car brands, models, daily rental rates, and available stock. It also ensures that users rent vehicles only for a valid number of days and manages the inventory accordingly.

## Features
- Display available car brands.
- Display available models for a selected brand.
- Display all available cars along with rental prices and stock.
- Rent a car by selecting a brand, model, and number of days.
- Return a rented car to update the inventory.
- Prevent renting of unavailable cars.
- Restrict rental period to a maximum of 7 days.

## Technologies Used
- **C++** (Standard Template Library - STL)
- **OOP Principles** (Encapsulation, Inheritance)
- **Vectors for Data Storage**

## Installation and Execution
1. **Install a C++ Compiler** (GCC, Clang, or MSVC)


## How to Use
1. The system welcomes you and displays the available car brands.
2. Enter the brand of the car you wish to rent.
3. The system will display the available models for that brand.
4. Enter the model name of the car you want to rent.
5. Enter the number of days (1-7) for the rental.
6. The system calculates the total rental cost and confirms your booking.
7. After use, you can return the car to increase its available stock.

## Example Interaction
```
Welcome to Creative Car Rentals!
Available Car Brands:
Toyota
Honda
Ford
...

Enter the brand of the car you want to rent: Toyota
Available Models for Toyota:
Camry
Corolla
Rav4

Enter the model of the car you want to rent: Corolla
Enter the number of days you want to rent the car (max 7 days): 3
Cost per day for Toyota Corolla: ₹30
You have rented a Toyota Corolla for 3 days.
Total Rent: ₹90
Thank you for choosing Creative Car Rentals!
```



