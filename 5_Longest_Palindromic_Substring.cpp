/**Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
**/

/** 
  take j and k as value of i 
  first check for even length palindrome and increment k 
  then as long as s[j-1] == s[k+1] j-- and k++ (for odd length palindrome)
  return the max length sub string
  **/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0;
        int max_len = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            int j = i, k = i;
            
            //even length palindrome
            while(k < s.length()-1 && s[k] == s[k+1]) k++;
            
            //odd length palindrome
            while(j > 0 && k < s.length()-1 && s[j-1] == s[k+1]){
                j--;
                k++;
            }
                
            //track of max length    
            if(k-j+1 > max_len){
                max_len = k-j+1;
                start = j;
            }
        }
        //extract max length sub string
        return s.substr(start, max_len);
    }
};