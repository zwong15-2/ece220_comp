/*In this mp we built a program that will solve a solvable maze and
 * return unsolvable if the maze cannot be solved. These four functions
 * are crucial for the program to function properly. The first function createMaze
 * creates the maze structure filling in the given cells based off the maze file.
 * destoryMaze frees up all the allocated memory and printMaze will print the maze
 * cells to the console. The last function will then solve the maze if it is possible 
 * or inform the user the maze is unsolvable.
 */
#include <stdio.h>
#include <stdlib.h>
#include "maze.h"


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName){
    //initialization of variables
    int row;
    int col;
    int width;
    int height;
    char x;
    FILE* maze_file;


    maze_t * maze = malloc(sizeof(maze_t)); 	                //allocate memory for structure

    maze_file = fopen((char*)fileName, "r"); 			//opens maze file and receives width and height values for maze

    fscanf(maze_file, "%d %d", 	&width, &height);

    maze->width = width;         //sets width and height parameters for maze structure
    maze->height = height;

    maze->cells = (char **) malloc((height) * sizeof(char *)); 	//allocates memory for cells within the maze

    for(row = 0; row < (height); row++){
        maze->cells[row] = (char *) malloc((width-1) * sizeof(char *));
    }

    for(row = 0; row < (height); row++){ 			//gets the characters from the file and stores into the cells of the maze array
        for(col = 0; col < (width); col++){
            x = fgetc(maze_file);

            if(x == '\n'){                              //if newline occurs, get next character
              x = fgetc(maze_file);
            }

            if(x == START){ 				//sets parameters for startRow and startColumn for maze structure when START definition is found
               maze->startRow = row;
               maze->startColumn = col;
            }

            if(x == END){                             //sets parameters for endRow and endColumn for maze structure when END definition is found
               maze->endRow = row;
               maze->endColumn = col;
            }
            maze->cells[row][col] = x;
             
        }
   }

   fclose(maze_file);  //closes file
          
return maze; //returns pointer to maze structure
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
	int i;   //initialize varible
	for(i = 0; i < maze->height; i++){ //loop through cells free up the allocated columns
    		free(maze->cells[i]);	
   	}
        free(maze->cells);  //free allocated rows from cells
	free(maze);        //free allocated maze structure
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */

void printMaze(maze_t * maze){
    int i;                 //initialization of variables
    int j;
    int width = maze->width; //setting width and height variables to width and height values
    int height = maze->height;

    for(i = 0; i < height; i++){   //loop through cells and print them to console
    	for(j = 0; j < width; j++){
             printf("%c", maze->cells[i][j]);
        }
        printf("\n");
   }

}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 
int solveMazeDFS(maze_t * maze, int col, int row){
if(col < 0 || row < 0 || col >= maze->width || row >= maze->height){	//if position lies outside of maze, return 0;
	return 0;
}

switch(maze->cells[row][col]){    
    case WALL:				//if position isn't start, then check if its empty, if its not, return 0 
    	return 0;
    case END:				//if the end of maze is reached, return 0
	return 1;
    case START:                         //if in the start position, check the possible pathways from start
	if((maze->cells[row - 1][col] == PATH) && (maze->cells[row - 2][col] == VISITED)){
		maze->cells[row - 1][col] = VISITED;		
	}
	if((maze->cells[row + 1][col] == PATH) && (maze->cells[row + 2][col] == VISITED)){
		maze->cells[row + 1][col] = VISITED;		
	}
	if((maze->cells[row][col - 1] == PATH) && (maze->cells[row][col - 2] == VISITED)){
		maze->cells[row][col - 1] = VISITED;		
	}
	if((maze->cells[row][col + 1] == PATH)  && (maze->cells[row][col + 2] == VISITED)){
		maze->cells[row][col + 1] = VISITED;		
	}
	break;
    case VISITED:              //if position is already visited, return 0
	return 0;
    case PATH:                //if position is already a part of the pathway, return 0
	return 0;
    case EMPTY:               //if position is in an empty space, mark it as a pathway
	maze->cells[row][col] = PATH;	
    	break;
}
//Recursive Cases
if(solveMazeDFS(maze, col - 1, row) == 1){				//if solveMaze to left returns 1, return 1
	return 1;
}
else if(solveMazeDFS(maze, col, row - 1) == 1){				//if solveMaze to down returns 1, return 1
	return 1;
}  
else if(solveMazeDFS(maze, col + 1, row) == 1){				//if solveMaze going right returns 1, return 1
	return 1;
}
else if(solveMazeDFS(maze, col, row + 1) == 1){				//if solveMaze going up returns 1, return 1
	return 1;
}
else{                                                                   //marks the cells visited if the cell is not the starting spot
	if((maze->cells[row][col] != START)){
		maze->cells[row][col] = VISITED;
	}
	return 0;
}

	
 	     	
}
