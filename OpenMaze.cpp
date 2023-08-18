#include <iostream>

#include <random>
#include <curses.h>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include "Potter.h"
#include "Engine.h"
#include "Moving.h"
#include "Gnome.h"
#include "HiScore.h"


using namespace std;

int main(int argc, char *argv[]) {
	int curx = 1, cury = 1;
	int gameover;
	if(argc < 3){
		cout << "Invalid maze file or score file. Try again!!!" << endl;
		return 0;
	}


//Δημιουργια χαρτη και παικτων h
	Engine e;
	Gnome g;
	Gnome g2;
	Potter p;

//ncurses
	initscr();
		curs_set(0);

	//noecho();
	//cbreak();
	clear();
	int y, x;
	getmaxyx(stdscr, y, x);
	WINDOW * win = newwin(16, x-10, y-30, 5);
	//box(win, 0, 0);
	//wattron(win, COLOR_PAIR(1));
	//init_pair(1, COLOR_RED, COLOR_WHITE);
	refresh();
	wrefresh(win);
	keypad(win, true);
	
	
	mvwprintw(win, 7, 50, "WELCOME TO MPAMPI'S GAME...");
	mvwprintw(win, 8, 40, "IF YOU WANT TO START THE GAME PRESS ANY BUTTON...");
	wrefresh(win);
	
	
	
	getch();
	endwin();
	
	initscr();
	clear();
	curs_set(0);
	e.Show(argv[1]);
	e.ShowGems();
	
	g.ShowGnome(e);
	g2.ShowGnome2(e);
	p.ShowPotter(e);
	
	curs_set(0);
	p.Move(e, g, g2);
	refresh();
	getch();
	endwin();
	
	gameover = e.getGameOver();
	if(gameover == 1){
		initscr();
		clear();
		curs_set(0);
		int f,g;
		getmaxyx(stdscr, f, g);
		WINDOW * win1 = newwin(16, g-10, f-30, 5);

		refresh();
		wrefresh(win1);
		keypad(win1, true);
		
		mvwprintw(win, 7, 50, "THE GAME IS OVER...");
		mvwprintw(win, 8, 40, "IF YOU WANT TO CONTINUE PRESS ANY BUTTON...");
		wrefresh(win);
		getch();
		endwin();
	}
	if(gameover == 2){
		initscr();
		clear();
		curs_set(0);
		int f,g;
		getmaxyx(stdscr, f, g);
		WINDOW * win1 = newwin(16, g-10, f-30, 5);

		refresh();
		wrefresh(win1);
		keypad(win1, true);
		
		mvwprintw(win, 7, 50, "CONGRATULATIONS. YOU WON...");
		mvwprintw(win, 8, 40, "IF YOU WANT TO CONTINUE PRESS ANY BUTTON...");
		wrefresh(win);
		getch();
		endwin();
	}
	
	system("clear");
	string name;
	cout << "Please insert your name: " << endl;
	cin >> name;
	int highscore = 0;
	highscore = e.get_score();	
	HiScore h;
	h.set_file(argv[2]);
	h != name;
	h < highscore;
	cout << endl << endl << endl;
	h.ShowScore();
    return 0;
}

	
	
	
	
