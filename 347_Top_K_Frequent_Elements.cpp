/**Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
//make pair of elements along with its frequency and sort


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        vector<int> res;
        vector<pair<int,int>> v;
        unordered_map<int, int> h;
        for(int x : nums)
            h[x]++;
        
        for(auto itr = h.begin(); itr != h.end(); itr++)
            v.push_back(make_pair(itr->second, itr->first));
        
        
        sort(v.begin(), v.end(), greater<>());
        
        for(int i = 0; i < k; i++)
            res.push_back(v[i].second);
        
        return res;
    }
};