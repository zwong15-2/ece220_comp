//In this mp we are constructing the Game of Life. The game board is two-dimensional stored in a one-dimensional
//array. These three functions help check the live neighbor count for a specific cell as well as update the game
//board if necessary based on the Game of Life's rules. 
/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
int live_neighbors = 0;
if(row == 0)                                //checks if the given cell is in the first row
  {
   if(col == 0)                             //checks if the given cell is in the first column
     {                                      //and counts the live neighbors
      if(board[1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[boardColSize + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[boardColSize] == 1)
        {
         live_neighbors += 1;
        }
     }
   else if(col == boardColSize - 1)             //checks if the given cell is in the last column
     {                                     //and counts the live neighbors
      if(board[col + boardColSize] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + boardColSize - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col - 1] == 1)
        {
         live_neighbors += 1;
        }
     }
   else                                  //checks if the given cell is in the middle columns
     {                                   //and counts the live neighbors
      if(board[col + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + boardColSize + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + boardColSize - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + boardColSize] == 1)
        {
         live_neighbors += 1;
        }
     }
  }
else if(row == boardRowSize - 1)                             //checks if the given cell is in the last
  {                                                     //row
   if(col == 0)                                         //checks if the given cell is in the first
     {                                                  //column and counts live neighbors
      if(board[col + (boardColSize * (row - 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * row) + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1)) + 1] == 1)
        {
         live_neighbors += 1;
        }
     }
   else if(col == boardColSize - 1)                         //checks if the given cell is in the last
     {                                                 //column and counts live neighbors
      if(board[col + (boardColSize * row) - 1])
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) ) - 1] == 1)
        {
         live_neighbors += 1;
        }
     }
   else                                                    //checks if the cell is in the middle
     {                                                     //columns and counts live neighbors
      if(board[col + (boardColSize * (row - 1) )]   == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) ) - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) ) + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * row) - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * row) + 1] == 1)
        {
         live_neighbors += 1;
        }
     }
  }
else                                                     //checks if the given cell is in the 
  {                                                      //middle row
   if(col == 0)                                          
                                                         //checks if the given cell is in the first column and counts live neighbors
     {
      if(board[col + (boardColSize * (row - 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row + 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * row) + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) ) + 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row + 1) ) + 1] == 1)
        {
         live_neighbors += 1;
        }
     }
   else if(col == boardColSize - 1)                              //checks if the given cell is in the
     {                                                          //last column and counts live neighbors
      if(board[col + (boardColSize * (row - 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row + 1) )] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * row) - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row - 1) ) - 1] == 1)
        {
         live_neighbors += 1;
        }
      if(board[col + (boardColSize * (row + 1) ) - 1] == 1)
        {
         live_neighbors += 1;
        }
     }
  else                                             //checks if the given cell is in the middle
    {                                              //columns and counts live neighbors
     if(board[col + (boardColSize * row) - 1] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * row) + 1] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * (row + 1) )] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * (row + 1) ) + 1] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * (row + 1) ) - 1] == 1)
       {
        live_neighbors += 1;
       }
      if(board[col + (boardColSize * (row - 1) )] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * (row - 1) ) + 1] == 1)
       {
        live_neighbors += 1;
       }
     if(board[col + (boardColSize * (row - 1) ) - 1] == 1)
       {
        live_neighbors += 1;
       }
    }
  }      
return live_neighbors;        //returns live neighbors
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {

int i;        //initialization of variables and updated board array
int j;
int a;
int updated_board[boardRowSize * boardColSize];
for(i = 0; i < boardRowSize; i++)               //loops through given game board
   {
    for(j = 0; j < boardColSize; j++)
       { 
         a = countLiveNeighbor(board, boardRowSize, boardColSize, i, j); 
         if( (*(board + ((i*boardColSize) + j) )  == 0) && (a == 3) )    //if cell is dead and has 3 neighbors, cell is updated to live on new board
           {
            updated_board[(i*boardColSize) + j] = 1;
           }
         if( (*(board + ((i*boardColSize) + j) )  == 0) && (a != 3) )   //if cell is dead and does not have 3 neighbors, cell is updated to dead on new board
           {
            updated_board[(i*boardColSize) + j] = 0;
           }
         if( (*(board + ((i*boardColSize) + j) ) == 1) && (a != 2 && a != 3) ) //if cell is live and does not have 2 or 3 neighbors, cell is updated to dead on new board
           {
            updated_board[(i*boardColSize) + j] = 0;
           }
         if( (*(board + ((i*boardColSize) + j) ) == 1) && (a == 2 || a == 3) ) //if cell is live and has 2 or 3 neighbors, cell is updated to live on new board
            {
             updated_board[(i*boardColSize) + j] = 1; 
            }
       }
   }
for(i = 0; i < boardRowSize; i++)   //stores updated game board onto the board
   {
    for(j = 0; j < boardColSize; j++)
       {
        (*(board + ((i * boardColSize) + j))) = updated_board[(i*boardColSize) + j];
       }
   }

}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){
int x;      //initialzation of variables and array to store updated values within
int y;
int z;   
int w;
int updated_board[boardRowSize * boardColSize];
int checker;
int v;
for(x = 0; x < boardRowSize; x++)                 //code is the same as updateBoard code to compare with current game board to determine if there is an update or not
   {
    for(y = 0; y < boardColSize; y++)
       { 
         z = countLiveNeighbor(board, boardRowSize, boardColSize, x, y);
         if( (board[(x*boardColSize) + y]  == 0) && (z == 3) )
           {
            updated_board[(x*boardColSize) + y] = 1;
           }
         if( (board[(x*boardColSize) + y]  == 0) && (z != 3) )
           {
            updated_board[(x*boardColSize) + y] = 0;
           }
         if( (board[(x*boardColSize) + y] == 1) && (z != 2 && z != 3) )
           {
            updated_board[(x*boardColSize) + y] = 0;
           }
         if( (board[(x*boardColSize) + y] == 1) && (z == 2 || z == 3) )
            {
             updated_board[(x*boardColSize) + y] = 1; 
            }
       }
   }
checker = 0;
for(w = 0; w < boardRowSize; w++)  //loops through the current game board size checking the cells
   {
    for(v = 0; v < boardColSize; v++)
       {
        if((board[(w*boardColSize) + v] == 1) && (updated_board[(w*boardColSize) + v] != 1) )   //if the live cells in the current game board are not the same in the updated game board
          {                                                                                     //counter is incremented
           checker += 1;
          }
        else
          {
          
          }
       }   
   }
if(checker != 0)  //if counter is not zero, return zero to indicate there is an update
  {
   return 0;
  }
else              //return one to indicate there is no update
  {
   return 1;
  }

}
