class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;

            long long val = 1;

            for (int col = 0; col <= i; col++) {
                row.push_back(val);

                val = val * (i - col) / (col + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};