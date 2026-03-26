#include <iostream>
#include <string>
#include <vector>
#include "math_utils.h"


class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    virtual ~Employee() {}

    virtual double calculatePay() const = 0;
    void updateDetails(std::string newName) {
        name = newName;
    }

    void updateDetails(std::string newName, int newId) {
        name = newName;
        id = newId;
    }

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << id;
    }
};

class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(std::string n, int i, double salary) : Employee(n, i), annualSalary(salary) {}

    double calculatePay() const override {
        return annualSalary / 12.0;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << " | Type: Salaried | Annual Salary: " << annualSalary
                  << " | Total Pay: " << calculatePay() << "\n";
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(std::string n, int i, double rate, double hours)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << " | Type: Hourly | Rate: " << hourlyRate << ", Hours: " << hoursWorked
                  << " | Total Pay: " << calculatePay() << "\n";
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string n, int i, double base, double sales, double rate)
        : Employee(n, i), baseSalary(base), salesAmount(sales), commissionRate(rate) {}

    double calculatePay() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << " | Type: Commission | Base: " << baseSalary
                  << ", Sales: " << salesAmount << ", Rate: " << commissionRate
                  << " | Total Pay: " << calculatePay() << "\n";
    }
};

int Aufgabe4() {
    std::cout << "\n--- Task 04: Static Polymorphism (Compile-time) ---\n";
    SalariedEmployee testEmp("Max Mustermann", 100, 60000.0);
    testEmp.displayInfo();

    testEmp.updateDetails("Max Müller");
    std::cout << "After updateDetails(string):\n";
    testEmp.displayInfo();

    testEmp.updateDetails("Maximilian Müller", 999);
    std::cout << "After updateDetails(string, int):\n";
    testEmp.displayInfo();

    std::cout << "\n--- Task 04: Dynamic Polymorphism (Runtime) ---\n";

    std::vector<Employee*> fleet;
    fleet.push_back(new SalariedEmployee("Alice", 101, 72000.0));
    fleet.push_back(new HourlyEmployee("Bob", 102, 25.50, 160.0));
    fleet.push_back(new CommissionEmployee("Charlie", 103, 2000.0, 15000.0, 0.10));

    for (Employee* emp : fleet) {

        emp->displayInfo();
    }

    for (Employee* emp : fleet) {
        delete emp;
    }
    fleet.clear();

    return 0;
}


class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width{w}, height{h} {}

    double getArea() {
        return width * height;
    }
};

void squareValue(int n)
{
    n = n * n;
}

void squareRef(int& n)
{
    n = n * n;
}

void updateScoreValue(int score)
{
    score += 100;
}

void updateScoreRef(int& score)
{
    score += 100;
}

void logMessage(const std::string& message)
{
    std::cout << "[LOG]: " << message << "\n";
}

int Aufgabe1a()
{
    int height{};
    std::cout << "Bitte Hoehe eingeben: ";
    std::cin >> height;

    for (int i{1}; i <= height; i++)
    {
        for (int j{1}; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

int Aufgabe1b()
{
    int height{};
    std::cout << "Bitte Hoehe eingeben: ";
    std::cin >> height;

    for (int i{1}; i <= height; i++)
    {
        for (int j{1}; j <= height - i; j++)
        {
            std::cout << " ";
        }

        for (int k{1}; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}

int Aufgabe1c()
{
    int height{};
    std::cout << "Bitte Hoehe eingeben: ";
    std::cin >> height;

    for (int i{1}; i <= height; i++)
    {
        for (int j{1}; j <= height - i; j++)
        {
            std::cout << " ";
        }
        for (int k{1}; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    for (int i = height - 1; i >= 1; i--)
    {
        for (int j{1}; j <= height - i; j++)
        {
            std::cout << " ";
        }
        for (int k{1}; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}

int Aufgabe2()
{
    double a{};
    double b{};
    std::cout << "Bitte a fuer ax + b eingeben: ";
    std::cin >> a;
    std::cout << "Bitte b fuer ax + b eingeben: ";
    std::cin >> b;

    if (a == 0)
    {
        std::cout << "Keine eindeutige Loesung.\n";
    }
    else
    {
        double x{ -b / a };

        std::cout << "Loesung:\n";
        std::cout << "x = " << x << "\n";
    }

    return 0;
}

int Alter()
{
    int age{};
    std::cout << "Bitte Alter eingeben oder stirb: ";
    std::cin >> age;

    if (age >= 18)
    {
        std::cout << "Du bist erwachsen\n";
    }
    else
    {
        std::cout << "Du bist ein Kind\n";
    }
    return 0;
}

int Aufgabe3Part1()
{
    int ergebnis = multiply(5, 4);
    std::cout << "5 * 4 = " << ergebnis << "\n";
    return 0;
}

int Aufgabe3Part2()
{
    int stackInt{10};
    int* heapInt = new int{20};

    int* ptr = heapInt;
    int& ref = stackInt;

    *ptr = 50;
    ref = 100;

    std::cout << "Stack Variable: " << stackInt << "\n";
    std::cout << "Heap Variable: " << *heapInt << "\n";

    delete heapInt;
    return 0;
}

int Aufgabe3Part3()
{
    int zahl{5};

    squareValue(zahl);
    std::cout << "Nach Wertaufruf (Kopie): " << zahl << "\n";

    squareRef(zahl);
    std::cout << "Nach Referenzaufruf (Original): " << zahl << "\n";

    return 0;
}

int Aufgabe3Part4()
{
    Rectangle stackRect{5.0, 4.0};
    Rectangle* heapRect = new Rectangle{10.0, 3.0};

    std::cout << "Flaeche Stack-Rechteck: " << stackRect.getArea() << "\n";
    std::cout << "Flaeche Heap-Rechteck: " << heapRect->getArea() << "\n";

    delete heapRect;
    return 0;
}

int main()
{
    int playerScore = 500;
    std::cout << "Startpunktzahl: " << playerScore << "\n";

    updateScoreValue(playerScore);
    std::cout << "Nach Wertaufruf: " << playerScore << "\n";

    updateScoreRef(playerScore);
    std::cout << "Nach Referenzaufruf: " << playerScore << "\n";

    logMessage("Uebung abgeschlossen");

    std::cout << "\n--- Tutorial 1 Aufgaben ---\n";
    Alter();
    std::cout << " \n";
    Aufgabe1a();
    std::cout << " \n";
    Aufgabe1b();
    std::cout << " \n";
    Aufgabe1c();
    std::cout << " \n";

    std::cout << " \n--- Tutorial 2 Aufgaben ---\n";
    Aufgabe2();

    std::cout << "\n--- Tutorial 3 Aufgaben ---\n";
    Aufgabe3Part1();
    std::cout << " \n";
    Aufgabe3Part2();
    std::cout << " \n";
    Aufgabe3Part3();
    std::cout << " \n";
    Aufgabe3Part4();
    std::cout << " \n";
    Aufgabe4();

    return 0;
}