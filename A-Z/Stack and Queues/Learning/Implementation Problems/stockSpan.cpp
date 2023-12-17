#include <iostream>
#include <vector>

class StockSpanner {
public:
    std::vector<int> arr;

    StockSpanner() {

    }

    int next(int price) {
        arr.push_back(price);
        int span = 1;
        int ind = arr.size() - 2;

        while (ind >= 0 && arr[ind] <= price) {
            span++;
            ind--;
        }
        return span;
    }
};

// Function to simulate input and test the StockSpanner class
void simulateStockSpanner() {
    StockSpanner obj;

    // Assuming a series of stock prices input
    std::vector<int> stockPrices = { 100, 80, 60, 70, 60, 75, 85 };

    for (int price : stockPrices) {
        int span = obj.next(price);
        std::cout << "Price: " << price << ", Span: " << span << std::endl;
    }
}

int main() {
    simulateStockSpanner(); // Simulate input for the StockSpanner class
    return 0;
}
