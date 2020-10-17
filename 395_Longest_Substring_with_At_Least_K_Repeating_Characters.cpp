/**
 * Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 * */

class Solution {
public:
    int longestSubstring(string s, int k) {
       
        int n = s.length();
        if(n < k || n == 0) return 0;
        if(k == 0) return n; 
        
        unordered_map<char,int> h;
        for(char i : s)
            h[i]++;
        
        int i = 0;
        while(i < n && h[s[i]] >= k) i++;
        
        if(i == n) return n;
        
        int l = longestSubstring(s.substr(0,i), k);
        
        while(i < n && h[s[i]] < k) i++;
        
        int r = longestSubstring(s.substr(i,n), k);
        
        return max(l, r);
    }
};