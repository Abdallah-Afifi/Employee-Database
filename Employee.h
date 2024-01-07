#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Employee {
public:
    Employee(std::string name, int employeeId, double salary);
    
    void displayDetails() const;
    
    // Getter functions
    int getEmployeeId() const;
    std::string getName() const;
    double getSalary() const;

    // Setter functions
    void setName(const std::string& name);
    void setSalary(double salary);

private:
    std::string name;
    int employeeId;
    double salary;
};

// Function to read employee data from a file
std::vector<Employee> readEmployeeData(const std::string& filename);

// Function to write employee data to a file
void writeEmployeeData(const std::vector<Employee>& employees, const std::string& filename);

#endif // EMPLOYEE_H
