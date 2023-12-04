#include <iostream>
#include <vector>

std::vector<int> countGreater(std::vector<int> &arr, std::vector<int> &query)
{
    std::vector<int> ans;
    for (auto i : query)
    {
        int count = 0;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

// Input function
void inputFunction()
{
    int arrSize, querySize;

    std::cout << "Enter the size of arr: ";
    std::cin >> arrSize;
    std::vector<int> arr(arrSize);

    std::cout << "Enter elements of arr:" << std::endl;
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter the size of query: ";
    std::cin >> querySize;
    std::vector<int> query(querySize);

    std::cout << "Enter elements of query:" << std::endl;
    for (int i = 0; i < querySize; i++)
    {
        std::cin >> query[i];
    }

    std::vector<int> result = countGreater(arr, query);

    std::cout << "Number of elements greater than queried indices:" << std::endl;
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    inputFunction();
    return 0;
}
