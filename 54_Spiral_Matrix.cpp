/**
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


 **/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       
        if(!matrix.size()) return {};
        vector<int> res;
        int hor = matrix[0].size()-1;
        int ver = matrix.size()-1;
        
        int i = 0;
        int j = 0;
        
        while(i <= ver && j <= hor){
            
            for(int k = j; k <= hor; k++)
                res.push_back(matrix[i][k]);
            
            i++;
            if(i > ver) break;
            for(int k = i; k <= ver; k++)
                res.push_back(matrix[k][hor]);
            
            hor--;
            if(j > hor) break;
            for(int k = hor; k >= j; k--)
                res.push_back(matrix[ver][k]);
            
            ver--;
             if(i > ver) break;
            for(int k = ver; k >= i; k--)
                res.push_back(matrix[k][j]);
            
            
            j++;
        }
        return res;
    }
};