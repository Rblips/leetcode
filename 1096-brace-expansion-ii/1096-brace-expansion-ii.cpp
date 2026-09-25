class Solution {
public:
    string s;
    int i = 0;

    set<string> merge(set<string> a, set<string> b) {
        set<string> res;

        for (const string& x : a) {
            for (const string& y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // Parse an expression until '}' or end
    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++; // skip comma

            set<string> next = parseTerm();

            res.insert(next.begin(), next.end());
        }

        return res;
    }

    // Parse concatenated expressions
    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++; // skip '{'

                cur = parseExpression();

                i++; // skip '}'
            }
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            res = merge(res, cur);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};