class Solution {
    //since we are traversing cols from left side 1 no need to check all directions for attack only from left
    bool notAttacking(int row, int col, vector<string> &board, int n) {
        int tmpRow = row;
        int tmpCol = col;
        
        //checking left upper diagonal for attack for any queen
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q')  return false;
            row--;
            col--;
        }
        
        //checking left side of cols for attack from any queen
        row = tmpRow;
        col = tmpCol;
        while(col>=0) {
            if(board[row][col] == 'Q')  return false;
            col--;
        }
        
        //checking left downward diagonal for any attack
        row = tmpRow;
        col = tmpCol;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        //if not under attack
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &res, int n) {
        //Base Case - if col reaches the end
        if(col == n) {
            res.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++) {
            if(notAttacking(row,col,board,n)) { //row is fixed and traversed in column
                board[row][col] = 'Q';
                solve(col+1 , board, res, n);
                board[row][col] = '.';
            }
        }
    }
    
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++) {
            board[i] = s;
        }
        solve(0,board,res,n);
        return res;
    }
};