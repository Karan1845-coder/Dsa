class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int N=matrix.size(),M=matrix[0].size();
        int start=0,end=N*M-1;
        int row_index,col_index,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            row_index=mid/M;
            col_index=mid%M;
            
            if(matrix[row_index][col_index]==x)
            return 1;
            else if(matrix[row_index][col_index]<x)
            start=mid+1;
            else 
            end=mid-1;
        }
        return 0;
    }
};