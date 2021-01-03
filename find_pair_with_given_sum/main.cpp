#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int max_num = 0;
    vector<int> res;

    target -= 30;

    for (int i = 0; i < nums.size(); ++i) {
        auto it = m.find(target - nums[i]);

        if (it != m.end()) {
            if(it->second > max_num) {
                max_num = it->second;
                res = {it->second, i};
            }
            if(i > max_num) {
                max_num = i;
                res = {it->second, i};
            }
        }
        m[nums[i]] = i;
    }
    return res;
}

int main() {

    vector<int> nums {1, 10, 25, 35, 60};
    int target = 90;
    std::cout << "Input {1, 10, 25, 35, 60} Target 90" << std::endl;
    std::cout << "Expected output: 2, 3" << std::endl;
    vector<int> res = twoSum(nums, target);
    std::cout << "Actual output: " << res[0] << ", " << res[1] << std::endl;

    nums = {20, 50, 40, 25, 30, 10};
    std::cout << "Input {20, 50, 40, 25, 30, 10} Target 90" << std::endl;
    std::cout << "Expected output: 1, 5" << std::endl;
    res = twoSum(nums, target);
    std::cout << "Actual output: " << res[0] << ", " << res[1] << std::endl;

    return 0;
}
