#include <iostream>
#include <vector>
using namespace std;

/*****************************************************
 * 红黄蓝对应012，不通过库中的排序函数的方式，按种类和顺序依次排序
 * 1.三指针的方式，i记录0的右侧，k记录2的左侧,
 *   默认起始位置i=0，k=size-1，j进行遍历将数据放到左边或者右边
 *   当j=k时表示遍历完成
 * 2.采用稳定的排序算法，如冒泡
******************************************************/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, curr = 0;
        int p2 = nums.size() - 1;

        while (curr <= p2) {
            if (nums[curr] == 0)
                swap(nums[curr++],nums[p0++]);
            else if (nums[curr] == 2)
                swap(nums[curr],nums[p2--]);
            else
                curr++;
        }


    }
};