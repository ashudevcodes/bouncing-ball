#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 20
#define HEIGHT 40

struct Circle{
	double x,y,r,v_x,v_y;
};

void printch(char c){
	printf("%c",c);
	printf("\033[1D");
	usleep(200000);
}

void clear_screen(){
	printf("\e[2J");
}

void move_cursor_beginning(){
		
	printf("\e[H");
}	


void screen_saver(struct Circle circle){
	for(int x = 0; x < WIDTH; x++){

		for(int y = 0; y < HEIGHT; y++){

			double distance = sqrt(pow(x - circle.x, 2) + pow(y - circle.y, 2));
			if(distance < circle.r){
				printf("#");
			}
			else{
				printf("-");
			}

		}
		printf("\n");
	}
}

void step(struct Circle* circle){

	if(circle->x - circle->r < 0)
		circle->v_x = - circle->v_x;
	if(circle->x + circle->r > WIDTH)
		circle->v_x = -circle->v_x;
	
	if(circle->y - circle->r < 0)
		circle->v_y = - circle->v_y;
	if(circle->y + circle->r > HEIGHT)
		circle->v_y = -circle->v_y;

	circle->x += circle->v_x;
	circle->y += circle->v_y;
		
}

int main(){
	/*
	printf("Hello Ashish ");
	while(1){
		printch('?');
		printch(':');
		printch('o');
	}
	*/

	clear_screen();

	struct Circle circle = {10,10,5,1,1};

	while(1){
		move_cursor_beginning();
		step(&circle);
		screen_saver(circle);
		usleep(200000);
	}
}
