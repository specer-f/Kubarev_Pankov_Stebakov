#include <ncurses.h>
#include <stdio.h>
#define size_x 50
#define size_y 20

int main()
{
	initscr();	

	char field[size_y][size_x];

	for (int i = 0; i < size_y; i++) {
	 for (int j = 0; j < size_x; j++) { 
	   field[i][j] = '	';
	  }
        }
        
	for (int i = 0; i < size_y; i++) {
	 for (int j = 0; j < size_x; j++) {
	  if ((((j == 0) || (j == 1)) || ((j == size_x - 1) || (j == size_x - 2))) || ((i == 0) || (i == size_y -1))) 
	  { 
		printw("%d", field[i][j]); 
	  } else { printw("%c", 32); }
 	  } printw("\n");
	} 
	
	getch();
	endwin();
	
	return 0; 
}
