#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // ��̬�滮 ǰ���Ԫ�ش���0ʱ��������ϵ�ǰԪ��
    int maxSubArray_1(vector<int>& nums) {
        int pre = 0;
        int maxAns = nums[0];

        // pre С��0ʱ����׿�pre�ˣ��ӵ�ǰλ�ÿ�ʼ��
        for (const auto &x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }       
        return maxAns;
    }


};