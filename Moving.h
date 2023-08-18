#ifndef Moving_h
#define Moving_h

#include <iostream>
#include <vector>
#include "Engine.h"


class Moving: public Engine
{
	public:
		virtual void Move(Engine&, Moving&, Moving&) = 0;
		virtual void Move2(Engine&, Moving&, Moving&) = 0;
		~Moving();
		
};            
#endif