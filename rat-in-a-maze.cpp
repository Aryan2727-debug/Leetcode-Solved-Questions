class Solution{
    public:
    
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
        //base case
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        
        //DOWNWARD (i+1,j)
        if(i+1 < n && !vis[i+1][j] && a[i+1][j] == 1){
            //if i+1 is within boundaries, it has NOT been visited, and its value is = 1
            vis[i][j] = 1;
            //recursive call
            solve(i+1, j, a, n, ans, move + "D", vis);
            //BACKTRACKING
            vis[i][j] = 0;
        }
        
        //LEFT (i,j-1)
        if(j-1 >= 0 && !vis[i][j-1] && a[i][j-1] == 1){
            //if j-1 is within boundaries, it has NOT been visited, and its value is = 1
            vis[i][j] = 1;
            //recursive call
            solve(i, j-1, a, n, ans, move + "L", vis);
            //BACKTRACKING
            vis[i][j] = 0;
        }
        
        //RIGHT (i,j+1)
        if(j+1 < n && !vis[i][j+1] && a[i][j+1] == 1){
            //if j+1 is within boundaries, it has NOT been visited, and its value is = 1
            vis[i][j] = 1;
            //recursive call
            solve(i, j+1, a, n, ans, move + "R", vis);
            //BACKTRACKING
            vis[i][j] = 0;
        }
        
        //UPWARD (i-1,j)
        if(i-1 >= 0 && !vis[i-1][j] && a[i-1][j] == 1){
            //if i+1 is within boundaries, it has NOT been visited, and its value is = 1
            vis[i][j] = 1;
            //recursive call
            solve(i-1, j, a, n, ans, move + "U", vis);
            //BACKTRACKING
            vis[i][j] = 0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        
        //call the function only if starting value is 1, otherwise Rat can NOT move
        if(m[0][0] == 1){
            solve(0, 0, m, n, ans, "", vis);
        }
        
        return ans;
    }
};
