#include <iostream>

int setBits(int N) {
    if (N == 0) {
        return 1;
    }

    int position = 1;
    int originalN = N;

    while ((N & 1) == 1) {
        N >>= 1;
        position <<= 1;
    }

    if (N == 0) {
        return originalN;
    }

    return originalN | position;
}

int main() {
    int result = setBits(7);
    std::cout << result << std::endl;

    return 0;
}
