## Car Rental System - Documentation

### 1. Introduction
The Car Rental System is a console-based application that allows users to manage a car rental service. It enables users to perform various operations such as viewing the available cars, issuing a car to customers, returning rented cars, adding new cars to the system, and deleting cars from the inventory. The system is implemented using C++ programming language and utilizes a linked list data structure to store information about different car categories: sedan, SUV, and truck.

### 2. Features
The Car Rental System offers the following key features:

#### 2.1 View Car List
Allows users to view the list of available cars categorized into sedan, SUV, and truck. Users can see detailed information about each car, including car model, transmission type, seating capacity, fuel type, license plate number, car ID, base rental rate, and fuel policy.

#### 2.2 Issue Car
Enables users to rent a car by providing their personal information and rental details, including pick-up location, pick-up date, pick-up time, and rental period in days. After the car is issued to the customer, a receipt is generated showing the car details, rental cost, and customer information.

#### 2.3 Return Car
Allows customers to return their rented cars by providing drop-off details, including drop-off date, drop-off time, and drop-off location. The system generates a receipt displaying the car details, rental cost, and customer information for confirmation.

#### 2.4 Add Car
Allows the car rental company to add new cars to the system. Users can input car details, such as car model, transmission type, seating capacity, fuel type, license plate number, car ID, base rental rate, and fuel policy. The new car is added to the appropriate category (sedan, SUV, or truck).

#### 2.5 Delete Car
Allows the car rental company to remove cars from the system by specifying the car ID. The car is deleted from the linked list corresponding to its category.

### 3. Implementation Details
The Car Rental System is implemented using C++ programming language. It utilizes the following components:

#### 3.1 Car Structure
A `struct` called `Car` is defined to represent the properties of a car. It contains attributes such as car model, transmission type, seating capacity, fuel type, license plate number, car ID, base rental rate, and fuel policy.

#### 3.2 Node Structure
A `struct` called `Node` is defined to create a linked list. It contains a `Car` object and a pointer to the next node.

#### 3.3 CarRental Class
The `CarRental` class manages the car rental operations and contains the following member functions:

- `insertCar`: Inserts a new car into the linked list corresponding to its category (sedan, SUV, or truck).
- `findCar`: Searches for a car in the linked list based on its car ID and returns a pointer to the node containing the car.
- `deleteCar`: Deletes a car from the linked list based on its car ID.
- `displayCarList`: Displays the list of cars in a specific category (sedan, SUV, or truck) along with their details.
- `viewCarList`: Allows users to view the car lists categorized by type and select a car to rent.
- `receipt`: Generates a receipt after issuing a car to a customer, displaying car details, rental cost, and customer information.
- `issueCar`: Allows users to rent a car by providing personal information and rental details.
- `returnCar`: Allows customers to return their rented cars and generates a receipt for confirmation.
- `addCar`: Enables the car rental company to add new cars to the system.
- `deleteCar`: Allows the car rental company to delete cars from the system.

#### 3.4 Main Function
The `main` function is the entry point of the program. It creates an instance of the `CarRental` class and presents a menu to the user. Users can choose from different options to perform specific operations on the car rental system.

### 4. Usage Instructions
To use the Car Rental System, follow these steps:

1. Run the program: Compile and execute the C++ code in a C++ compiler. The program will display a menu with different options for managing the car rental system.

2. View Car List: Select option `1` from the menu to view the list of available cars categorized as sedan, SUV, or truck.

3. Issue Car: Select option `2` from the menu to rent a car. Provide personal information and rental details, and the system will issue a car to the customer. A receipt will be generated displaying the car details, rental cost, and customer information.

4. Return Car: Select option `3` from the menu to return a rented car. Provide drop-off details such as drop-off date, drop-off time, and drop-off location. A receipt will be generated for confirmation.

5. Add Car: Select option `4` from the menu to add a new car to the rental system. Enter car details such as car model, transmission type, seating capacity, fuel type, license plate number, car ID, base rental rate, and fuel policy.

6. Delete Car: Select option `5` from the menu to delete a car from the rental system. Provide the car ID of the car to be deleted.

7. Exit: Select option `6` from the menu to exit the program.

### 5. Conclusion
The Car Rental System is a simple console-based application that allows users to manage car rental operations efficiently. By utilizing linked lists to store car information, it provides a flexible and dynamic way to add and remove cars from the inventory. The system's menu-driven interface makes it user-friendly and easy to navigate for both car rental companies and customers.

Please note that this documentation provides an overview of the Car Rental System's functionality, and the actual implementation can be further enhanced and expanded to meet specific business requirements.

Collaborators:                    Email               Github
Marasigan Xyzon Ezekiel R.  xyzonezm98@gmailcom  Zxynerprogram09     
Carandang Angelica D.                               aica
