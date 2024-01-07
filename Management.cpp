#include "Employee.h"
#include <cstdlib> 
#include <iostream>
#include <algorithm>

// Function prototypes
void displayMenu();
void addEmployee(std::vector<Employee>& database);
void updateEmployee(std::vector<Employee>& database);
void deleteEmployee(std::vector<Employee>& database);

int main() {
    // Read employee data from a file (if exists)
    std::vector<Employee> employeeDatabase = readEmployeeData("employee_data.txt");

    int choice;
    do {
        // Clear the console screen
        system("clear");

        // Display the menu
        displayMenu();

        // Get user choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Perform the chosen operation
        switch (choice) {
            case 1:
                // Display all employees in the database
                std::cout << "\nEmployee Database:\n";
                for (const auto& employee : employeeDatabase) {
                    employee.displayDetails();
                }
                break;

            case 2:
                // Add a new employee
                addEmployee(employeeDatabase);
                break;

            case 3:
                // Update an existing employee
                updateEmployee(employeeDatabase);
                break;

            case 4:
                // Delete an employee
                deleteEmployee(employeeDatabase);
                break;

            case 5:
                // Save employee data to a file
                writeEmployeeData(employeeDatabase, "employee_data.txt");
                std::cout << "Employee data saved to 'employee_data.txt'.\n";
                break;

            case 6:
                // Exit the program
                std::cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        // Pause to allow the user to read the output
        std::cout << "Press Enter to continue...";
        std::cin.ignore(); // Ignore any previous newline character
        std::cin.get();    // Wait for Enter key

    } while (choice != 6);

    return 0;
}

void displayMenu() {
    std::cout << "Employee Database Management\n";
    std::cout << "1. Display all employees\n";
    std::cout << "2. Add a new employee\n";
    std::cout << "3. Update an existing employee\n";
    std::cout << "4. Delete an employee\n";
    std::cout << "5. Save employee data to a file\n";
    std::cout << "6. Exit\n";
}

void addEmployee(std::vector<Employee>& database) {
    std::string name;
    int employeeId;
    double salary;

    std::cout << "Enter employee name: ";
    std::cin.ignore(); // Ignore any previous newline character
    std::getline(std::cin, name);

    std::cout << "Enter employee ID: ";
    std::cin >> employeeId;

    std::cout << "Enter employee salary: ";
    std::cin >> salary;

    database.push_back(Employee(name, employeeId, salary));
    std::cout << "Employee added successfully.\n";
}

void updateEmployee(std::vector<Employee>& database) {
    int employeeId;
    std::cout << "Enter the employee ID to update: ";
    std::cin >> employeeId;

    for (auto& employee : database) {
        if (employee.getEmployeeId() == employeeId) {
            std::string newName;
            double newSalary;

            std::cout << "Enter the new name for the employee: ";
            std::cin.ignore(); // Ignore any previous newline character
            std::getline(std::cin, newName);

            std::cout << "Enter the new salary for the employee: ";
            std::cin >> newSalary;

            employee.setName(newName);
            employee.setSalary(newSalary);

            std::cout << "Employee updated successfully.\n";
            return;
        }
    }

    std::cout << "Employee not found.\n";
}

void deleteEmployee(std::vector<Employee>& database) {
    int employeeId;
    std::cout << "Enter the employee ID to delete: ";
    std::cin >> employeeId;

    auto it = std::remove_if(database.begin(), database.end(),
                             [employeeId](const Employee& e) { return e.getEmployeeId() == employeeId; });

    if (it != database.end()) {
        database.erase(it, database.end());
        std::cout << "Employee deleted successfully.\n";
    } else {
        std::cout << "Employee not found.\n";
    }
}
