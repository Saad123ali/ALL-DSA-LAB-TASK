/* Write a C++ program that has a Polygon interface that has abstract functions, area(), and perimeter(). Implement classes for Triangle, Quadrilateral, Pentagon, Hexagon, and Octagon, which implement this interface, with the obvious meanings for the area() and perimeter() functions. Also implement classes, IsoscelesTriangle, EquilateralTriangle, Rectangle, and Square, which have the appropriate inheritance relationships. Finally, write a simple user interface that allows users to create polygons of the various types, input their geometric dimensions, and then output their area and perimeter. For extra effort, allow users to input polygons by specifying their vertex coordinates and be able to test if two such polygons are similar.  */
#include <iostream>
#include <cmath>
using namespace std;

class Polygon
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Triangle : public Polygon
{
protected:
    double side1, side2, side3;

public:
    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}

    double area() const override
    {
        double s = perimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override
    {
        return side1 + side2 + side3;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double base, double equalSide) : Triangle(equalSide, equalSide, base) {}
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}
};

class Quadrilateral : public Polygon
{
protected:
    double side1, side2, side3, side4;

public:
    Quadrilateral(double side1, double side2, double side3, double side4) : side1(side1), side2(side2), side3(side3), side4(side4) {}

    double perimeter() const override
    {
        return side1 + side2 + side3 + side4;
    }
};

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double length, double width) : Quadrilateral(length, width, length, width) {}

    double area() const override
    {
        return side1 * side2;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}
};

class Pentagon : public Polygon
{
private:
    double side;

public:
    Pentagon(double side) : side(side) {}

    double area() const override
    {
        return (5 * side * side) / (4 * tan(M_PI / 5));
    }

    double perimeter() const override
    {
        return 5 * side;
    }
};

class Hexagon : public Polygon
{
private:
    double side;

public:
    Hexagon(double side) : side(side) {}

    double area() const override
    {
        return (3 * sqrt(3) * side * side) / 2;
    }

    double perimeter() const override
    {
        return 6 * side;
    }
};

class Octagon : public Polygon
{
private:
    double side;

public:
    Octagon(double side) : side(side) {}

    double area() const override
    {
        return 2 * (1 + sqrt(2)) * side * side;
    }

    double perimeter() const override
    {
        return 8 * side;
    }
};

int main()
{
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\nPolygon Menu:\n";
        cout << "1. Triangle\n";
        cout << "2. Isosceles Triangle\n";
        cout << "3. Equilateral Triangle\n";
        cout << "4. Rectangle\n";
        cout << "5. Square\n";
        cout << "6. Pentagon\n";
        cout << "7. Hexagon\n";
        cout << "8. Octagon\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 9)
            break;

        Polygon* polygon = nullptr;

        if (choice == 1)
        {
            double side1, side2, side3;
            cout << "Enter the three sides of the triangle: ";
            cin >> side1 >> side2 >> side3;
            polygon = new Triangle(side1, side2, side3);
        }
        else if (choice == 2)
        {
            double base, equalSide;
            cout << "Enter base & equal side of the Isosceles Triangle: ";
            cin >> base >> equalSide;
            polygon = new IsoscelesTriangle(base, equalSide);
        }
        else if (choice == 3)
        {
            double side;
            cout << "Enter side of the Equilateral Triangle: ";
            cin >> side;
            polygon = new EquilateralTriangle(side);
        }
        else if (choice == 4)
        {
            double length, width;
            cout << "Enter length and width of the rectangle: ";
            cin >> length >> width;
            polygon = new Rectangle(length, width);
        }
        else if (choice == 5)
        {
            double side;
            cout << "Enter side of the square: ";
            cin >> side;
            polygon = new Square(side);
        }
        else if (choice == 6)
        {
            double side;
            cout << "Enter side of the pentagon: ";
            cin >> side;
            polygon = new Pentagon(side);
        }
        else if (choice == 7)
        {
            double side;
            cout << "Enter side of the hexagon: ";
            cin >> side;
            polygon = new Hexagon(side);
        }
        else if (choice == 8)
        {
            double side;
            cout << "Enter side of the octagon: ";
            cin >> side;
            polygon = new Octagon(side);
        }
        else
        {
            cout << "Invalid choice!\n";
            continue; // Skip to the next iteration if choice is invalid
        }

        cout << "Area: " << polygon->area() << endl;
        cout << "Perimeter: " << polygon->perimeter() << endl;
        delete polygon;
    }



    return 0;
}


/* ALl Formulas use in this Program

1. Triangle with three sides => side1 , side2 , side3

semi-perimeter  =>  s = (side1+side2+side3)/2
Area => sqrt(s* (s-side1) *(s - side2) *(s - side3))
perimeter => side1 + side2 + side3

2. Isosceles tirangle with 2 equal sieds and base

primeter of isosceles => 2 * equlaside + base

area => area sqrt(s* (s - equalside) * (s- equalside) * (s- base))

3. Equilateral triangle with all equal sieds equal

area =>  area = sqrt(3) * side^2 / 4
perimeter => perimeter = 3 * side

4. Quadrilateral  with 4 sides = side1 , side2 , side3 , side4

perimeter => perimeter = side1 + side2 + side3 + side4

5. Rectangle with lenght and width

area => area = lenght * width
perimeter => perimeter = 2 * (lenght + width)

6. square with equal sides

area => area = side^2
perimeter => perimeter = 4 * side

7. Pentagon with side lenght
area => area = 5 * side^2 / 4 * tan(pi / 5)
perimeter => perimeter = 5 * side

8. Hexagon with side length
area => area = 3 sqrt(3)/ side^2 / 2
Perimeter => perimeter = 6 * side

9. Octagon with side length
area => area = 2 * (1 + sqrt(2)) / side^2
perimeter => perimeter = 8 * side


*/