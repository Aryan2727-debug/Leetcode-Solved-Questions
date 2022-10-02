class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        for(int row = 0; row < n; row++){
            //Flipping
            reverse(image[row].begin(), image[row].end());
            
            for(int col = 0; col < m; col++){
                //inverting
                image[row][col] ^= 1;        
            }
        }
        
        return image;
    }
};