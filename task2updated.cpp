#include <iostream>
using namespace std;

class Book
{
public:
    int ISBN;
    string title;
    string author;
    Book* next;

    Book(int val, string t, string a) : ISBN(val), title(t), author(a), next(nullptr) {}
};

class Bookstack
{
public:
    Book* top; // top of the stack

    Bookstack() : top(nullptr) {}

    void push(string t, string a, int val)
    {
        Book* newNode = new Book(val, t, a);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        int x;
        if (isEmpty())
        {
            cout << "Bookstack is empty " << endl;
            return;
        }
        else
        {
            cout << "How many books do you want to remove? ";
            cin >> x;
            for (int i = 0; i < x; i++)
            {
                Book* temp = top;
                top = top->next;
                delete temp;
            }
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void bubblesortBooksByISBN(Bookstack& stack, int ct)
{
    if (ct <= 1)
        return;

    Book* current = stack.top;
    Book* temp = nullptr;
    bool swapped;

    do
    {
        swapped = false;
        current = stack.top;

        while (current->next != temp)
        {
            if (current->ISBN > current->next->ISBN)
            {
                swap(current->ISBN, current->next->ISBN);
                swap(current->title, current->next->title);
                swap(current->author, current->next->author);
                swapped = true;
            }
            current = current->next;
        }

        temp = current;
    } while (swapped);
}

};

int main()
{
    Bookstack myStack;
    int ch;
    int count = 0;

    cout << "Push in stack" << endl;
    cout << "Pop from stack" << endl;
    cout << "Bubble sort the stack" << endl;
    cout << "Exit" << endl;

    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        cin.ignore(); // Consume the newline character

        switch (ch)
        {
        case 1:
            {
                string title, author;
                int ISBN;
                cout << "Enter title of book: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                cin >> ISBN;
                myStack.push(title, author, ISBN);
                count++;
                break;
            }
        case 2:
            myStack.pop();
            break;
        case 3:
            myStack.bubblesortBooksByISBN(myStack, count);
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 4);

    return 0;
}
