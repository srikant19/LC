// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// Input: [1,2,4,8]
// Output: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size();
        
        vector<int> res;
        vector<int> LDS(n, 1);
        vector<int> parent(n, 0);
        int mxlen = 0;
        int mxidx = 0;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(LDS[i] < LDS[j]+1){
                        LDS[i] = LDS[j]+1;
                        parent[i] = j;
                    }
                }
            }
          if(LDS[i] > mxlen){
              mxlen = LDS[i];
              mxidx = i;
          }
        }
        for(int i = 0; i < mxlen; i++){
            res.push_back(nums[mxidx]);
            mxidx = parent[mxidx];
        }
        
        return res; 
    }
};