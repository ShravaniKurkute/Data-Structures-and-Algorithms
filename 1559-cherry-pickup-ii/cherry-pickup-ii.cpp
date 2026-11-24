class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(j1<0 || j1 >= n || j2<0 || j2 >= n) return INT_MIN;

        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int cherries = grid[i][j1];
        if(j1 != j2) cherries += grid[i][j2];
        int maxi = INT_MIN;

        for(int ic=-1; ic<=1; ic++){
            for(int jc=-1; jc<=1; jc++){
                int ans = solve(i+1, j1+ic, jc+j2, grid, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n-1, grid, dp);
    }
};