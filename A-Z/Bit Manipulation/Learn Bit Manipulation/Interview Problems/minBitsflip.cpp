#include <iostream>

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int value = start ^ goal;
        int count = 0;
        while (value) {
            value = value & (value - 1);
            count++;
        }
        return count;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input start and goal values
    int start = 29; // Example start value
    int goal = 15; // Example goal value

    // Call the minBitFlips function and output the result
    int flips = solution.minBitFlips(start, goal);
    std::cout << "Minimum number of bit flips required: " << flips << std::endl;

    return 0;
}
