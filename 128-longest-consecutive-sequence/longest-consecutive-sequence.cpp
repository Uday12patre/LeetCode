class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cntCurr = 0;
        int longest = 0;
        int lastSmaller = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            // [1,2,3,4,5,6,7]
            if(nums[i] - 1 == lastSmaller)
            {
                cntCurr++;
                lastSmaller = nums[i];
            }
            // [1,1,1,2,2,2,2,3,[3,100],101,102]
            else if(nums[i] != lastSmaller)
            {
                cntCurr = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cntCurr);
        }
        return longest;
    }
};