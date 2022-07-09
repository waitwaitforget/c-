#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return  res;
        sort(nums.begin(), nums.end());
        for(auto x=0; x<nums.size(); x++) {
            cout << nums[x] << ",";
        }
        cout << endl;
        int i = 0,  j = i + 1, k = nums.size();

        for (i = 0; i < nums.size() - 2; i ++) {
            j = i + 1;
            k = nums.size() - 1;
            int val = - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < val) {
                    j++;
                } else if (nums[j] + nums[k] > val) k--;
                else {
                    if (nums[i] == -1) {
                        cout << "* " << nums[j] << " " << nums[k] << endl;
                    }
                    if (j == i + 1 || k == nums.size() - 1 || (nums[j] != nums[j-1] && nums[k] != nums[k+1]))
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        res.push_back(temp);
                    }
                    j++; 
                    k--;
                    
                }
            }
            while (nums[i] == nums[i+1] && i < nums.size()-2) i++;
        }
        return res;
    }
    
    vector<vector<int>> threeSumV2(vector<int>& nums) {
           vector<vector<int>> res;
        if (nums.size() < 3) return  res;
        sort(nums.begin(), nums.end());
        int i = 0,  j = i + 1, k = nums.size();

        for (i = 0; i < nums.size() - 2; i ++) {
            j = i + 1;
            if (nums[i] > 0) break;
            k = nums.size() - 1;
            int val = - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < val) {
                    j++;
                } else if (nums[j] + nums[k] > val) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                   
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                     j++; 
                    k--;
                }
            }
            //while (nums[i] == nums[i+1] && i < nums.size()-2) i++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> test = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    vector<vector<int>> res = sol.threeSumV2(test);

    for (auto v : res) {
        cout  << v[0] << "," << v[1] << "," <<v[2] <<endl;
    }
    return 0;
}