
output: Engine.o Gnome.o HiScore.o Moving.o Potter.o OpenMaze.o
	g++ Engine.o Gnome.o HiScore.o Moving.o Potter.o OpenMaze.o -o output -lncurses
	
Engine.o: Engine.cpp Engine.h
	g++ -c Engine.cpp -lncurses

Gnome.o: Gnome.cpp Engine.h
	g++ -c Gnome.cpp -lncurses
	
HiScore.o: HiScore.cpp HiScore.h
	g++ -c HiScore.cpp -lncurses
	
Moving.o: Moving.cpp Moving.h
	g++ -c Moving.cpp -lncurses
	
Potter.o: Potter.cpp Potter.h
	g++ -c Potter.cpp -lncurses

OpenMaze.o: OpenMaze.cpp
	g++ -c OpenMaze.cpp -lncurses

clean:
	rm *.o output