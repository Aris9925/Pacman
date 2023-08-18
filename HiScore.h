#ifndef HiScore_h
#define HiScore_h

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
class HiScore{

	string name;
	int score;
	char *fileName;
	public:
		void operator!=(string);
		void operator<(int);
		void ShowScore();
		void set_file(char *);
		~HiScore();
		
	
};
#endif
