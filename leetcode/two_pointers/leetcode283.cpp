#include <iostream>
#include <vector>
using namespace std;

/*****************************************************************
 * ��������muns[],�����е�0ȫ���Ƶ�ĩβ�����ı��0Ԫ��ֵ
 * ����ͨ������Ŀ���������������������ƶ�����
 * 1.˫ָ��ij��iָ��ǰ��0Ԫ�أ�jָ��0����ĵ�һ����0Ԫ�أ����н���
 * 2.����0Ԫ�������ԣ��������ݵ�ͬʱ���һ��++ָ�룬�Ƚ���0Ԫ�ش洢
*****************************************************************/


class Solution {
public:

    // ��ʼi=j��Ԫ�ز�Ϊ0ʱ������ʱҲ����Ӱ�죬������ij����1
    void moveZeroes_1(vector<int>& nums) {
        for (int i = 0,j = 0; j < nums.size(); j++) 
            if (nums[j] != 0)
                swap(nums[i++],nums[j]); 
    }

    // ��¼0Ԫ�صĸ���������0Ԫ��ת�棬���0Ԫ�����ĩβ������ĿҪ�󲻷���
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

    // ���淽���ı��壬����0Ԫ�ش浽ǰ�棬�����0
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