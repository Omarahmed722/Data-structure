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
            size = 1; // تحديث size
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
};

int main()
{
    int n = 2;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    for (int i = 0; i < 15; ++i)
        v.push_back(i + 10);

    v.print();

    return 0;
}