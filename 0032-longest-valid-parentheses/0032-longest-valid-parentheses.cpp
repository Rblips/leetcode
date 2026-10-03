class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);              // base index before the string starts
        int best = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);   // unmatched ')' becomes the new base
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};