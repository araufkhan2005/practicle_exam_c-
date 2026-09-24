#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;
    float area;

public:
    Shape(string c, float a)
    {
        color = c;
        area = a;
    }

    void setColor(string c)
    {
        color = c;
    }

    void setArea(float a)
    {
        area = a;
    }

    string getColor()
    {
        return color;
    }

    float getArea()
    {
        return area;
    }

    virtual void calculateArea() = 0;
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(string c, int r) : Shape(c, 0)
    {
        radius = r;
    }

    void calculateArea() override
    {
        setArea(3.14f * radius * radius);
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(string c, int l, int w) : Shape(c, 0)
    {
        length = l;
        width = w;
    }

    void calculateArea() override
    {
        setArea(length * width);
    }
};

int main()
{
    Circle c("Red", 5);
    c.calculateArea();

    cout << "Circle Color : " << c.getColor() << endl;
    cout << "Circle Area : " << c.getArea() << endl;

    Rectangle r("Blue", 10, 5);
    r.calculateArea();

    cout << "\nRectangle Color : " << r.getColor() << endl;
    cout << "Rectangle Area : " << r.getArea() << endl;
    return 0;
}