#include <bits/stdc++.h>

using namespace std;
// brute force
/*bool isCompatible(vector < int > inp, int dist, int cows) {
  int n = inp.size();
  int k = inp[0];
  cows--;
  for (int i = 1; i < n; i++) {
    if (inp[i] - k >= dist) {
      cows--;
      if (!cows) {
        return true;
      }
      k = inp[i];
    }
  }
  return false;
}
*/
// optimal approach
bool isPossible(int a[], int n, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastPlacedCow >= minDist)
        {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    if (cntCows >= cows)
        return true;
    return false;
}

int main()
{
    int n = 5, cows = 3;
    int a[] = {1, 2, 8, 4, 9};
    sort(a, a + n);

    int low = 1, high = a[n - 1] - a[0];

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "The largest minimum distance is " << high << endl;

    return 0;
}