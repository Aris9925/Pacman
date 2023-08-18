#ifndef Potter_h
#define Potter_h

#include <iostream>
#include "Moving.h"
#include <vector>
#include "Engine.h"
//#include "Gnome.h"
using namespace std;

class Potter: public Moving
{
	protected:
		int y, x, gameover;
		vector <string> vec;
		//int cnt=0;
		

	public:
		void ShowPotter(Engine&);
		void Move(Engine&, Moving&, Moving&);
		void Move2(Engine&, Moving&, Moving&);
		~Potter();

};

#endif