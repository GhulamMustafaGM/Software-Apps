// Demonstrate class specialization.

#include <iostream>
using namespace std;

template <class T>
class myclass
{
    T x;

public:
    myclass(T a)
    {
        cout << "Inside generic myclass\n";
        x = a;
    }

    T getx() { return x; }
};
// Explicit specialization for int.
template <>
class myclass<int>
{
    int x;

public:
    myclass(int a)
    {
        cout << "Inside myclass<int> specialization\n";
        x = a * a;
    }
    int getx() { return x; }
};

int main()
{
    myclass<double> d(10.1);
    cout << "double: " << d.getx() << "\n\n";
    myclass<int> i(5);
    cout << "int: " << i.getx() << "\n";

    return 0;
}

/* Output:

Inside generic myclass
double: 10.1

Inside myclass<int> specialization
int: 25

*/