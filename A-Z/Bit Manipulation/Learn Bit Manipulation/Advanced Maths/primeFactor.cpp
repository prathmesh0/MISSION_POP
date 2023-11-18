#include <iostream>
#include <vector>

std::vector<int> countPrimes(int n) {
    std::vector<int> ans;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ans.push_back(i);
            n = n / i;
        }
    }
    if (n > 1) {
        ans.push_back(n);
    }
    return ans;
}

int main() {
    int num = 60; // Example input
    std::vector<int> result = countPrimes(num);

    std::cout << "Prime factors of " << num << " are: ";
    for (int factor : result) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
