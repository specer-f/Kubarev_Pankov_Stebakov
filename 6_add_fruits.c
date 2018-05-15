#include <ncurses.h>
#include <stdio.h>
#define size_x 70
#define size_y 20

void Fruits();
void Snake();

struct Snake
{
	int x[100];
	int y[100];
};

int main()
{	
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();	
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
		if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, 				j, '='); }
		} printw("\n");
	}	
	
	int size_snake = 3;
	struct Snake snake;
	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;	
	keypad(stdscr, true);	
	for (int i = 0; i < size_snake; i++) {
		if (i == 0) {
		mvaddch(snake.y[0], snake.x[0], '%');
		}
		else { 
		mvaddch(snake.y[i], snake.x[i], '*');
		} 
	}


	while (true)
	{
		switch (getch())
		{
			case KEY_UP:
				clear();
				for(int i = size_snake; i !=0; i--){
					snake.y[i]=snake.y[i-1];
					snake.x[i]=snake.x[i-1];
				}
				snake.y[0]--;
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					}
				} 
				refresh();
			break;

			case KEY_DOWN:
				clear();
				for(int i = size_snake; i !=0; i--){
					snake.y[i]=snake.y[i-1];
					snake.x[i]=snake.x[i-1];
				}
				snake.y[0]++;
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;

			case KEY_RIGHT:
				clear();
				for(int i = size_snake; i !=0; i--){
					snake.y[i]=snake.y[i-1];
					snake.x[i]=snake.x[i-1];
				}
				snake.x[0]++;
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;
				
			case KEY_LEFT:
				clear();
				for(int i = size_snake; i !=0; i--){
					snake.y[i]=snake.y[i-1];
					snake.x[i]=snake.x[i-1];
				}
				snake.x[0]--;
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;			
		}
		
	}
	
	usleep(5000);
	refresh();
				
	getch();
	endwin();	
	

return 0;
}

void Fruits()
{
	char fruit = 34;
	int i = rand()%(size_y - 3) + 2;
	int j = rand()%(size_x - 2) + 2;
	mvaddch(i, j, '9');
}
