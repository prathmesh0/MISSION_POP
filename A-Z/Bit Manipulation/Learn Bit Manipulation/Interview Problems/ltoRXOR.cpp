#include <iostream>

int findXOR(int L, int R) {
    // Finding the XOR of 1 to R
    int ans = 0;
    if (R % 4 == 0) ans = R;
    else if (R % 4 == 1) ans = 1;
    else if (R % 4 == 2) ans = R + 1;
    else if (R % 4 == 3) ans = 0;

    // Finding XOR of 1 to L-1
    L = L - 1;
    int ans1 = 0;
    if (L % 4 == 0) ans1 = L;
    else if (L % 4 == 1) ans1 = 1;
    else if (L % 4 == 2) ans1 = L + 1;
    else if (L % 4 == 3) ans1 = 0;

    return ans ^ ans1;
}

int main() {
    int L = 5; // Example L value
    int R = 20; // Example R value

    int result = findXOR(L, R);
    std::cout << "XOR from " << L << " to " << R << " is: " << result << std::endl;

    return 0;
}
