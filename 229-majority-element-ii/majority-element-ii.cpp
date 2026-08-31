class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // By Boyer–Moore Majority Vote Algorithm

        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt1 == 0 && nums[i] != el2)
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1)
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i])
                cnt1++;
            else if(el2 == nums[i])
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;

        int cnt3 = 0, cnt4 = 0;
        for(int i : nums)
        {
            if(i == el1)
                cnt3++;
        }

        for(int i : nums)
        {
            if(i == el2)
                cnt4++;
        }

        if(cnt3 > nums.size()/3)
            ans.push_back(el1);
        
        if(cnt4 > nums.size()/3)
            ans.push_back(el2);
        
        return ans;
    }
};