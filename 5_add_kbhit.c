#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

struct Snake
{
	int x[100];
	int y[100];
};

void mov_arr(struct Snake snake, int n);
int kbhit();

int main()
{
	initscr();
	curs_set(0);
	int size_snake = 3;
	struct Snake snake;
	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;
	keypad(stdscr, true);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);

	while (true) {	
		if (!kbhit()) { 
		/*30*/	for (int i = 0; i < size_snake; i++) {
				snake.y[i]--;
			}				
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
				mvaddch(snake.y[0], snake.x[0], '%');
				//unsleep(5000);
				}
				else { 
				mvaddch(snake.y[i], snake.x[i], '*');
				//sleep(5000);
				} 
			}
		} 
		else {
			switch (getch())
		{
			case KEY_UP:
				for (int i = 0; i < size_snake; i++) {
				snake.y[i]--;
				}				
				for (int i = 0; i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
			break;

			case KEY_DOWN:
				for (int i = 0; i < size_snake; i++) {
				snake.y[i]++;
				}
				for (int i = 0; i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else	{ 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
			break;

			case KEY_RIGHT:
				for (int i = 0; i < size_snake; i++) {
				snake.x[i]++;
				}
				for (int i = 0; i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
			break;
				
			case KEY_LEFT:
				for (int i = 0; i < size_snake; i++) {
				snake.x[i]--;
				}
				for (int i = 0; i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
			break;			
		} 
		}
	sleep(2);
	}
	//sleep(10);
	refresh();
	getch();
	endwin();
	return 0;
}

void mov_arr(struct Snake snake, int n)
{
	int dop_x1, dop_x2;	

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dop_x1 = snake.x[i];
			snake.x[i]++;
		} 
		else if (i % 2 == 0 && i != 0) {
			dop_x1 = snake.x[i];
			snake.x[i] = dop_x2;
		}
		else {/*60*/
			dop_x2 = snake.x[i];
			snake.x[i] = dop_x1;
		}
	}

}

int kbhit()
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
	}
	else {
		return 0;
	} 
}
