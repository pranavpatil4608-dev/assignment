
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    float sgpa;
};

void display(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << s[i].roll << " "
             << s[i].name << " "
             << s[i].sgpa << endl;
    }
}

void bubbleSort(Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by Roll Number:\n";
    display(s, n);
}

void insertionSort(Student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].name > key.name)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }

    cout << "\nSorted Alphabetically:\n";
    display(s, n);
}

void linearSearch(Student s[], int n)
{
    float key;
    int found = 0;

    cout << "Enter SGPA: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa == key)
        {
            cout << s[i].roll << " "
                 << s[i].name << " "
                 << s[i].sgpa << endl;

            found = 1;
        }
    }

    if (found == 0)
        cout << "Student Not Found";
}

void binarySearch(Student s[], int n)
{
    string key;
    int low = 0, high = n - 1;
    int found = 0;

    cout << "Enter Name: ";
    cin >> key;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (s[mid].name == key)
        {
            cout << "\nStudent Found:\n";
            cout << s[mid].roll << " "
                 << s[mid].name << " "
                 << s[mid].sgpa << endl;

            found = 1;
            break;
        }
        else if (s[mid].name < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found == 0)
        cout << "Student Not Found";
}

int main()
{
    Student s[100];
    int n, choice;

    cout << "Enter number of students: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of students";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Roll Number: ";
        cin >> s[i].roll;

        cout << "Enter Name: ";
        cin >> s[i].name;

        cout << "Enter SGPA: ";
        cin >> s[i].sgpa;
    }

    do
    {
        cout << "\n--- STUDENT DATABASE ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Students\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bubbleSort(s, n);
                break;

            case 2:
                insertionSort(s, n);
                break;

            case 3:
                linearSearch(s, n);
                break;

            case 4:
                insertionSort(s, n);
                binarySearch(s, n);
                break;

            case 5:
                display(s, n);
                break;

            case 0:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while (choice != 0);

    return 0;
}
