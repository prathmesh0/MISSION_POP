#include <iostream>
using namespace std;

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // initialization
    int arr[5];
    long long num[10];
    char letter[20];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    string name[4] = {"horse", "monkey", "dog", "cow"};
    for (int i = 0; i < 4; i++)
    {
        cout << name[i] << " ";
    }
    cout << endl;

    // initialization of array element with same value
    int arr1[100] = {0};
    printarray(arr1, 10);
    int arr2[5] = {2, 2, 2, 2, 2};
    printarray(arr2, 5);
    int n = 5, val = 10;
    int arr3[n];
    for (int i = 0; i < n; i++)
    {
        arr3[i] = val;
    }
    printarray(arr3, n);
    // fill is the inbuilt function
    int m;
    int arr4[m];
    fill_n(arr4, 5, 30);
    printarray(arr4, 5);

    // length of an array
    int lenght = sizeof(arr2) / sizeof(int);
    cout << lenght << endl;
    // scope of arrays in the function

       return 0;
}