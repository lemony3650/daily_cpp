#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int singleNumber_1(vector<int> &nums){
         sort(nums.begin(),nums.end());      
         for (int i = 0, j = 1; j < nums.size(); i+=2, j +=2) {
             if (nums[i] != nums[j])
                return nums[i];
         } 
         return nums[nums.size() - 1];
    }

    int singleNumber_2(vector<int> &nums) {
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tmp = tmp ^ nums[i];  
        }
        return tmp;
    }

    int singleNumber_3(vector<int> &nums) {
        unordered_set<int> bobo;
        int tmp;

        for (auto i : nums) {
            if (bobo.count(i))
                bobo.erase(i);
            else
                bobo.insert(i);
        }
        for (auto j : bobo) 
            tmp = j;

        return tmp;
    }
};


int main()
{
    vector<int> v1;
    Solution s;

    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(3);   
    v1.push_back(3);
    v1.push_back(4);  
    v1.push_back(2);
    v1.push_back(2);   

    // 排序查找，双指针
    int n1 = s.singleNumber_1(v1);

    // 异或操作，限于两次重复数据
    int n2 = s.singleNumber_2(v1);

    // 入hash 
    int n3 = s.singleNumber_3(v1);

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;

    return 0;
}