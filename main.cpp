#include <iostream>

int Aufgabe1a()
{
    int height;
    std::cout << "Enter height: ";
    std::cin >> height;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

int Aufgabe1b()
{
    int height;
    std::cout << "Enter height: ";
    std::cin >> height;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            std::cout << " ";
        }

        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}

int Aufgabe1c()
{
    int height;
    std::cout << "Enter height: ";
    std::cin >> height;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    for (int i = height - 1; i >= 1; i--)
    {
        for (int j = 1; j <= height - i; j++)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}

int Aufgabe2()
{
    float a, b;
    std::cout << "Enter a for ax + b: ";
    std::cin >> a;
    std::cout << "Enter b for ax + b: ";
    std::cin >> b;

    if (a == 0)
    {
        std::cout << "No unique solution.\n";
    }
    else
    {
        float x = -b / a;

        std::cout << "Solution:\n";
        std::cout << "x = " << x << "\n";
    }

    return 0;
}

int Alter()
{
    int age;
    std::cout << "Enter your age or die: ";
    std::cin >> age;

    if (age >= 18)
    {
        std::cout << "You are an Adult" << std::endl;
    }
    else
    {
        std::cout << "You are a Child" << std::endl;
    }
    return 0;
}

int main()
{
    Alter();
    std::cout << " \n";
    Aufgabe1a();
    std::cout << " \n";
    Aufgabe1b();
    std::cout << " \n";
    Aufgabe1c();
    std::cout << " \n";
    Aufgabe2();
    return 0;
}
