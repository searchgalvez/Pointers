// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum EnumColorDefinition {White, Red};

struct Car
{
    char make[32];
    char model[32];
    int year;
    int mileage;
    EnumColorDefinition color;
};

void program1();
void program2(int x, int* pointer);
void repaintCar(Car* ptrCar, EnumColorDefinition newcolor);
void printCar(Car c);
void printCarPointer(Car* ptrCar);
void addMileage(Car* ptrCar, int milestoadd);

int main()
{
    std::cout << "Program 1" << std::endl;
    program1();

    std::cout << "Program 2" << std::endl;
    srand(time(0));

    int array2[15];
    for (int i = 0; i < 15; i++)
    {
        array2[i] = rand() / 7;
    }
    for (int i = 0; i < 15; i++)
    {
        program2(array2[i], &array2[i]);
    }

    std::cout << "\nProgram 3" << std::endl;
    std::cout << "\nPart 1" << std::endl;
    Car car[3];
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nPlease enter your car information\n" << "Car # " << i + 1 << std::endl;
        
        std::cout << "Enter Car Make: ";
        std::cin >> car[i].make;
        std::cin.getline(car[i].make, 32);
        std::cin.clear();

        std::cout << "Enter Car Model: ";
        std::cin >> car[i].model;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        std::cout << "Enter Car Year: ";
        std::cin >> car[i].year;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cin.clear();

        std::cout << "Enter Car Mileage: ";
        std::cin >> car[i].mileage;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        int colorinput;
        std::cout << "Car color:1) White \n\t  2) Red:\n Enter color: ";
        std::cin >> colorinput;
        std::cin.clear();

        std::cin.ignore(INT_MAX, '\n');
        car[i].color = (EnumColorDefinition)colorinput;

        switch (colorinput)
        {
        case EnumColorDefinition::White:
        {
            std::cout << "\t White\n" << std::endl;
        }
        case EnumColorDefinition::Red:
        {
            std::cout << "\t Red" << std::endl;
        }
        std::cout << std::endl;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nCar " << i + 1 << "_";
        std::cout << car[i].year << " ";
        switch (car[i].color)
        {
        case EnumColorDefinition::White:
        {
            std::cout << "White ";
            break;
        }
        case EnumColorDefinition::Red:
        {
            std::cout << "Red ";
            break;
        }
        }
        std::cout << car[i].make << " ";
        std::cout << car[i].model << " with ";
        std::cout << car[i].mileage << " miles ";
    }
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    std::cout << "Part 2" << std::endl;
    
    int carNumber;
    //std::count << std::endl;
    std::cout << "Enter which car you would like to repaint: (Car: 1, 2, 3) ";
    std::cin >> carNumber;
    int colorChoice;
    std::cout << "Choose a new color for the car:" << std::endl;
    std::cout << "Color 1: White \n\t  2: Red\n Enter Color:";
    std::cin >> colorChoice;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    switch (colorChoice)
    {
    case EnumColorDefinition::White:
    {
        repaintCar(car, White);
        break;
    }
    case EnumColorDefinition::Red:
    {
        repaintCar(car, Red);
        break;
    }
    std::cout << std::endl;
    }
    
    
    std::cout << "\nPart 3" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nCar " << (i + 1) << "-";
        printCar(car[i]);
    }
    std::cout << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nCar " << (i + 1) << "-";
        printCarPointer(&car[i]);
    }

    std::cout << "\nProgram 4" << std::endl;
    std::cout << "\nChanging mileage" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        addMileage(&car[i], 267);
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nCar " << (i + 1) << "-";
        printCar(car[i]);
    }
    std::cout << std::endl;


}
void program1()
{
    srand(time(0));
                    
    int ofarray[15];for (int i = 0; i < 15; i++)
        {
        ofarray[i] = rand() / 7; 
        }
    for (int i = 0; i < 15; i++)
    {
        std::cout << "Value:" << ofarray[i];
        std::cout << "\tAddress: " << &ofarray[i] << std::endl;
    }
}
    
void program2(int x, int* pointer)
{
    std::cout << "value: " << x;
    std::cout << "\t Address; " << pointer << std::endl;
}
void repaintCar(Car* ptrCar, EnumColorDefinition newcolor)
{
    (*ptrCar).color = newcolor;
}
void printCar(Car c)
{
    std::cout << c.year << " ";
    char color[12] = "White";
    if (c.color == 1)
    {
        strcpy_s(color, "Red");
    }
    std::cout << color << " ";
    std::cout << c.make << " ";
    std::cout << c.model << " with ";
    std::cout << c.mileage << " miles ";
}
void printCarPointer(Car* ptrCar)
{
    std::cout << (*ptrCar).year << " ";
    char color[12] = "White";
    if ((*ptrCar).color == 1)
    {
        strcpy_s(color, "White");
    }
    std::cout << color << " ";
    std::cout << (*ptrCar).make << " ";
    std::cout << (*ptrCar).model << "with";
    std::cout << (*ptrCar).mileage << "miles";
}
void addMileage(Car* ptrCar, int milestoadd)
{
    (*ptrCar).mileage = milestoadd;
}