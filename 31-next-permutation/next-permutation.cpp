class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        // finding the break index | nums[i] < nums[i+1]
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        // reverse the array if it's the greatest of all
        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // searching the number just greater than nums[index]
        for(int i = n-1; i > index; i--)
        {
            if(nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // eg. | 2 | 5 | 1 | 4 | 3 | 0 | 0 |

        // now reversing the list from nums[i] to nums.end();
        reverse(nums.begin() + index + 1, nums.end());
        return; 
    }
};