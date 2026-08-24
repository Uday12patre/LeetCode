class Solution {
public:
    long long ncr(int n, int r)
    {
        long long result = 1;
        for(int i = 0; i < r; i++)
        {
            result = result * (n-i);
            result = result/(i+1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> answer;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> result;
            for(int j = 0; j <= i; j++)
            {
                result.push_back(ncr(i,j));
            }
            answer.push_back(result);
        }

        return answer;
    }
};