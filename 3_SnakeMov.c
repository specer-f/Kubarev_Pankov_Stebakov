#include <stdio.h>
#include <ncurses.h>

struct Snake
{
	int x[100];
	int y[100];
};

int main()
{
	struct Snake snake;
	int dop_x1, dop_x2, n = 4;	

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dop_x1 = snake.x[i];
			snake.x[i]++;
		} 
		else if (i % 2 == 0 && i != 0) {
			dop_x1 = snake.x[i];
			snake.x[i] = dop_x2;
		}
		else {
			dop_x2 = snake.x[i];
			snake.x[i] = dop_x1;
		}
	}
	return 0;
}
