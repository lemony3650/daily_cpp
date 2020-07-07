#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // 动态规划 前面的元素大于0时，则将其加上当前元素
    int maxSubArray_1(vector<int>& nums) {
        int pre = 0;
        int maxAns = nums[0];

        // pre 小于0时则就抛开pre了，从当前位置开始了
        for (const auto &x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }       
        return maxAns;
    }


};