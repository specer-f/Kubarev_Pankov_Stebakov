#include <stdio.h>
#include <ncurses.h>

struct Snake
{
	int x[100];
	int y[100];
};

int main()
{
	initscr();
	curs_set(0);
	//clear();
	int size_snake = 3;
	struct Snake snake;
	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;	
	int i = 1, y = 1;
	keypad(stdscr, true);	
	for (int i = 0; i < size_snake; i++)
	{
	if (i == 0) 
	{
	mvaddch(snake.y[0], snake.x[0], '%');
	}
	else
	{ 
	mvaddch(snake.y[i], snake.x[i], '*');
	} 
	}


	while (true)
	{
	//clear();
		
		switch (getch())
		{
			case KEY_UP:
				for (int i = 0; i < size_snake; i++)
				{
				snake.y[i]--;
				}				
				for (int i = 0; i < size_snake; i++)
				{
				if (i == 0) 
				{
				mvaddch(snake.y[0], snake.x[0], '%');
				}
				else
				{ 
				mvaddch(snake.y[i], snake.x[i], '*');
				} 
				}
			break;

			case KEY_DOWN:
				for (int i = 0; i < size_snake; i++)
				{
				snake.y[i]++;
				}
				for (int i = 0; i < size_snake; i++)
				{
				if (i == 0) 
				{
				mvaddch(snake.y[0], snake.x[0], '%');
				}
				else
				{ 
				mvaddch(snake.y[i], snake.x[i], '*');
				} 
				}
			break;

			case KEY_RIGHT:
				for (int i = 0; i < size_snake; i++)
				{
				snake.x[i]++;
				}
				for (int i = 0; i < size_snake; i++)
				{
				if (i == 0) 
				{
				mvaddch(snake.y[0], snake.x[0], '%');
				}
				else
				{ 
				mvaddch(snake.y[i], snake.x[i], '*');
				} 
				}
			break;
				
			case KEY_LEFT:
				for (int i = 0; i < size_snake; i++)
				{
				snake.x[i]--;
				}
				for (int i = 0; i < size_snake; i++)
				{
				if (i == 0) 
				{
				mvaddch(snake.y[0], snake.x[0], '%');
				}
				else
				{ 
				mvaddch(snake.y[i], snake.x[i], '*');
				} 
				}
			break;			
		}
	
		
	}
	usleep(5000);
	refresh();			
	getch();
	endwin();
	return 0;
}
