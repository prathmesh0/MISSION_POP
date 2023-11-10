#include <iostream>
#include <vector>

std::vector<int> bitManipulation(int n, int i) {
    std::vector<int> ans;
    
    // Extract ith bit
    int res1 = (n >> (i - 1)) & 1;
    
    // Set bit at ith position
    int mask = 1 << (i - 1);
    int res2 = mask | n;
    
    // Clear bit at ith position
    int res3 = ~(mask) & n;
    
    ans.push_back(res1);
    ans.push_back(res2);
    ans.push_back(res3);
    
    return ans;
}

void getInputAndRun() {
    int n, i;
    
    // Get user input for n
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    // Get user input for i
    std::cout << "Enter the value of i: ";
    std::cin >> i;
    
    // Call bitManipulation function with user input
    std::vector<int> result = bitManipulation(n, i);
    
    // Display the results
    std::cout << "Results:" << std::endl;
    std::cout << "1. Extracted ith bit: " << result[0] << std::endl;
    std::cout << "2. Set bit at ith position: " << result[1] << std::endl;
    std::cout << "3. Cleared bit at ith position: " << result[2] << std::endl;
}

int main() {
    // Call the input function
    getInputAndRun();

    return 0;
}
