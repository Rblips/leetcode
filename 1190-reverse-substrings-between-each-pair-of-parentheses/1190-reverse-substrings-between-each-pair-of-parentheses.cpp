class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair_(n);
        stack<int> st;
        
        // Step 1: find matching pairs
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top(); st.pop();
                pair_[i] = j;
                pair_[j] = i;
            }
        }
        
        // Step 2: traverse with direction flipping at brackets
        string result;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair_[i];
                d = -d;
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};