class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> last_seen(256, -1);
        int left = 0;
        int max_len = 0;

        for(int right = 0; right < s.length(); right++)
        {
            char curr_char = s[right];

            if(last_seen[curr_char] >= left)
            {
                left = last_seen[curr_char] + 1;
            }

            last_seen[curr_char] = right;

            max_len = max(max_len, 1 + right - left);
        }

        return max_len;
    }
};