#include <stdio.h>
#include <math.h>

// Function to calculate the number of nodes in a binary tree with height N
int numberOfNodes(int N) {
    int ans = pow(2, N - 1);
    return ans;
}

int main() {
    // Example: Calculate the number of nodes for a binary tree with height 4
    int input = 4;
    int result = numberOfNodes(input);

    // Print the result
    printf("Number of nodes for a binary tree with height %d: %d\n", input, result);

    return 0;
}
