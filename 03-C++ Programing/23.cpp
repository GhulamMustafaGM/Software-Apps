// Use get() to read a strin gthat contains spaces.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char str[80];

    cout << "Enter your name: ";
    cin.get(str, 79);

    cout << str << endl;

    return 0;
}

/* Output: 

Enter your name: ghulam
ghulam

*/