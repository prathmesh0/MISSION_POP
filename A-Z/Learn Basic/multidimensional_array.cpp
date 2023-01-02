#include <iostream>
using namespace std;

int main()
{
    // multidimensional array
    // declaration and initialization
    int student[3][3] = {{12, 22, 34}, {12, 55, 25}, {54, 76, 89}};
    int marks[3][4] = {12, 3, 4, 55, 6, 78, 8, 4, 43, 98, 98, 76};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << student[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}