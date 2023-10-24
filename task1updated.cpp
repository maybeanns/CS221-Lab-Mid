/*
    main task: 1.patient class
               2. waitlist class including:-
                  (i) find patient by name
                  (ii) call the patient and remove his name
                  (iii) enter new patients data
*/

#include <iostream>
using namespace std;

class patient // class  for patients data
{
public:
    string name;
    int age;
    int prty;
    patient *next;

    patient(string s = "", int a = 0, int p = 0) : name(s), age(a), prty(p), next(nullptr) {}
};

class waitinglist // class for the registrars
{
public:
    patient *head;

    waitinglist() : head(nullptr) {}

    void insert(string s, int a, int p)
    {
        patient *newpt = new patient(s, a, p);
        if (!head)
        {
            head = newpt;
        }
        else
        {
            newpt->next = head;
            head = newpt;
        }
    }

     bool calling()
    {
        if (!head)
        {
            cout << "No patients in the list." << endl;
            return false;
        }
        
        cout << "Calling patient: " << head->name << " (Priority: " << head->prty << ")" << endl;
        patient* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
};

void findPatientByName(waitinglist &list, string n1)
{
    patient *find1 = list.head;
    while (find1)
    {
        if (find1->name == n1)
        {
            cout << "Name: " << find1->name << endl;
            cout << "Age: " << find1->age << endl;
            cout << "Priority: " << find1->prty << endl;
            return;
        }
        find1 = find1->next;
    }
    cout << "Patient not found." << endl;
}

int main()
{
    waitinglist p1;
    string name;
    int age, prior;
    char n;
    string x;

    do
    {
        cout << "1. Enter new patient" << endl;
        cout << "2. Call the patient" << endl;
        cout << "3. Find the patient by name" << endl;
        cout << "4. Exit" << endl; // Remove exclamation mark

        cin >> n;
        cin.ignore(); // Add this to consume the newline character

        switch (n)
        {
        case '1':
            cout << "Enter name of patient: ";
            getline(cin, name);
            cout << "Enter age of patient: ";
            cin >> age;
            cout << "Enter priority of the patient: ";
            cin >> prior;
            cin.ignore(); // Add this to consume the newline character
            p1.insert(name, age, prior);
            break;

        case '2':
            cout << "Calling patient on the basis of their priority: "<<endl;
            
            if (p1.calling())
            {
                cout << "Patient called and removed from the list." << endl;
            }
            else
            {
                cout << "Patient not found in the list." << endl;
            }
            break;

        case '3':
            cout << "Enter the name of the patient: ";
            getline(cin, x); // Use getline to read names with spaces
            findPatientByName(p1, x);
            break;

        default:
            if (n != '4') // Avoid printing "Try again" when the user exits
                cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (n != '4'); // Exit when '4' is selected

    return 0;
}
