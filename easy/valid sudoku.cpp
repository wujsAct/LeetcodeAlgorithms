//easy:直接采用模拟的方法去解决！
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> nums;
        //row
        for(size_t i=0;i<board.size();++i){
            for(size_t j=0;j<board[i].size();++j){
                if(isdigit(board[i][j])){
                    if(nums.test(board[i][j]-'1')){
                        return false;
                    }
                    else{
                        nums.set(board[i][j]-'1');
                    }
                }
            }
            nums.reset();
        }
        //column
        for(size_t j=0;j<board[0].size();++j){
            for(size_t i=0;i<board.size();++i){
                if(isdigit(board[i][j])){
                    if(nums.test(board[i][j]-'1')){
                        return false;
                    }
                    else{
                        nums.set(board[i][j]-'1');
                    }
                }
            }
            nums.reset();
        }
        //block
        for(size_t k=0;k<9;++k){
            for(size_t i=0;i<3;++i){
                for(size_t j=0;j<3;++j){
                    if(isdigit(board[i+k/3*3][j+k%3*3])){
                        if(nums.test(board[i+k/3*3][j+k%3*3]-'1')){
                            return false;
                        }
                        else{
                            nums.set(board[i+k/3*3][j+k%3*3]-'1');
                        }
                    }
                }
            }
            nums.reset();
        }
       return true; 
    }
};