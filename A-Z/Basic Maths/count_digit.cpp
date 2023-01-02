#include <iostream>
#include <math.h>
using namespace std;

int countDigit(int n)
{
    // approach 1 -> using loop and increase the count variable
    // Time complexity = O(n), Space complexity = O(1)

    /*
        x= 234 -- /10 (c1)
        x= 23 --/10   (c2)
        x= 2  --/10   (c3)
        x = 0

    */

    int x = n, count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;

    // approach 2 -> convert number to string and used length function to calculate length
    // TC = O(1), SC = O(1)
    string p = to_string(n);
    return p.length();

    // approach 3 ->Used log base 10 to (n) then take floor value and add 1 in it to get no.of digits
    // TC = O(1), SC =O(1)
    int digit = floor(log10(n) + 1);
    return (digit);
}

int main()
{
    int num;
    cin >> num;
    int count = countDigit(num);
    cout << count << endl;
    return 0;
}