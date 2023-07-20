#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Structure to represent a car
struct Car
{
    // Car details
    string carmodel;
    string transmissionType;
    int seatingCapacity;
    string fuelType;
    string licensePlateNumber;
    string carID;
    float baseRentalRate;
    string fuelPolicy;
};
// Structure to represent a node in the linked list
struct Node
{
    Car car;
    Node* next;
};
// CarRental class to manage car rental operations
class CarRental
{
public:
    Node* sedanList;
    Node* suvList;
    Node* truckList;
    // Constructor to initialize the linked lists to nullptr
    CarRental() : sedanList(nullptr), suvList(nullptr), truckList(nullptr) {}

    // Function to insert a car into the linked list
    void insertCar(Node*& carList, const Car& car)
    {
        Node* newNode = new Node;
        newNode->car = car;
        newNode->next = nullptr;

        if (carList == nullptr)
        {
            carList = newNode;
        }

        else
        {
            Node* current = carList;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // Function to find a car in the linked list based on carID
    Node* findCar(Node* carList, const string& carID)
    {
        Node* current = carList;
        while (current != nullptr)
        {
            if (current->car.carID == carID)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    // Function to delete a car from the linked list based on carID
    void deleteCar(Node*& carList, const string& carID)

    //(Implementation of deleteCar function)
    {
        if (carList == nullptr)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\tNo cars available in the list." << endl;
            cout << "\n\t\t\t\t";
            getch();
            return;
        }

        if (carList->car.carID == carID)
        {
            Node* temp = carList;
            carList = carList->next;
            delete temp;
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\tCar with ID " << carID << " has been deleted." << endl;
            cout << "\n\t\t\t\t";
            getch();
            return;
        }

        Node* previous = carList;
        Node* current = carList->next;

        while (current != nullptr && current->car.carID != carID)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\tCar with ID " << carID << " not found." << endl;
            cout << "\n\t\t\t\t";
            getch();
            return;
        }

        else
        {
            previous->next = current->next;
            delete current;
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\tCar with ID " << carID << " has been deleted." << endl;
            cout << "\n\t\t\t\t";
            getch();
            return;
        }
    }
    // Function to display the list of cars in a specific category (sedan, suv, truck)
    void displayCarList(Node* carList, const string& category)

    //(Implementation of displayCarList function)
    {
        if (carList == nullptr)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                   " << category << " CAR LIST" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;
            cout << "\n\t\t\t\tNo cars available in the " << category << " list." << endl;
            cout << "\n\t\t\t\t";
            getch();
            return;
        }

        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t*******************************************************" << endl;
        cout << "\t\t\t\t                   " << category << " CAR LIST" << endl;
        cout << "\t\t\t\t*******************************************************" << endl;

        Node* current = carList;
        int count = 1;
        while (current != nullptr)
        {
            cout << "\n\t\t\t\t" << count << ". Car Model: " << current->car.carmodel << endl;
            cout << "\t\t\t\t   Transmission Type: " << current->car.transmissionType << endl;
            cout << "\t\t\t\t   Seating Capacity: " << current->car.seatingCapacity << endl;
            cout << "\t\t\t\t   Fuel Type: " << current->car.fuelType << endl;
            cout << "\t\t\t\t   License Plate Number: " << current->car.licensePlateNumber << endl;
            cout << "\t\t\t\t   Car ID: " << current->car.carID << endl;
            cout << "\t\t\t\t   Base Rental Rate: " << current->car.baseRentalRate << endl;
            cout << "\t\t\t\t   Fuel Policy: " << current->car.fuelPolicy << endl;

            current = current->next;
            count++;
        }

        cout << "\n\t\t\t\tPress any key to continue...";
        cin.ignore();
        cin.get();
    }
    // Function to display the list of cars in a selected category
    void viewCarList()
    {
        int carTypeChoice;
        do {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                   VIEW CAR LIST" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;
            cout << "\n\t\t\t\tCar Categories" << endl;
            cout << "\n\t\t\t\t  1. Sedan";
            cout << "\n\t\t\t\t  2. SUV";
            cout << "\n\t\t\t\t  3. Truck";
            cout << "\n\t\t\t\t  4. Go Back";
            cout << "\n\n\t\t\t\tEnter Car Category: ";
            cin >> carTypeChoice;
            cout << endl;

            switch (carTypeChoice)
            {
                case 1:
                    displayCarList(sedanList, "SEDAN");
                    break;
                case 2:
                    displayCarList(suvList, "SUV");
                    break;
                case 3:
                    displayCarList(truckList, "TRUCK");
                    break;
                case 4:
                    break;
                default:
                    system("cls");
                    cout << "\n\n\n\n\n\n\t\t\t\tInvalid choice. Please try again." << endl;
                    getch();
                    break;
            }
        }

        while (carTypeChoice != 4);
    }
    // Function to display a receipt after issuing a car to a customer
    void receipt(const Car& issuedCar, const string& fullName, const string& phoneNumber,
                const string& emailAddress, const string& residentialAddress,
                const string& pickUpLocation, const string& pickUpDate,
                const string& pickUpTime, int rentalPeriod)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
        cout << "\t\t\t\t                        RECEIPT" << endl;
        cout << "\t\t\t\t*******************************************************" << endl;

        cout << "\n\t\t\t\tCAR SPECIFICATIONS";
        cout << "\n\t\t\t\t    Car Model: " << issuedCar.carmodel;
        cout << "\n\t\t\t\t    Transmission Type: " << issuedCar.transmissionType;
        cout << "\n\t\t\t\t    Seating Capacity: " << issuedCar.seatingCapacity << " Seats";
        cout << "\n\t\t\t\t    Fuel Type: " << issuedCar.fuelType;
        cout << "\n\t\t\t\t    License Plate Number: " << issuedCar.licensePlateNumber;
        cout << "\n\t\t\t\t    Car ID: " << issuedCar.carID;
        cout << endl;

        cout << "\n\t\t\t\tRENTAL DETAILS";
        cout << "\n\t\t\t\t    Pick-up Location: " << pickUpLocation;
        cout << "\n\t\t\t\t    Pick-up Date: " << pickUpDate;
        cout << "\n\t\t\t\t    Pick-up Time: " << pickUpTime;
        cout << "\n\t\t\t\t    Rental Period: " << rentalPeriod << " days";
        cout << endl;

        float rentalCost = issuedCar.baseRentalRate * rentalPeriod;
        cout << "\n\t\t\t\tPAYMENT SUMMARY";
        cout << "\n\t\t\t\t    Rental Cost: ₱" << rentalCost;
        cout << "\n\t\t\t\t    Fuel Policy: Full to Full ";
        cout << endl;

        cout << "\n\t\t\t\tCUSTOMER DETAILS";
        cout << "\n\t\t\t\t    Full Name: " << fullName;
        cout << "\n\t\t\t\t    Phone Number: " << phoneNumber;
        cout << "\n\t\t\t\t    Email Address: " << emailAddress;
        cout << "\n\t\t\t\t    Residential Address: " << residentialAddress;
        cout << endl;

        cout << "\n\t\t\t\t*******************************************************" << endl;
        cout << "\t\t\t\t       Thank you for using our car rental service!" << endl;
        cout << "\t\t\t\t*******************************************************" << endl;
    }
    // Function to issue a car to a customer
    void issueCar()
    {
        int carTypeChoice;
        do {
            system("cls");
            cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                   ISSUE CAR" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;
            cout << "\n\t\t\t\tCar Categories" << endl;
            cout << "\n\t\t\t\t  1. Sedan";
            cout << "\n\t\t\t\t  2. SUV";
            cout << "\n\t\t\t\t  3. Truck";
            cout << "\n\t\t\t\t  4. Go Back";
            cout << "\n\n\t\t\t\tEnter Car Category: ";
            cin >> carTypeChoice;
            cout << endl;

            if (carTypeChoice != 4)
            {
                displayCarList(carTypeChoice);
            }

        }
        while (carTypeChoice != 4);
    }

