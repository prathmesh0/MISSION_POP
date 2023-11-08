#include <iostream>

bool isKthBitSet(int n, int k) {
    // Create a mask with only the Kth bit set to 1 (all other bits set to 0)
    int mask = 1 << k;

    // Use bitwise AND to check if the Kth bit is set
    if ((n & mask) != 0) {
        return true; // Kth bit is set
    } else {
        return false; // Kth bit is not set
    }
}

int main() {
    int N, K;

    std::cout << "Enter an integer N: ";
    std::cin >> N;

    std::cout << "Enter the bit position K (0-based index): ";
    std::cin >> K;

    if (isKthBitSet(N, K)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
