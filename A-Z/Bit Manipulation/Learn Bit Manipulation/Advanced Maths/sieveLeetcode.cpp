#include <iostream>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        std::vector<int> isPrime(n + 1, 1);

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    int input_number = 20; // Example input
    int primeCount = solution.countPrimes(input_number);

    std::cout << "Number of prime numbers less than " << input_number << " is: " << primeCount << std::endl;

    return 0;
}
