/**
 Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

 **/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int first = start(nums, target);
        int last = end(nums, target);
        
        return {first, last};
    }
    
    int start(vector<int> v, int target){
        
        int l = 0;
        int r = v.size()-1;
        
        while(l <= r){
            
            int mid = (l+r)/2;
            
            if(v[mid] == target && ((mid > 0 && v[mid - 1] < v[mid]) || mid == 0))
               return mid;
           
            if(v[mid] >= target)
               r = mid - 1;
              else
               l = mid + 1;
        }
          return -1;
    }
               
   int end(vector<int> v, int target){
       
       int l = 0;
       int r = v.size()-1;
       
       while(l <= r){
           
           int mid = (l+r)/2;
           if(v[mid] == target && ((mid+1 < v.size() && v[mid] < v[mid+1]) || mid == v.size()-1))
               return mid;
           if(target >= v[mid])
               l = mid + 1;
           else
               r = mid - 1;
              
                  
       }
       return -1;
   }
};