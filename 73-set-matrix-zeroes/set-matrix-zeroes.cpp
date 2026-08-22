class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int row[n]; -> matrix[0][..]
        // int col[m]; -> matrix[..][0]

        int n = matrix.size(); // rows
        int m = matrix[0].size(); // colmumns

        bool col0 = true;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] =  0;

                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = false;

                }
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] != 0)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0)
            for(int j = 0;  j < m; j++) matrix[0][j] = 0;
        if(col0 == false)
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }
};