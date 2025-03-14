#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
private:
    int *arr = nullptr;
    int size{0};
    int capacity{};

    void expand_capacity()
    {
        capacity *= 2;
        cout << "Expand capacity to " << capacity << "\n";
        int *arr2 = new int[capacity]{};
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
    }

public:
    Vector(int siz) : size(siz)
    {
        if (siz < 0)
        {
            size = 1; 
        }
        capacity = size + 10;
        arr = new int[capacity]{};
    }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get_size()
    {
        return size;
    }

    int get(int indx)
    {
        assert(0 <= indx && indx < size);
        return arr[indx];
    }

    void set(int indx, int valu)
    {
        assert(0 <= indx && indx < size);
        arr[indx] = valu;
    }

    int front()
    {
        return arr[0];
    }

    int back()
    {
        return arr[size - 1];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int find_index(int valu)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == valu)
                return i;
        }
        return -1;
    }

    void push_back(int value)
    {
        if (capacity == size)
        {
            expand_capacity();
        }
        arr[size++] = value;
    }

    void insert(int indx, int valu)
    {
        assert(0 <= indx && indx < size);
        if (capacity == size)
            expand_capacity();

        for (int i = size - 1; i > indx; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[indx] = valu;
        ++size;
    }

    void right_rotate(int n)
    {
        if (n <= 1)
            return;

        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    void left_rotate(int n)
    {
        if (n <= 1)
            return;

        int first = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = first;
    }
};

int main()
{
    int n = 5;
    Vector vector(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    cout << "Original array: ";
    v.print();

    v.right_rotate(n);
    cout << "Array after right rotation by 1: ";
    v.print();

    v.left_rotate(n);
    cout << "Array after left rotation by 1: ";
    v.print();

    return 0;
}
