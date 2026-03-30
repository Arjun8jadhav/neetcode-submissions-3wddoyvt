class Solution {
public:
    bool allwings(vector<vector<char>>& s){
        for(int i=0;i<9;i++){
            vector<int> row(10,0),col(10,0);
            for(int j=0;j<9;j++){
                if(s[i][j] != '.') {
                    row[s[i][j]-'0']++;
                    if(row[s[i][j]-'0']>1) return true;
                }
                if(s[j][i] != '.') {
                    col[s[j][i]-'0']++;
                    if(col[s[j][i]-'0']>1) return true;
                }
            }
        }
        return false;
    }
    bool notValid(int i,int j,vector<vector<char>> & board){
          vector<int> val(10,0);
          for(int l=i;l<i+3;l++){
            for(int m=j;m<j+3;m++){
                if(board[l][m] != '.') {
                    val[board[l][m]-'0']++;
                    if(val[board[l][m]-'0']>1) return true;
                }

            }
          }
          return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(allwings(board)){
            return false;
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(notValid(i,j,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
