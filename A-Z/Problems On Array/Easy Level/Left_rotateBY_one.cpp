#include <iostream>
using namespace std;

/*
//brute force approach
void Left_rotate(int arr[], int n)
{
    int temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}
*/

// optimal approach
void Left_rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    { // n-1 to prevent segmentation fault
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Left_rotate(arr, n);

    return 0;
}