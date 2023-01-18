class Solution {
public:

    bool solve(vector<vector<char>> &board){
        int row = board.size();
        int col = board[0].size();

        //traversing through the matrix/board
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //if an empty space is present
                if(board[i][j] == '.'){
                   //try for every possible number from 1-9
                   for(char c='1';c<='9';c++){
                       //checking if number is valid or not
                       if(isValid(board, i, j, c)){
                           board[i][j] = c;

                           //recursive call
                           if(solve(board) == true){
                               return true;
                           }else{
                               board[i][j] = '.';
                           }
                       }
                   }
                   return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c){
        for(int i=0;i<9;i++){
            //checking for valid row
            if(board[i][col] == c){
                return false;
            }

            //checking for valid column
            if(board[row][i] == c){
                return false;
            }

            //checking for valid 3x3 matrix
            if(board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c){
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};