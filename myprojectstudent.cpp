 #include <iostream>
#include <string>
using namespace std;

struct Student
{
    string roll_number;
    string name;
    string dob;
    string fathername;
    string mothername;
    string contactnumber;
    string address;
    string city;
    Student* next;
};

Student* head = NULL;
Student* tail = NULL;

void addStudent()
{
    cin.ignore();
    Student* temp = new Student;

    cout << "\nEnter roll number of the student: ";
    getline(cin, temp->roll_number);

    cout << "\nEnter name of the student: ";
    getline(cin, temp->name);

    cout << "\nEnter DOB (MM/DD/YYYY): ";
    getline(cin, temp->dob);

    cout << "\nEnter father name: ";
    getline(cin, temp->fathername);

    cout << "\nEnter mother name: ";
    getline(cin, temp->mothername);

    cout << "\nEnter contact no: ";
    getline(cin, temp->contactnumber);

    cout << "\nEnter address: ";
    getline(cin, temp->address);

    cout << "\nEnter city: ";
    getline(cin, temp->city);

    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void displayAllStudents()
{
    Student* temp = head;

    if (temp == NULL)
        cout << "\nNo students in the list\n";
    else
    {
        cout << "\nList of students:\n";
        while (temp != NULL)
        {
            cout << temp->roll_number << "\t" << temp->name << "\n";
            temp = temp->next;
        }
    }
}

void displayAllStudentsdata()
{
    Student *temp = head;

    if(head == NULL)
        cout << "\nNo record: Linked list empty!!";
    else
    {
        while(temp != NULL)
        {
            cout << "\nRoll No : " << temp->roll_number;
            cout << "\nName : " << temp->name;
            cout << "\nDOB : " << temp->dob;
            cout << "\nFather name : " << temp->fathername;
            cout << "\nMother name : " << temp->mothername;
            cout << "\nContact no : " << temp->contactnumber;
            cout << "\nAddress : " << temp->address;
            temp = temp->next;
            if(temp != NULL)
            {
                cout << "\n-----------------------------------------";
                cout << "\nPress enter key for the next record..";
                cin.get();
            }
        }
    }
}

void displayStudentsFromCity()
{
    string city;
    cout << "\nEnter city name to display students from: ";
    cin >> city;

    Student* temp = head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->city == city)
        {
            cout << "\n" << temp->name << " is from " << city;
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "\nNo students found from " << city;
}

void deleteAllStudent()
{
    Student* temp = head;

    while (temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    tail = NULL;
}

void sortRollNumber()
{
    bool swapped;
    Student* ptr1 = head;
    Student* lptr = NULL;
/* Checking for empty list */
if(head == NULL) 
   return;

do
{
    swapped = false;
    ptr1 = head;

    while (ptr1->next != lptr)
    {
        if (ptr1->roll_number > ptr1->next->roll_number)
        {
            swap(ptr1->roll_number, ptr1->next->roll_number);
            swap(ptr1->name, ptr1->next->name);
            swap(ptr1->dob, ptr1->next->dob);
            swap(ptr1->fathername, ptr1->next->fathername);
            swap(ptr1->mothername, ptr1->next->mothername);
            swap(ptr1->contactnumber, ptr1->next->contactnumber);
            swap(ptr1->address, ptr1->next->address);
            swap(ptr1->city, ptr1->next->city);
            swapped = true;
        }
        ptr1 = ptr1->next;
    }
    lptr = ptr1;
} while (swapped);
}

int main()
{
int choice;
do
{
cout << "\n\nMenu:\n";
cout << "1. Add student\n";
cout << "2. Display all students\n";
cout << "3. Display all student data\n";
cout << "4. Display students from a city\n";
cout << "5. Delete all students\n";
cout << "6. Sort students by roll number\n";
cout << "7. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

    switch (choice)
    {
    case 1:
        addStudent();
        break;
    case 2:
        displayAllStudents();
        break;
    case 3:
        displayAllStudentsdata();
        break;
    case 4:
        displayStudentsFromCity();
        break;
    case 5:
        deleteAllStudent();
        break;
    case 6:
        sortRollNumber();
        break;
    case 7:
        deleteAllStudent();
        cout << "\nThank you for using the program!\n";
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
    }

} while (choice != 7);

return 0;
}
   
        




