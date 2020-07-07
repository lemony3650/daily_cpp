#include <iostream>
#include <vector>
using namespace std;

/*****************************************************************
 * 给定数组muns[],将其中的0全部移到末尾，不改变非0元素值
 * 不能通过额外的拷贝数组操作，尽量减少移动次数
 * 1.双指针ij，i指向当前的0元素，j指向0后面的第一个非0元素，进行交换
 * 2.由于0元素特殊性，遍历数据的同时添加一个++指针，先将非0元素存储
*****************************************************************/


class Solution {
public:

    // 起始i=j，元素不为0时，交换时也不会影响，交换后ij都加1
    void moveZeroes_1(vector<int>& nums) {
        for (int i = 0,j = 0; j < nums.size(); j++) 
            if (nums[j] != 0)
                swap(nums[i++],nums[j]); 
    }

    // 记录0元素的个数，将非0元素转存，最后将0元素添加末尾，与题目要求不符合
    void moveZeroes_2(vector<int>& nums) {
        int numZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            numZeros += (nums[i] == 0);

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                ans.pop_back(nums[i]);

        while (numZeros--)
            ans.pop_back(0);

        for (int i = 0; i < n; i++)
            nums[i] = ans[i];
    }

    // 上面方法的变体，将非0元素存到前面，后面加0
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) 
            nums[i] = 0;
        
    }

};