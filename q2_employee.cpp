#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int salary;
    string designation;

public:
    Employee(string n, int s, string d)
    {
        name = n;
        salary = s;
        designation = d;
    }

    void setName(string n)
    {
        name = n;
    }

    void setSalary(int s)
    {
        salary = s;
    }

    void setDesignation(string d)
    {
        designation = d;
    }

    string getName()
    {
        return name;
    }

    int getSalary()
    {
        return salary;
    }

    string getDesignation()
    {
        return designation;
    }
};

int main()
{
    int n;
    string name, designation;
    int salary;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Employee " << i + 1 << " Details:" << endl;

        cout << "Enter Name: ";
        getline(cin >> ws, name);

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Enter Designation: ";
        getline(cin >> ws, designation);

        Employee e("", 0, "");

        e.setName(name);
        e.setSalary(salary);
        e.setDesignation(designation);

        cout << "\nEmployee " << i + 1 << " Information:" << endl;
        cout << "Name : " << e.getName() << endl;
        cout << "Salary : " << e.getSalary() << endl;
        cout << "Designation : " << e.getDesignation() << endl;
    }

    return 0;
}