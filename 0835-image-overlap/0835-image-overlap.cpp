class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), ans = 0;

        for (int dr = -(n - 1); dr < n; dr++) {
            for (int dc = -(n - 1); dc < n; dc++) {
                int cnt = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int x = i + dr, y = j + dc;

                        if (x >= 0 && x < n && y >= 0 && y < n)
                            cnt += a[i][j] & b[x][y];
                    }
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
    