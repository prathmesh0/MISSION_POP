#include <iostream>
using namespace std;

// void Moves_Zeros(int arr[], int n)
// {
//     int temp[n];
//     int k = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != 0)
//         {
//             temp[k] = arr[i];
//             k++;
//         }
//     }
//     while (k < n)
//     {
//         temp[k] = 0;
//         k++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << temp[i] << " ";
//     }
// }

void Moves_Zeros(int arr[], int n)
{
    int k = 0;
    // finding the first zero
    while (k < n)
    {
        if (arr[k] == 0)
        {
            break;
        }
        else
        {
            k++;
        }
    }

    int i = k;
    int j = k + 1;
    while (i < n && j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
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
    Moves_Zeros(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}