    void displayCarList(int carTypeChoice)
    {
        Node* carList = nullptr;

        switch (carTypeChoice)
        {
            case 1:
                carList = sedanList;
                break;
            case 2:
                carList = suvList;
                break;
            case 3:
                carList = truckList;
                break;
            default:
                cout << "\n\t\t\t\tInvalid choice. Please try again." << endl;
                getch();
                return;
        }

        if (carList == nullptr)
        {
            system("cls");
            cout << "\n\n\n\n\t\t\t\tNo cars available in the selected category." << endl;
            cout << "\n\t\t\t\tPress any key to continue...";
            cin.ignore();
            cin.get();
            return;
        }

        system("cls");
        cout << "\n\t\t\t\t*******************************************************" << endl;
        cout << "\t\t\t\t                   ";
        switch (carTypeChoice)
        {
            case 1:
                cout << "SEDAN";
                break;
            case 2:
                cout << "SUV";
                break;
            case 3:
                cout << "TRUCK";
                break;
        }

        system("cls");
        cout << " CAR LIST";
        cout << "\n\t\t\t\t*******************************************************" << endl;

        Node* current = carList;
        int count = 1;
        while (current != nullptr)
        {
            cout << "\n\t\t\t\t" << count << ". Car Model: " << current->car.carmodel << endl;
            cout << "\t\t\t\t   Transmission Type: " << current->car.transmissionType << endl;
            cout << "\t\t\t\t   Seating Capacity: " << current->car.seatingCapacity << " Seats" << endl;
            cout << "\t\t\t\t   Fuel Type: " << current->car.fuelType << endl;
            cout << "\t\t\t\t   License Plate Number: " << current->car.licensePlateNumber << endl;
            cout << "\t\t\t\t   Car ID: " << current->car.carID << endl;
            cout << "\t\t\t\t   Base Rental Rate: " << current->car.baseRentalRate << endl;

            current = current->next;
            count++;
        }

        cout << "\n\t\t\t\tPress any key to continue...";
        cin.ignore();
        cin.get();

        string carID;
        cout << "\n\t\t\t\tEnter Car ID to Rent: ";
        cin >> carID;

        Node* car = findCar(carList, carID);

        if (car != nullptr)
        {
            string fullName, phoneNumber, emailAddress, residentialAddress, pickUpLocation, pickUpDate, pickUpTime;
            int rentalPeriod;

            system("cls");
            cout << "\n\n\t\t\t\t    Personal Information";
            cout << "\n\t\t\t\t      Full Name: ";
            cin.ignore();
            getline(cin, fullName);
            cout << "\t\t\t\t      Phone Number: ";
            getline(cin, phoneNumber);
            cout << "\t\t\t\t      Email Address: ";
            getline(cin, emailAddress);
            cout << "\t\t\t\t      Residential Address: ";
            getline(cin, residentialAddress);

            cout << "\n\t\t\t\t    Rental Details";
            cout << "\n\t\t\t\t      Pick-up Location: ";
            getline(cin, pickUpLocation);
            cout << "\t\t\t\t      Pick-up Date: ";
            getline(cin, pickUpDate);
            cout << "\t\t\t\t      Pick-up Time: ";
            getline(cin, pickUpTime);
            cout << "\t\t\t\t      Rental Period (days): ";
            cin >> rentalPeriod;
            cout << endl;

            receipt(car->car, fullName, phoneNumber, emailAddress, residentialAddress, pickUpLocation,
                pickUpDate, pickUpTime, rentalPeriod);

            cout << "\n\n\n\t\t\t\tCar with ID " << carID << " has been rented." << endl;
            getch();
            return;
        }

        else
        {
            cout << "\n\n\n\t\t\t\tCar with ID " << carID << " not found. Please try again." << endl;
            getch();
            return;
        }
    }
    // Function to return a car
    void returnCar()
    {
        system("cls");
        string carID;
        string dropOffDate, dropOffTime, dropOffLocation;
        string returnConfirmation;

        cout << "\n\n\n\n\n\n\t\t\t\tRETURN CAR" << endl;
        cout << "\n\t\t\t\t  Enter Car ID: ";
        cin >> carID;

        cout << "\n\t\t\t\t  Return Details";
        cout << "\n\t\t\t\t    Drop-off Date: ";
        cin >> dropOffDate;
        cout << "\t\t\t\t    Drop-off Time: ";
        cin >> dropOffTime;
        cout << "\t\t\t\t    Drop-off Location: ";
        cin >> dropOffLocation;

        cout << "\n\t\t\t\t  Return Confirmation (Y/N): ";
        cin >> returnConfirmation;

        cout << "\n\t\t\t\t  Rental Company Information";
        cout << "\n\t\t\t\t    Company Name: ABC Rental Co.";
        cout << "\n\t\t\t\t    Rental Location: Batangas";
        cout << endl;

        Car returnedCar;
        bool carFound = false;

        Node* current = sedanList;
        while (current != nullptr)
        {
            if (current->car.carID == carID)
            {
                returnedCar = current->car;
                carFound = true;
                break;
            }
            current = current->next;
        }

        if (!carFound)
        {
            current = suvList;
            while (current != nullptr)
            {
                if (current->car.carID == carID)
                {
                    returnedCar = current->car;
                    carFound = true;
                    break;
                }
                current = current->next;
            }
        }

        if (!carFound)
        {
            current = truckList;
            while (current != nullptr)
            {
                if (current->car.carID == carID)
                {
                    returnedCar = current->car;
                    carFound = true;
                    break;
                }
                current = current->next;
            }
        }

        if (carFound)
        {
            cout << "\n\t\t\t\t    Press any to continue...";
            getch();
            system("cls");

            cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                        RECEIPT" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;

            cout << "\n\t\t\t\tCAR SPECIFICATIONS";
            cout << "\n\t\t\t\t    Car Model: " << returnedCar.carmodel;
            cout << "\n\t\t\t\t    Transmission Type: " << returnedCar.transmissionType;
            cout << "\n\t\t\t\t    Seating Capacity: " << returnedCar.seatingCapacity << " Seats";
            cout << "\n\t\t\t\t    Fuel Type: " << returnedCar.fuelType;
            cout << "\n\t\t\t\t    License Plate Number: " << returnedCar.licensePlateNumber;
            cout << "\n\t\t\t\t    Car ID: " << returnedCar.carID;
            cout << endl;

            cout << "\n\t\t\t\tRETURN DETAILS" << endl;
            cout << "\n\t\t\t\t    Drop-off Date: " << dropOffDate;
            cout << "\n\t\t\t\t    Drop-off Time: " << dropOffTime;
            cout << "\n\t\t\t\t    Drop-off Location: " << dropOffLocation;
            cout << "\n\n\t\t\t\t    ";

            int returnCarSubChoice;
            do
            {
                getch();
                cout << "1. Go Back";
                cout << "\n\t\t\t\t  2. Exit";
                cout << "\n\n\t\t\t\t  Enter Choice: ";
                cin >> returnCarSubChoice;
                cout << endl;
            }
            while (returnCarSubChoice != 1 && returnCarSubChoice != 2);

            if (returnCarSubChoice == 2)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tClosing Application..." << endl;
                getch();
                cout <<"\n\n\n\n\n";
                exit(0);
            }
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tError! Please try again." << endl;
            getch();
            return;
        }
    }
    // Function to add a new car to the rental system
    void addCar()
    {
        int carTypeChoice;
        do {
            system("cls");
            cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                   ADD A CAR" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;
            cout << "\n\t\t\t\tCar Categories" << endl;
            cout << "\n\t\t\t\t  1. Sedan";
            cout << "\n\t\t\t\t  2. SUV";
            cout << "\n\t\t\t\t  3. Truck";
            cout << "\n\t\t\t\t  4. Go Back";
            cout << "\n\n\t\t\t\tEnter Car Category: ";
            cin >> carTypeChoice;
            cout << endl;

            if (carTypeChoice != 4)
            {
                Car newCar;
                cout << "\n\t\t\t\tEnter Car Model: ";
                cin.ignore();
                getline(cin, newCar.carmodel);

                cout << "\t\t\t\tEnter Transmission Type: ";
                getline(cin, newCar.transmissionType);

                cout << "\t\t\t\tEnter Seating Capacity: ";
                cin >> newCar.seatingCapacity;

                cout << "\t\t\t\tEnter Fuel Type: ";
                cin.ignore();
                getline(cin, newCar.fuelType);

                cout << "\t\t\t\tEnter License Plate Number: ";
                getline(cin, newCar.licensePlateNumber);

                cout << "\t\t\t\tEnter Car ID: ";
                getline(cin, newCar.carID);

                cout << "\t\t\t\tEnter Base Rental Rate: ";
                cin >> newCar.baseRentalRate;

                cout << "\t\t\t\tEnter Fuel Policy: ";
                cin.ignore();
                getline(cin, newCar.fuelPolicy);

                switch (carTypeChoice) {
                case 1:
                    insertCar(sedanList, newCar);
                    break;
                case 2:
                    insertCar(suvList, newCar);
                    break;
                case 3:
                    insertCar(truckList, newCar);
                    break;
                default:
                    cout << "\n\t\t\t\tInvalid choice. Please try again." << endl;
                    break;
                }

                cout << "\n\n\t\t\t\tCar added successfully!" << endl;
                cout << "\n\t\t\t\tPress any key to continue...";
                cin.ignore();
                cin.get();
            }
        }

        while (carTypeChoice != 4);
    }
