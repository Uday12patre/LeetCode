class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> answer;
        // creating void 2D vector
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> temp(i);
            answer.push_back(temp);
        }

        // filling up pascal's triangle
        for(int i = 0; i < numRows; i++)
        {
            int ans;
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || i == j)
                    ans = 1;
                else
                    ans = answer[i-1][j-1] + answer[i-1][j];

                answer[i][j] = ans; 
            }
        }

        return answer;
    }
};