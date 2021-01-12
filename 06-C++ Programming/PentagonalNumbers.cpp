// Find pentagonal numbers

/*

Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2.
The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8.
However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk,
for which their sum and difference are pentagonal
and D = |Pk − Pj| is minimised; what is the value of D?

Program find pentagonal pairs and prove that they have
alse pentagonal sum and difference.

*/

#include <iostream>

using namespace std;

class Pentagonal
{

private:
    int j = 1, k = 1, z = 0, r = 0;
    long long sum = 0, dif = 0;
    int MIN_j = 0, MIN_k = 0, MIN_z = 0, MIN_r = 0;
    bool FCT = true;

public:
    // Constructor Pentagonal() step by step compare numbers
    // and looks if they pentagonal and fit all conditions
    Pentagonal()
    {
        while (FCT)
        {
            k = ++j;
            while (--k > 0)
            {
                sum = formula(j) + formula(k);
                dif = formula(j) - formula(k);
                // Obviously, index of pentagonal number equal
                // sum of pair will be bigger than max index = "j".
                z = j;
                // Obviously, index of pentagonal number equal
                // difference of numbers will be bigger than
                // min index = "k".
                r = k;
                if ((pentagon_chk(sum, z)) && (pentagon_chk(dif, r)))
                {
                    MIN_j = j;
                    MIN_k = k;
                    MIN_z = z;
                    MIN_r = r;
                    FCT = false;
                }
            }
        }
    }

    // Method return "true" if given number is pentagonal,
    // return "false" if - not.
    bool pentagon_chk(long long X, int &z)
    {
        long long P = 0;
        int i = z;
        while (P < X)
        {
            P = formula(i);
            z = i++;
            if (P == X)
                return true;
        }
        return false;
    }

    // Method formula calculate pentagonal number for given "i"
    long long formula(int i)
    {
        return (i * (3 * i - 1) / 2);
    }

    // Destructor print result of calculations
    ~Pentagonal()
    {
        if (!(FCT))
        {
            cout << "\nAfter research was founded pentagonal pair: " << endl;
            cout << "P[" << MIN_j << "]=" << formula(MIN_j) << " and ";
            cout << "P[" << MIN_k << "]=" << formula(MIN_k) << "." << endl;
            cout << "\nThat have pentagonal sum: " << endl;
            cout << "P[" << MIN_z << "]=" << formula(MIN_z);
            cout << "=" << formula(MIN_j);
            cout << "+" << formula(MIN_k) << endl;
            cout << "and pentagonal difference: " << endl;
            cout << "P[" << MIN_r << "]=" << formula(MIN_r);
            cout << "=|" << formula(MIN_j);
            cout << "-" << formula(MIN_k) << "|," << endl;
            cout << "which is minimum." << endl;
        }

        else
            cout << "Not a single pair of pentagonal numbers in the scope!";
    }
};

int main()
{

    // Initialize calculations by creating object call of Pentagonal class,
    // constructor Pentagonal() will calculate numbers
    Pentagonal call;

    return 0;

    // Destructor calls when main() is terminated
}