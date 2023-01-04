#include <iostream>
#include <vector>

class Sudoku {
    public:
        void solveSudoku(std::vector<std::vector<char> >& board) {
            solve(board);

            std::cout << "\n";

            for(int i = 0; i < board.size();i++){
                for(int j = 0; j < board.size();j++){
                    std::cout << board[i][j] << "\t";
                }
                std::cout << "\n";
            }
        }
        
        bool solve(std::vector<std::vector<char> >& board){
            for(int i=0; i<board.size(); i++){
                for(int j=0; j<board[0].size(); j++){
                    if(board[i][j] == '0'){
                        for(char c='1'; c<='9'; c++){
                            if(valid(c, board, i, j)){
                                board[i][j] = c;
                                if(solve(board) == true) return true;
                                else board[i][j]='.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        
        bool valid(char c, std::vector<std::vector<char> >& board, int row, int col){
            for(int i=0; i<9; i++){
                if(board[i][col] == c) return false;
                if(board[row][i] == c) return false;
                if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c) return false;
            }
            return true;
        }
};

int main(){

    Sudoku Test;

    std::vector<std::vector<char> > board;

    unsigned int size = 9;

    for(int i = 0; i < size; i++){
        
        std::vector<char> curr_row;
        char curr;
        for(int i = 0; i < size; i++){
            std::cin >> curr;
            curr_row.push_back(curr);

            
        }
        board.push_back(curr_row);
        curr_row.clear();
    }

    Test.solveSudoku(board);


    return 0;
}