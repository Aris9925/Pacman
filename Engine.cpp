#include "Engine.h"
#include <curses.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

Engine::~Engine(){
}
void Engine::Show(char* x){
	rows = 0;
	string Line;
	fstream fs;
	fs.open(x);
	start_color();
	while (getline(fs, Line)){
		rows++;
		maze.push_back(Line);
	}
		for(int i=0;i<maze.size();i++){
			
			init_pair('*', COLOR_YELLOW, COLOR_BLACK);
			attron(COLOR_PAIR('*'));
			printw("%s", maze[i].c_str());
			printw("\n");
			attroff(COLOR_PAIR('*'));
	}
	fs.close();
	col = maze[1].size();
}

int Engine::get_rows(){
	return rows;
}

int Engine::get_col(){
	return col;
}
void Engine::ShowGems(){
	srand(time(NULL));
	int cnt =0;
	for(int i=0;i<maze.size();i++){
			int y=rand()%22;
			int x=rand()%75;
			if(maze[y][x]!='$' && maze[y][x]!='*' && maze[y][x]!='@'){
				init_pair('$', COLOR_MAGENTA, COLOR_BLACK);
				attron(COLOR_PAIR('$'));
				move(y, x);
				addch('$');	
				maze[y][x]='$';
				cnt++;
				attroff(COLOR_PAIR('$'));
		}
		
		if (cnt == 10) break;
	}


}	


void Engine::ShowPerg(){
	srand(time(NULL));
	for (int i=0;i<maze.size();i++){
		int y = rand()%22;
		int x=rand()%75;
		if(maze[y][x]!='*' && maze[y][x]!='@' && maze[y][x]!='$'){
				init_pair('#', COLOR_WHITE, COLOR_BLACK);
				attron(COLOR_PAIR('#'));
			move(y, x);
			addch('#');
			maze[y][x]='#';
			attroff(COLOR_PAIR('#'));
			break;
		}
		break;
	}
}

void Engine::CalcScore(int cnt){
	score = 0;
	if (cnt == 100){
		score = cnt + 100;
		
	}
	else{
		score = cnt * 10;
	}
}

void Engine::ShowScore(){
	cout << score;

}

vector<string>& Engine::get_map(){
	return maze;
}


void Engine::UpdateMaze(int y, int x, char str, int z){
	if(maze[y][x] == '$' && z==0){
		maze[y][x] = '$';
	}
	else
		maze[y][x] = str;

}


int Engine::get_score(){
	return score;
}

int Engine::getGameOver(){
	return gameover;
}


