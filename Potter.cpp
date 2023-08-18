#include "Potter.h"
#include <curses.h>
#include "Moving.h"
#include <vector>
#include "Engine.h"
#include <time.h>
#include <stdlib.h>
#include "Gnome.h"
using namespace std;

Potter::~Potter(){
}
void Potter::ShowPotter(Engine& e){

	vec = e.get_map();
	
    int z=e.get_rows();
	int k=e.get_col();
	while(1){
		y=rand()%z; //22
		x=rand()%k; //75
		if (vec[y][x]!='*' && vec[y][x]!='$' && vec[y][x]!='E' ){	
			move(y,x);
			addch('@');
			vec[y][x] = '@';
			break;
		}
	}
		e.UpdateMaze(y, x, '@', 1);
}

void Potter::Move(Engine& e, Moving& g, Moving& g1){
	int cnt = 0;
			g.Move(e, g, g1);
			g1.Move2(e, g, g1);
	int ch;
	keypad (stdscr,TRUE);
	vec = e.get_map();	
	
	int win = 100;
	do{
		ch = getch();
		move(y,x);
		switch(ch){
			case 32:{
				addch(' ');
				move(y,x);
				addch('@');
				g.Move(e, g, g1);
				g1.Move2(e, g, g1);
				break;}
			case KEY_UP :{	
						y--;
						
				if(vec[y][x] == '*') y++;
				if(vec[y][x] == '$'){
					cnt++;
					e.CalcScore(cnt);
					vec[y][x] = ' ';
					e.UpdateMaze(y, x, ' ',1);
				}
				if (vec[y][x] == '#'){
					e.CalcScore(win);
					vec[y][x] == ' ';
					e.gameover=2;
					ch = 27;
				}
				if (vec[y][x] == 'E'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
					
				}
				if (vec[y][x] == 'O'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
					
				}

				addch(' ');
				move(y,x);
				addch('@');
				g.Move(e, g, g1);
				g1.Move2(e, g, g1);

				break;}
			case KEY_DOWN :{ 
					y++;
					
				if(vec[y][x] == '*') y--;
				if(vec[y][x] == '$'){ 
					cnt++;
					e.CalcScore(cnt);
					vec[y][x] = ' ';
					e.UpdateMaze(y, x, ' ', 1);
				}
				if (vec[y][x] == '#'){
					e.CalcScore(win);
					vec[y][x] == ' ';
					//printw("%d", win);
					e.gameover=2;
					ch = 27;
				}
				if (vec[y][x] == 'E'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}
				if (vec[y][x] == 'O'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}
					addch(' ');		
					move(y,x);
					addch('@');
					g.Move(e, g, g1);
					g1.Move2(e, g, g1);

					break;}
			case KEY_RIGHT :{ 
						x++;
					

				if(vec[y][x] == '*') x--;
				if(vec[y][x] == '$'){
					cnt++;
					e.CalcScore(cnt);

					vec[y][x] = ' ';
					e.UpdateMaze(y, x, ' ', 1);
				
					}
				if (vec[y][x] == '#'){
					e.CalcScore(win);
					vec[y][x] == ' ';
					e.gameover=2;
					ch = 27;
				}
				if (vec[y][x] == 'E'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}
				if (vec[y][x] == 'O'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}
			addch(' ');
			move(y,x);
			addch('@');
			g.Move(e, g, g1);
			g1.Move2(e, g, g1);
			
				break;}
			case KEY_LEFT :{ 
			
				x--;
					
				
				if (vec[y][x] == '*') x++;
				if(vec[y][x] == '$'){
					cnt++;
					e.CalcScore(cnt);
					vec[y][x] = ' ';
					e.UpdateMaze(y, x, ' ', 1);
					

					}
				if (vec[y][x] == '#'){
					e.CalcScore(win);
					vec[y][x] == ' ';
					e.gameover=2;
					ch=27;
				}
				if (vec[y][x] == 'E'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}
				if (vec[y][x] == 'O'){
					ch = 27;
					e.gameover = 1;
					vec = e.get_map();
				}

			addch(' ');
			move(y,x);
			addch('@');
			g.Move(e, g, g1);
			g1.Move2(e, g, g1);

			break;}
		}
		
		if (cnt == 10){
			e.ShowPerg();
			cnt = 0;
		}

		//printw("%d", cnt);
		vec = e.get_map();
}while(ch!=27);

}

void Potter::Move2(Engine& , Moving&, Moving&){
}


