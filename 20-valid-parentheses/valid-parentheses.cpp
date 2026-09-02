class Solution {
public:
    bool isValid(string s) {
        
        stack <char> bracket;
        for(char c : s)
        {
            if(c == '(')
                bracket.push(')');
            else if(c == '{')
                bracket.push('}');
            else if(c == '[')
                bracket.push(']');

            else
            {
                if(bracket.empty() || bracket.top() != c)
                    return false;
                    
                bracket.pop();
            }
        }
     return bracket.empty();
    }
};