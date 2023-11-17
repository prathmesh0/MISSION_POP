#include <iostream>
#include <vector>

std::vector<int> twoOddNum(const std::vector<int>& arr) {
    std::vector<int> ans;
    int xor3 = 0;
    for (int i = 0; i < arr.size(); i++) {
        xor3 = xor3 ^ arr[i];
    }
    int count = 0;
    while (xor3) {
        if (xor3 & 1) {
            break;
        }
        count++;
        xor3 = xor3 >> 1;
    }
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if ((arr[i] & (1 << count))) {
            xor1 = xor1 ^ arr[i];
        } else {
            xor2 = xor2 ^ arr[i];
        }
    }
    return {std::max(xor1, xor2), std::min(xor1, xor2)};
}

void printTwoOddOccurrences(const std::vector<int>& result) {
    std::cout << "Two odd occurrences in the array are: " << result[0] << " and " << result[1] << std::endl;
}

int main() {
    // Input vector of integers
    std::vector<int> arr = {4, 3, 4, 5, 5, 6, 6, 8, 8, 9}; // Example input

    // Get two odd occurrences using the twoOddNum function
    std::vector<int> result = twoOddNum(arr);

    // Print the two odd occurrences
    printTwoOddOccurrences(result);

    return 0;
}
