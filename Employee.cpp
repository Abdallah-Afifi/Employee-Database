#include "Employee.h"

Employee::Employee(std::string name, int employeeId, double salary)
    : name(name), employeeId(employeeId), salary(salary) {}

void Employee::displayDetails() const {
    std::cout << "Employee ID: " << employeeId << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Salary: $" << salary << "\n";
    std::cout << "---------------------\n";
}

int Employee::getEmployeeId() const {
    return employeeId;
}

std::string Employee::getName() const {
    return name;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setName(const std::string& newName) {
    name = newName;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}

std::vector<Employee> readEmployeeData(const std::string& filename) {
    std::vector<Employee> employees;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return employees;
    }

    std::string name;
    int employeeId;
    double salary;

    while (inputFile >> employeeId >> name >> salary) {
        employees.push_back(Employee(name, employeeId, salary));
    }

    inputFile.close();
    return employees;
}

void writeEmployeeData(const std::vector<Employee>& employees, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    for (const auto& employee : employees) {
        outputFile << employee.getEmployeeId() << " "
                    << employee.getName() << " "
                    << employee.getSalary() << "\n";
    }

    outputFile.close();
}
