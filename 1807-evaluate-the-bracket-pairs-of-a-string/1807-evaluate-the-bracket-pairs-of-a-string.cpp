class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string ans;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                // Find the closing bracket
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Replace with value if found, otherwise '?'
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }

                // Move past ')'
                i = j;
            }
            else {
                // Normal character
                ans += s[i];
            }
        }

        return ans;
    }
};