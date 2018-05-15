#include <ncurses.h>
#include <stdio.h>
#define size_x 70
#define size_y 20
#define MAX 10

void Fruits();
void Snake();

struct snake_arr
{
	int x;
	int y;
	char point;
};

int main()
{
	struct snake_arr snake[MAX];
	snake[0].x = 45;
	snake[0].y = 10;
	snake[0].point = '#'; 
	bool Gameover = true;
	srand(time(0));
	initscr();
	while (Gameover)
	{		
	clear();
	//int i = 0, j = 0;
	//Gosha Dudar'	
	//getmaxyx(stdscr,size_y, size_x);
	for (int i = 0; i < size_y; i++) {
	  for (int j = 0; j < size_x; j++) {
		if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, j, '='); }
		//else { printw("%c", 32); }
	 } printw("\n");
	}
	Fruits();
	
	refresh();
	usleep(250000);
	}
	getch();
	endwin();
	
	return 0; 
}

void Snake(struct snake_arr *snake_for_func)
{
	printw(snake_for_func[0]);
}

void Fruits()
{
	char fruit = 34;
	int i = rand()%(size_y - 3) + 2;
	int j = rand()%(size_x - 2) + 2;
	mvaddch(i, j, '9');
}
