/**Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.**/

//store sorted version of each string in map with value as last index as new index in the resultant vector

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        vector<vector<string>> res;
        unordered_map<string, int> h;
        for(int i = 0; i < strs.size(); i++){
            
            string st = strs[i];
            sort(st.begin(), st.end());
            
            if(h.find(st) != h.end())
               res[h[st]].push_back(strs[i]);
            else
            {
              h[st] = res.size();
              res.push_back({strs[i]});
            }
        }
        return res;
    }
};