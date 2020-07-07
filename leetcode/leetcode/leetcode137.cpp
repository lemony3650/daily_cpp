#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

/*********************************************************
 * ���������������ݣ��������ݺͳ������ε�����
 * �󵥸�����
*********************************************************/

class Solution {
public:
    int singleNumber_1(vector<int> &nums){
         sort(nums.begin(),nums.end());      
         for (int i = 0, j = 1; j < nums.size(); i+=3, j +=3) {
             if (nums[i] != nums[j])
                return nums[i];
         } 
         return nums[nums.size() - 1];
    }

    int singleNumber_2(vector<int> &nums) {
        int res = 0;

        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                sum += (nums[j] >> i) & 1;
            }
            res ^= (sum % 3) << i;
        }
        return res;
    }

};


int main()
{
    vector<int> v1;
    Solution s;

    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(3);   
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(4); 
    v1.push_back(2);
    v1.push_back(2);   
    v1.push_back(2);  
 
    // ������ң���ָ��
    int n1 = s.singleNumber_1(v1);

    // λ����
    int n2 = s.singleNumber_2(v1);


    cout << n1 << endl;
    cout << n2 << endl;


    return 0;
}