#include <iostream>
using namespace std;

int main()
{

    int arr[] = {11, 35, 62, 555, 989};
    int sum = 0;

    for (int x = 0; x < 5; x++)
    {
        sum += arr[x];
    }
    cout << "The sum of all integers is " << sum << endl;
}
