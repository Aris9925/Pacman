#include "Gnome.h"
#include <curses.h>
#include "Moving.h"
#include <vector>
#include "Engine.h"
#include <time.h>
#include <stdlib.h>

using namespace std;


Gnome::~Gnome(){
}
void Gnome::ShowGnome(Engine& e){
	
	vec = e.get_map();
	int z=e.get_rows();
	int k=e.get_col();
	for(int i=0;i<vec.size();i++){
			 y=rand()%z;
			 x=rand()%k;
			if(vec[y][x]!='$' && vec[y][x]!='*' && vec[y][x]!='E'){
				init_pair('E', COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR('E'));
				move(y, x);
				addch('E');
				vec[y][x]='E';	
				attroff(COLOR_PAIR('E'));
				break;
		}
	}
	e.UpdateMaze(y, x, 'E', 0);

}

void Gnome::ShowGnome2(Engine& e){
	
	vec = e.get_map();
	int z=e.get_rows();
	int k=e.get_col();
	for(int i=0;i<vec.size();i++){
			 y=rand()%z;
			 x=rand()%k;
			if(vec[y][x]!='$' && vec[y][x]!='*' && vec[y][x]!='E'){
				init_pair('O', COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR('O'));
				move(y, x);
				addch('O');
				vec[y][x]='O';	
				attroff(COLOR_PAIR('O'));
				break;
		}
	}
	e.UpdateMaze(y, x, 'E', 0);

}

void Gnome::Move(Engine& e, Moving& p, Moving& p1){
	
	int count = 0;
	int ep;
	vec = e.get_map();
	move(y, x);
	
	if(vec[y][x] == '$'){
		init_pair('$', COLOR_MAGENTA, COLOR_BLACK);
		attron(COLOR_PAIR('$'));
		addch('$');
		attroff(COLOR_PAIR('$'));
	}
	else if(vec[y][x] == '#'){
		init_pair('#', COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR('#'));
		addch('#');
		attroff(COLOR_PAIR('#'));
	}
	else {
		addch(' ');
	}
	
//	vec[y][x] = ' ';
	e.UpdateMaze(y, x, ' ', 0);

	while(count==0){
		
		ep = rand() % 4;
		count = 0;
		e.UpdateMaze(y, x, ' ', 0);
		switch(ep){
			case 0:{
				if(vec[y-1][x]!='*'){
					y--; 
					init_pair('E', COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR('E'));
					move(y, x);
					addch('E');
					count ++;
					attroff(COLOR_PAIR('E'));
					break;
				}
				vec = e.get_map();
			}
			case 1:{
				if(vec[y+1][x]!='*'){
					y++; 
					init_pair('E', COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR('E'));
					move(y, x);
					addch('E');
					count ++;
					attroff(COLOR_PAIR('E'));
					break;
				}
				vec = e.get_map();
			}
			case 2:{
				if(vec[y][x-1]!='*'){
					x--; 
					move(y, x);
					init_pair('E', COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR('E'));
					addch('E');
					count ++;
					attroff(COLOR_PAIR('E'));
					break;
				}
				vec = e.get_map();
			}
			case 3:{
				if(vec[y][x+1]!='*'){
					x++; 
					move(y, x);
					init_pair('E', COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR('E'));
					addch('E');
					count ++;
					attroff(COLOR_PAIR('E'));
					break;
				}
				vec = e.get_map();
				}
	}
	vec[y][x]='E';
	e.UpdateMaze(y, x, 'E', 0);
	vec = e.get_map();
}}

void Gnome::Move2(Engine& e, Moving& p, Moving& p1){
	
	int count = 0;
	int ep;
	vec = e.get_map();
	move(y, x);
	
	if(vec[y][x] == '$'){
		init_pair('$', COLOR_MAGENTA, COLOR_BLACK);
		attron(COLOR_PAIR('$'));
		addch('$');
		attroff(COLOR_PAIR('$'));
	}
	else if(vec[y][x] == '#'){
		init_pair('#', COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR('#'));
		addch('#');
		attroff(COLOR_PAIR('#'));
	}
	else {
		addch(' ');
	}
	
//	vec[y][x] = ' ';
	e.UpdateMaze(y, x, ' ', 0);

	while(count==0){
		ep = rand() % 4;
		count = 0;
		e.UpdateMaze(y, x, ' ', 0);
		switch(ep){
			case 0:{
				if(vec[y-1][x]!='*'){
					y--; 
					init_pair('O', COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR('O'));
					move(y, x);
					addch('O');
					count ++;
					attroff(COLOR_PAIR('O'));
					break;
				}
				vec = e.get_map();
			}
			case 1:{
				if(vec[y+1][x]!='*'){
					y++; 
					init_pair('O', COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR('O'));
					move(y, x);
					addch('O');
					count ++;
					attroff(COLOR_PAIR('O'));
					break;
				}
				vec = e.get_map();
			}
			case 2:{
				if(vec[y][x-1]!='*'){
					x--; 
					init_pair('O', COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR('O'));
					move(y, x);
					addch('O');
					count ++;
					attroff(COLOR_PAIR('O'));
					break;
				}
				vec = e.get_map();
			}
			case 3:{
				if(vec[y][x+1]!='*'){
					x++; 
					init_pair('O', COLOR_GREEN, COLOR_BLACK);
				attron(COLOR_PAIR('O'));
					move(y, x);
					addch('O');
					attroff(COLOR_PAIR('O'));
					count ++;
					break;
				}
				vec = e.get_map();
				}
	}
	vec[y][x]='O';
	e.UpdateMaze(y, x, 'O', 0);
	vec = e.get_map();
}}
		