// Function to delete car to the rental system
    void deleteCar()
    {
        int carTypeChoice;
        do {
            system("cls");
            cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
            cout << "\t\t\t\t                   DELETE A CAR" << endl;
            cout << "\t\t\t\t*******************************************************" << endl;
            cout << "\n\t\t\t\tCar Categories" << endl;
            cout << "\n\t\t\t\t  1. Sedan";
            cout << "\n\t\t\t\t  2. SUV";
            cout << "\n\t\t\t\t  3. Truck";
            cout << "\n\t\t\t\t  4. Go Back";
            cout << "\n\n\t\t\t\tEnter Car Category: ";
            cin >> carTypeChoice;
            cout << endl;

            if (carTypeChoice != 4)
            {
                Node* carList = nullptr;

                switch (carTypeChoice)
                {
                case 1:
                    carList = sedanList;
                    break;
                case 2:
                    carList = suvList;
                    break;
                case 3:
                    carList = truckList;
                    break;
                default:
                    cout << "\n\t\t\t\tInvalid choice. Car not deleted." << endl;
                    getch();
                    break;
                }

                if (carList != nullptr)
                {
                    string carID;
                    cout << "\n\t\t\t\tEnter Car ID to Delete: ";
                    cin >> carID;

                    deleteCar(carList, carID);
                }

                else
                {
                    cout << "\n\t\t\t\tInvalid choice. Car not deleted." << endl;
                    getch();
                    return;
                }

                cout << "\n\t\t\t\tPress any key to continue...";
                cin.ignore();
                cin.get();
            }

        }

        while (carTypeChoice != 4);
    }

};
// Main function - starting point of the program
int main()
{
    system("COLOR 03");
    CarRental carRental;

    int choice;
    do
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t*******************************************************" << endl;
        cout << "\t\t\t\t                 CAR RENTAL SYSTEM" << endl;
        cout << "\t\t\t\t*******************************************************" << endl;
        cout << "\n\t\t\t\tMenu" << endl;
        cout << "\n\t\t\t\t  1. View Car List";
        cout << "\n\t\t\t\t  2. Issue Car";
        cout << "\n\t\t\t\t  3. Return Car";
        cout << "\n\t\t\t\t  4. Add Car";
        cout << "\n\t\t\t\t  5. Delete Car";
        cout << "\n\t\t\t\t  6. Exit";
        cout << "\n\n\t\t\t\tEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            carRental.viewCarList();
            break;
        case 2:
            carRental.issueCar();
            break;
        case 3:
            carRental.returnCar();
            break;
        case 4:
            carRental.addCar();
            break;
        case 5:
            carRental.deleteCar();
            break;
        case 6:
            cout << "\n\t\t\t\tThank you for using the car rental system. Goodbye!" << endl;
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice. Please try again." << endl;
            break;
        }

        cout << "\n\t\t\t\tPress any key to continue...";
        cin.ignore();
        cin.get();

    } while (choice != 6);

    return 0;
}

