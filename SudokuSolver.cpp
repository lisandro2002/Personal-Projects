#include <iostream>

// N is the size of the 2D matrix rows * cols
#define N 9

/**
 * @brief this class will be utilized to solve the sudoku
 * 
 */
class SudokuSolver{

    private:

        int game_board[N][N];

    public:
        
        SudokuSolver(){

            get_unsolved_board();

            /**
             * @brief driver code, if solution exist figure out the solution 
             * else print that no solution exists
             * 
             */
            try{
                if(solveSudoku(0, 0)){
                    print_solved_board();
                }else{
                    throw 505;
                }
            }catch(...){
                std::cout << "No solution exists, sorry try again" << "\n";
            }
		       
        }

        /**
         * @brief Get the unsolved board object
         */

        void get_unsolved_board(){

            std::cout << "Enter the unsolved board \n\n";

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    std::cin >> game_board[i][j];
                    std::cout << " ";
                }
                std::cout << "\n";
            }
            
        }

        /**
         * @brief print the solved board
         */

        void print_solved_board(){

            std::cout << "Solved Board \n\n";

            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++)
                    std::cout << game_board[i][j] << "\t";
                std::cout << "\n";
            }
        }

        /**
         * @brief 
         * 
         * @param row the current row we are looking at
         * @param col the current col we are looking at
         * @param num  the number we are trying to see if it can be placed within the board
         * @return true if the num can be placed within the board
         * @return false if the num cannot be placed within the board
         */
       
        bool valid_move(int row,
                            int col, int num){
            
            // verify the same num doesn't exit within the row
            for (int x = 0; x <= 8; x++)
                if (game_board[row][x] == num)
                    return false;

            // verify the same num doesn't exit within the column
            for (int x = 0; x <= 8; x++)
                if (game_board[x][col] == num)
                    return false;

            //check if we have the same num within the 3*3 matrix, return false
            int startRow = row - row % 3,
                    startCol = col - col % 3;

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (game_board[i + startRow][j +
                                    startCol] == num)
                        return false;

            return true;
        }

        /**
         * @brief verify if the game board has been solved
         * 
         * @param row the current row we are looing at
         * @param col the current column we are looking at
         * @return true if the game board has been completely solved
         * @return false if the game board has not been completed
         */

        bool solveSudoku(int row, int col){

            // is the row and col have been looked return true as the game board is solved
            
            if (row == N - 1 && col == N)
                return true;

           
            if (col == N) {
                row++;
                col = 0;
            }

            if (game_board[row][col] > 0)
                return solveSudoku(row, col + 1);

            for (int num = 1; num <= N; num++)
            {
                
                // verify if the our next move is valid else increment the num
                if (valid_move(row, col, num))
                {
                    
                    // assign the num if is a valid move
                    game_board[row][col] = num;
                
                    // Checking for next possibility with next
                    if (solveSudoku(row, col + 1))
                        return true;
                }

                game_board[row][col] = 0;
            }
            return false;
        }
};


int main(){
	
	// creating an instance of the SudokuSolver class
    SudokuSolver (*Test) = new SudokuSolver();

	return 0;
}