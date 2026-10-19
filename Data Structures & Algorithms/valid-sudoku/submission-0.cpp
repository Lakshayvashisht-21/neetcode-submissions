class Solution {
public:
    bool isnum(char t){
        if(t=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    bool col(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            vector<int> check(9,-1);
            for(int j=0;j<9;j++){
                if(isnum(board[j][i])){
                    int k= board[j][i]-'0';
                    if(check[k-1]==-1){
                        check[k-1]=0;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool matrix(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(i%3==0 && j%3==0){
                    vector<int> check(9,-1);
                    for(int r=i;r<i+3;r++){
                        for(int c=j;c<j+3;c++){
                            if(isnum(board[r][c])){
                                int k= board[r][c]-'0';
                                if(check[k-1]==-1){
                                    check[k-1]=0;
                                }
                                else{
                                    return 0;
                                }
                            }
                        }
                    }
                }
               
            }
        }
        return 1;
        
    }
    bool row(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            vector<int> check(9,-1);
            for(int j=0;j<9;j++){
                if(isnum(board[i][j])){
                    int k= board[i][j]-'0';
                    if(check[k-1]==-1){
                        check[k-1]=0;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(col(board)==0){
            return 0;
        }
        if(row(board)==0){
            return 0;
        }
        
        return matrix(board);
        
    }
};
