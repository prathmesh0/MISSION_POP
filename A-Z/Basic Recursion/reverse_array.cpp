#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    cout << "reversed array ->" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}

// using extra array
// void ReverseArray(int arr[], int n)
// {
//     int ans[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         ans[n - i - 1] = arr[i];
//     }
//     PrintArray(ans, n);
// }

// using two pointer approach
void ReverseArrayTwo(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // ReverseArray(arr, n);
    ReverseArrayTwo(arr, n);
    PrintArray(arr, n);
    return 0;
}