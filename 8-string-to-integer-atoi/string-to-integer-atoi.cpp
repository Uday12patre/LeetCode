class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // whitespaces handled
        while(i < n && s[i] == ' ')
            i++;

        // '-' and '+' handled
        int sign = 1;
        if(i < n && s[i] == '-' || s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // leading conversions
        int ans = 0;
        while(i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // *** Checking overflow conditions before multiplying answer by 10
            if(ans > INT_MAX / 10 || (ans == INT_MAX/10 && digit > INT_MAX%10))
                return (sign == 1) ? INT_MAX : INT_MIN;

            ans = ans*10 + digit;
            i++;
        }

        return ans*sign;
    }
};