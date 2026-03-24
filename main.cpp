#include <iostream>
#include <string>
#include "math_utils.h"

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

    std::cout << "\n--- Tutorial 1 & 2 Aufgaben ---\n";
    Alter();
    std::cout << " \n";
    Aufgabe1a();
    std::cout << " \n";
    Aufgabe1b();
    std::cout << " \n";
    Aufgabe1c();
    std::cout << " \n";
    Aufgabe2();

    std::cout << "\n--- Tutorial 3 Aufgaben ---\n";
    Aufgabe3Part1();
    std::cout << " \n";
    Aufgabe3Part2();
    std::cout << " \n";
    Aufgabe3Part3();
    std::cout << " \n";
    Aufgabe3Part4();

    return 0;
}