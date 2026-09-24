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

    string getColor()
    {
        return color;
    }

    void setArea(float a)
    {
        area = a;
    }

    float getArea()
    {
        return area;
    }

    virtual void calculateArea() = 0;
    virtual void display() = 0;

    virtual ~Shape()
    {
    }
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

    void display() override
    {
        cout << "\n--- Circle ---" << endl;
        cout << "Color : " << getColor() << endl;
        cout << "Radius : " << radius << endl;
        cout << "Area : " << getArea() << endl;
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

    void display() override
    {
        cout << "\n--- Rectangle ---" << endl;
        cout << "Color : " << getColor() << endl;
        cout << "Length : " << length << endl;
        cout << "Width : " << width << endl;
        cout << "Area : " << getArea() << endl;
    }
};

int main()
{
    int n, choice;
    string color;

    cout << "Enter number of shapes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of shapes." << endl;
        return 0;
    }

    Shape **shapes = new Shape *[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nShape " << i + 1 << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int radius;

            cout << "Enter Color: ";
            getline(cin >> ws, color);

            cout << "Enter Radius: ";
            cin >> radius;

            shapes[i] = new Circle(color, radius);
        }
        else if (choice == 2)
        {
            int length, width;

            cout << "Enter Color: ";
            getline(cin >> ws, color);

            cout << "Enter Length: ";
            cin >> length;

            cout << "Enter Width: ";
            cin >> width;

            shapes[i] = new Rectangle(color, length, width);
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
            i--;
        }
    }

    cout << "\n===== SHAPE INFORMATION =====" << endl;

    for (int i = 0; i < n; i++)
    {
        shapes[i]->calculateArea();
        shapes[i]->display();
    }

    for (int i = 0; i < n; i++)
    {
        delete shapes[i];
    }
    
    delete[] shapes;
    return 0;
}