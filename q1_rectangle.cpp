#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    void setLength(int l)
    {
        length = l;
    }

    void setWidth(int w)
    {
        width = w;
    }

    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int area()
    {
        return length * width;
    }
};

int main()
{
    Rectangle r(10, 5);

    cout << "Length : " << r.getLength() << endl;
    cout << "Width : " << r.getWidth() << endl;
    cout << "Area : " << r.area() << endl;

    r.setLength(20);
    r.setWidth(10);

    cout << "\nAfter changing values:" << endl;
    cout << "Length : " << r.getLength() << endl;
    cout << "Width : " << r.getWidth() << endl;
    cout << "Area : " << r.area() << endl;

    return 0;
}