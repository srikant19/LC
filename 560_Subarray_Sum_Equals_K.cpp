/**Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
**/


//traverse the pointer to end and at each step store the sum(prefix sum) in a map
//and add the value of (value at h[sum - k]) , if sum-k exist in the map then it then definitely the subarray values after sum
//will be will be k, so the result will be incremented


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int sum = 0, res = 0;
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); i++){
            h[sum]++;
            sum += nums[i];
            res += h[sum - k];
           
        }
        return res;
    }
};