/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                 POLYMORPHISM
*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:

    virtual void Area() = 0;
    virtual void Perimeter() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    // Circle(){
    //     cout<<"Object of class circle is initialised"<<endl;
    // }
    void Circle_dimension()
    {
        cout << "\n\n1. DERIVED CLASS CIRCLE FOR CALCULATING AREA AND PERIMETER\n"
             << endl;
        
        cout << "Enter the Radius of the Circle = ";
        cin >> radius;
        cout << endl;
    }

    void Area()
    {
        cout << "The Area of the Circle is = "<< M_PI * radius * radius << endl;
            
    }

    void Perimeter()
    {
        cout << "The Perimeter of the Circle is = " << 2 * M_PI * radius << endl;
            
    }
};

class Rectangle : public Shape
{

private:
    float length;
    float breadth;

public:
// Rectangle(){
//     cout<<"Object of class Rectangle is initialised"<<endl;
// }
    void Rectangle_dimension()
    {
        cout << "\n\n2. DERIVED CLASS RECTANGLE FOR CALCULATING AREA AND PERIMETER\n"
             << endl;
        cout << "Enter the Length of the Rectangle = ";
        cin >> length;
        cout << "\nEnter the Breadth of the Rectangle = ";
        cin >> breadth;
        cout << endl;
    }

    void Area()
    {
        cout << "The Area of the Rectangle is = "<< length * breadth << endl;
    }

    void Perimeter()
    {
        cout << "The Perimeter of the Rectangle is = " << 2 * (length + breadth) << endl;
        
    }
};

class Square : public Shape
{

private:
    float side;

public:
// Square(){
//     cout<<"Object of class Square is initialised"<<endl;
// }
//     void Square_dimension()
    {
        cout << "\n\n3. DERIVED CLASS SHAPE FOR CALCULATING AREA AND PERIMETER\n"
             << endl;
        cout << "Enter the Side of the Square = ";
        cin >> side;
        cout << endl;
    }

    void Area()
    {
        cout << "The Area of the Square is = " << side * side << endl;
    }

    void Perimeter()
    {
        cout << "The Perimeter of the Square is = " << 4 * side << endl;
    }
};

class Triangle : public Shape
{

private:
    float side_1;
    float side_2;
    float base;
    float height_b;

public:
    // Triangle(){
    //     cout<<"Object of class Triangle is initialised"<<endl;
    // }
    void Triangle_dimension()
    {
        cout << "\n\n4.DERIVED CLASS TRIANGLE FOR CALCULATING AREA AND PERIMETER\n"
             << endl;
        cout << "Enter the first  of the Triangle = ";
        cin >> side_1;
        cout << "\nEnter the second of the Triangle = ";
        cin >> side_2;
        cout << "\nEnter the base of the Triangle = ";
        cin >> base;
        cout << "\nEnter the height of the Triangle = ";
        cin >> height_b;
        cout << endl;
    }

    void Area()
    {
        cout << "The Area of the Triangle is = " <<(0.5 * base * height_b) <<endl;
    }

    void Perimeter()
    {
        cout << "The Perimeter of the Triangle is = "<< side_1 + side_2 + base << endl;
    }
};
int main()
{
    int ch = 0;
    Circle Circle1;
    Rectangle rect1;
    Square sqr1;
    Triangle tri1;
     while (1)
    {
        cout << "\n\tMenu"<<endl
             << "1.Circle" << endl
             << "2.Rectangle" << endl
             << "3.Square" << endl
             << "4.Triangle" << endl
             << "5.Exit" << endl;
        cout << "Enter your choice to choose Shape : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        
            Circle1.Circle_dimension();
            Circle1.Area();
            Circle1.Perimeter();
            break;
        case 2:
            rect1.Rectangle_dimension();
            rect1.Area();
            rect1.Perimeter();
            break;
        case 3:
            sqr1.Square_dimension();
            sqr1.Area();
            sqr1.Perimeter();
            break;
        case 4:
            tri1.Triangle_dimension();
            tri1.Area();
            tri1.Perimeter();
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Please enter valid choice " << endl;
            break;
        }
    }
    return 0;
}