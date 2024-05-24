
#include <iostream>
#include <string>
using namespace std;

// Employee Class Declaration

class Employee
{
private:
    string name;        // Employee's name
    int idNumber;       // ID number
    string department;  // Department name
    string position;    // Employee's position

public:
    // Constructors
    Employee(string, int, string, string);
    Employee();

    // update methods
    void setName(string n)
    {
        name = n;
    }

    void setIdNumber(int i)
    {
        idNumber = i;
    }

    void setDepartment(string d)
    {
        department = d;
    }

    void setPosition(string p)
    {
        position = p;
    }

    // Accessors
    string getName()
    {
        return name;
    }

    int getIdNumber()
    {
        return idNumber;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }
};

// Constructor #1
Employee::Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

// Constructor #3, default constructor
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}


// Function prototype
void displayEmployee(Employee);

void displayEmployee(Employee e)
{
    cout << "Name: " << e.getName() << endl;
    cout << "ID Number: " << e.getIdNumber() << endl;
    cout << "Department: " << e.getDepartment() << endl;
    cout << "Position: " << e.getPosition() << endl << endl;
}

int findEmployeeById(Employee arr[], int numEmployees, int idToFind)
{
    for (int i = 0; i < numEmployees; ++i)
    {
        if (arr[i].getIdNumber() == idToFind)
        {
            return i; // Return the index of the employee if found
        }
    }
    return -1; // Return -1 if the employee is not found
}

void addEmployee(Employee arr[], int& numEmployees)
{
    if (numEmployees < 10)
    {
        cout << "Enter employee details:\n";
        string name, department, position;
        int idNumber;

        cout << "Name: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, name);

        cout << "ID Number: ";
        cin >> idNumber;

        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        cout << "Position: ";
        getline(cin, position);

        arr[numEmployees] = Employee(name, idNumber, department, position);
        numEmployees++;
        cout << "Employee added successfully.\n";
    }
    else
    {
        cout << "Employee database is full. Cannot add more employees.\n";
    }
}

void deleteEmployee(Employee arr[], int& numEmployees)
{
    if (numEmployees > 0)
    {
        cout << "Enter the index of the employee to delete: ";
        int indexToDelete;
        cin >> indexToDelete;

        if (indexToDelete >= 0 && indexToDelete < numEmployees)
        {
            // Shift the array elements to remove the employee at the specified index
            for (int i = indexToDelete; i < numEmployees - 1; ++i)
            {
                arr[i] = arr[i + 1];
            }

            numEmployees--;
            cout << "Employee deleted successfully.\n";
        }
        else
        {
            cout << "Invalid index. Please enter a valid index.\n";
        }
    }
    else
    {
        cout << "No employees to delete.\n";
    }
}  

// Driver program to demonstrate the class
int main()
{
    const int MAX_EMPLOYEES = 10;
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    int index; // Declare the index variable outside the switch statement

    while (true)
    {
        cout << "   Employee Record Daatabase\n";
        cout << "---------------------------------\n";
        cout << "1. Display Employee\n";
        cout << "2. Add Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        

        int choice;
        cin >> choice;
        cout << "---------------------------------\n";
        switch (choice)
        {
        case 1:
            // Display Employee
            cout << "Enter employee ID: ";
            int idToDisplay;
            cin >> idToDisplay;
            index = findEmployeeById(employees, numEmployees, idToDisplay);
            if (index != -1)
            {
                displayEmployee(employees[index]);
            }
            else
            {
                cout << "Employee not found.\n";
            }
            break;

        case 2:
            // Add Employee
            addEmployee(employees, numEmployees);
            break;

        case 3:
            // Delete Employee
            deleteEmployee(employees, numEmployees);
            break;

        case 4:
            // Exit
            return 0;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    }
}


