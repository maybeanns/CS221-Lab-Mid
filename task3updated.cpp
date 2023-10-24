#include <iostream>
using namespace std;

class Customer
{
public:
    string name;
    int n;
    Customer() {}
    ~Customer() {}
};

class CheckoutQueue
{
public:
    int front, rear, len;
    Customer queue[100];
    CheckoutQueue(/* args */)
    {
        rear = -1;
        front = -1;
    }

    void enqueue(Customer c) // enqueue
    {
        if (len == 100)
        {
            cout << "Queue is full";
            return;
        }
        len++;
        rear++;
        if (rear == 100)
        {
            rear = 0;
        }
        queue[rear] = c;
    }

    void service() // dequeue
    {
        if (len == 0)
        {
            cout << "Queue is empty";
            return;
        }

        front++;
        len--;
        if (front == 10)
        {
            front = 0;
        }
    }

    string* nextThreeCustomers() // info of 3 customers
    {
        for (int i = front; i <= front + 3; i++)
        {
            cout<< queue[i].name << endl;
        }
    }

    ~CheckoutQueue() {}
};

int main() // drivers code
{
    char choice;
    CheckoutQueue q1;
    Customer c1;
    string *three_cus;

    do
    {
        cout << "Enter which opertation do you want to perform\n1. Add Customer\n2. Remove Customer\n3. Next Three Customer\n4. Exit\n\n>>> ";
        cin>>choice;
        switch (choice)
        {
        case '1':
            cout << "Name: ";
            cin >> c1.name;
            cout << "Number of items : ";
            cin >> c1.n;
            q1.enqueue(c1);
            break;

        case '2':
            q1.service();
            break;

        case '3':
            q1.nextThreeCustomers();
            break;

        default:
            break;
        }
    } while (choice != '4');

    return 0;
}
