class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        std::string prefix = strs[0];
        
        for (size_t i = 1; i < strs.size(); ++i) {
            // find() != 0 means strs[i] does not start with the prefix
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back(); // Remove the last character
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};