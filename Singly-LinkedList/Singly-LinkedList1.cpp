#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // check if list is empty or not
    bool isempty()
    {
        return (head == nullptr);
    }

    // add new element at the firest of linkedlist
    void insert_first(int num)
    {
        Node *node = new Node(num);

        if (isempty())
        {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
    }

    // add new element at the end of linkedlist
    void insert_end(int num)
    {
        Node *node = new Node(num);

        if (isempty())
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // It returns a pointer to the node (Node*) located at position n
    Node *get_nth(int n)
    {
        int cnt = 0;
        Node *cur = head;

        while (cur != nullptr)
        {
            if (++cnt == n)
                return cur;
            cur = cur->next;
        }

        return nullptr;
    }

    // Search for an element by value and return its index
    int search(int val)
    {
        int indx = 0;
        for (Node *i = head; i; i = i->next; indx++)
        {
            if (i->data == val)
                return indx;
            return -1
        }
    }

    // show the all item/element in the linkedlist
    void display()
    {
        for (Node *i = head; i; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList linkedlist;

    if (linkedlist.isempty())
    {
        cout << "The linked list is empty" << endl;
    }

    int n;
    cout << "Enter first number: ";
    cin >> n;
    linkedlist.insert_end(n);
    linkedlist.display();

    cout << "**************" << endl;
    int e;
    cout << "Enter second number: ";
    cin >> e;
    linkedlist.insert_end(e);
    linkedlist.display();

    return 0;
}
