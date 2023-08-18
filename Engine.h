#ifndef Engine_h
#define Engine_h

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class Engine{
	public:
		vector <string> maze;
		int score= 0;
		int rows, col;
		int gameover;
	public:
		void Show(char* );
		void ShowGems();
		void ShowPerg();
		void CalcScore(int);
		int get_score();
		void ShowScore();

		vector<string> &get_map();
		int get_rows();
		int get_col();
		void UpdateMaze(int, int, char, int);
		int getGameOver();
		~Engine();
};
#endif