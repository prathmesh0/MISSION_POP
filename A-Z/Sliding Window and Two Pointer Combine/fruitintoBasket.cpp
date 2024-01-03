#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution
// {
// public:
//     int totalFruit(std::vector<int> &fruits)
//     {
//         int maxi = 0;
//         int n = fruits.size();
//         for (int i = 0; i < n; i++)
//         {
//             std::unordered_map<int, int> basket;
//             for (int j = i; j < n; j++)
//             {
//                 if (basket.size() <= 2)
//                 {
//                     basket[fruits[j]]++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//                 maxi = std::max(maxi, j - i + 1);
//             }
//         }
//         return maxi;
//     }
// };

// Optimal Solution
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int maxi = 0;
        int n = fruits.size();
        int start = 0;
        int end = 0;
        unordered_map<int, int> basket;
        while (end < n)
        {
            // add current element in the basket
            basket[fruits[end]]++;

            // if basket contains  more than 2 unique fruit
            while (basket.size() > 2)
            {

                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0)
                {
                    basket.erase(fruits[start]);
                }
                start++;
            }

            maxi = max(maxi, end - start + 1);
            end++;
        }
        return maxi;
    }
};
// Input function
std::vector<int> takeInput()
{
    int n;
    std::cout << "Enter number of fruits: ";
    std::cin >> n;

    std::vector<int> fruits(n);
    std::cout << "Enter fruit types:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> fruits[i];
    }

    return fruits;
}

int main()
{
    Solution solution;
    std::vector<int> fruits = takeInput();
    int maxFruits = solution.totalFruit(fruits);
    std::cout << "Maximum fruits that can be collected: " << maxFruits << std::endl;

    return 0;
}
