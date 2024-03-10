#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

class fraction
{

public:
    int num, den;

    // Complete the class

    fraction(int n, int d)
    {

        this->num = n;

        this->den = d;
    }

    void add(int n, int d)
    {

        int num2 = n;

        int den2 = d;

        this->num = (num * den2) + (num2 * den);

        this->den = (den * den2);

        simplify();
    }

    void multiply(int n, int d)
    {

        int num2 = n;

        int den2 = d;

        this->num = (num * num2);

        this->den = (den * den2);

        simplify();
    }

    void simplify()
    {

        int g = gcd(num, den); //__gcd is pre build function to calculate greatest common divisor

        if (g == 0)

            return;

        else
        {

            this->num = (num / g);

            this->den = (den / g);
        }
    }

    void print()
    {

        cout << num << "/" << den << endl;
    }
};

int main()
{

    // Write your code here

    int num1, den1, t;

    cin >> num1 >> den1;

    cin >> t;

    fraction f(num1, den1);

    while (t > 0)
    {

        --t;

        int num2, den2, query;

        cin >> query >> num2 >> den2;

        if (query == 1)
        {

            f.add(num2, den2);
        }

        else
        {

            f.multiply(num2, den2);
        }

        f.print();
    }

    return 0;
}