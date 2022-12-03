#include <iostream>
#include <vector> 
#include <unordered_map>

void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
        {
            std::cout << v[i] << ",";
        }
        else
        {
            std::cout << v[i];
        }
    }
}

std::vector<int> two_sum(std::vector<int> &nums, int target)
{
    std::vector<int> res(2);
    std::unordered_map<int, int> my_map;
    
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (my_map.find(diff) != my_map.end())
        {
            res[0] = my_map[diff];
            res[1] = i;
        }
        my_map[nums[i]] = i;
    }
    return res;
}

int main()
{
    int size, target;
    std::cout << "Enter the size of vector: ";
    std::cin >> size;
    std::vector<int> nums(size);
    std::cout << "Enter the elements of vector: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> nums[i];
    }
    std::cout << "Enter the target: ";
    std::cin >> target;
    std::cout << "Are the additive indices: [";
    print(two_sum(nums, target));
    std::cout << "]\n";
    return 0;
}