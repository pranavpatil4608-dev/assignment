
#include <iostream>
#include <fstream>
using namespace std;

void addStudent()
{
    ofstream fout("StudentData.txt", ios::app);

    int roll;
    char name[30], division[10], address[50];

    cout << "Enter Roll Number: ";
    cin >> roll;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Division: ";
    cin >> division;

    cout << "Enter Address: ";
    cin >> address;

    fout << roll << " " << name << " "
         << division << " " << address << endl;

    fout.close();

    cout << "Record Added Successfully!\n";
}

void searchStudent()
{
    ifstream fin("StudentData.txt");

    int roll, key;
    char name[30], division[10], address[50];
    int found = 0;

    cout << "Enter Roll Number to Search: ";
    cin >> key;

    while (fin >> roll >> name >> division >> address)
    {
        if (roll == key)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll: " << roll << endl;
            cout << "Name: " << name << endl;
            cout << "Division: " << division << endl;
            cout << "Address: " << address << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "Student Not Found!\n";

    fin.close();
}

void deleteStudent()
{
    ifstream fin("StudentData.txt");
    ofstream fout("Temp.txt");

    int roll, key;
    char name[30], division[10], address[50];
    int found = 0;

    cout << "Enter Roll Number to Delete: ";
    cin >> key;

    while (fin >> roll >> name >> division >> address)
    {
        if (roll == key)
        {
            found = 1;
        }
        else
        {
            fout << roll << " " << name << " "
                 << division << " " << address << endl;
        }
    }

    fin.close();
    fout.close();

    ifstream temp("Temp.txt");
    ofstream original("StudentData.txt");

    char ch;
    while (temp.get(ch))
    {
        original.put(ch);
    }

    temp.close();
    original.close();

    if (found == 1)
        cout << "Record Deleted Successfully!\n";
    else
        cout << "Student Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- STUDENT DATABASE ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                deleteStudent();
                break;

            case 4:
                cout << "Program Ended.";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
