#include <iostream>
#include <algorithm>
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
    int length;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // check if list is empty or not
    bool isempty()
    {
        return (head == nullptr);
    }

    // add new element at the first of linkedlist
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
        length++; // تحديث الطول
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
        length++; 
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
        for (Node *i = head; i; i = i->next, indx++)
        {
            if (i->data == val)
                return indx;
        }
        return -1; 
    }

    //Improve search by moving the item forward when found
    int search_improve(int val)
    {
        int indx = 0;
        Node *prv = nullptr;

        for (Node *cur = head; cur; prv = cur, cur = cur->next, indx++)
        {
            if (cur->data == val)
            {
                if (!prv) 
                    return indx;
                swap(prv->data, cur->data); 
                return indx - 1;
            }
        }
        return -1; 
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

    void validate_integrity()
    {
        cout << "Running tests...\n";

        // Test: tail->next should be nullptr
        if (tail && tail->next != nullptr)
        {
            cout << "Error: tail->next is not nullptr!\n";
        }

        // Test: Length validation
        int count = 0;
        for (Node *cur = head; cur; cur = cur->next)
        {
            count++;
        }
        if (count != length)
        {
            cout << "Error: Length mismatch! Expected " << length << ", Found " << count << "\n";
        }

        // Test: If length > 1, head should not be tail
        if (length > 1 && head == tail)
        {
            cout << "Error: Head and Tail should not be the same when length > 1!\n";
        }

        // Test: If length == 0, head and tail should be nullptr
        if (length == 0 && (head || tail))
        {
            cout << "Error: Head and Tail should be nullptr when list is empty!\n";
        }

        // Test: If length == 1, head should be tail and both should not be nullptr
        if (length == 1 && (head != tail || !head))
        {
            cout << "Error: When length = 1, head and tail should be the same and not nullptr!\n";
        }

        cout << "Tests completed, No issue.\n";
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
    linkedlist.run_tests();

    cout << "**************" << endl;
    int e;
    cout << "Enter second number: ";
    cin >> e;
    linkedlist.insert_end(e);
    linkedlist.display();

    return 0;
}
