// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int mx = 0;
        vector<int> LIS(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i], 1+LIS[j]);
                    
                }
                
            }
            mx = max(mx, LIS[i]);
        }
        return mx;
    }
};