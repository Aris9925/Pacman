#ifndef Gnome_h
#define Gnome_h

#include <iostream>
#include "Moving.h"
#include <vector>
#include "Engine.h"
#include "Potter.h"
using namespace std;

class Gnome: public Moving
{
	protected:	
		int y, x;
		vector<string> vec;
	public:
		void ShowGnome(Engine& );
		void ShowGnome2(Engine& );
		
		void Move(Engine&, Moving&, Moving&);
		void Move2(Engine&, Moving&, Moving&);
		~Gnome();

};
#endif