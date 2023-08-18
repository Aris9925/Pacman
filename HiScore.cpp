#include "HiScore.h"

#include <fstream>


using namespace std;

HiScore::~HiScore(){
}
void HiScore::set_file(char *file){
	fileName = file;
}

void HiScore::operator!=(string name1){

	name = name1;

}



void HiScore::operator<(int score){
	int op;
	score = score;
	fstream file;
	file.open(fileName, ios::in|ios::out|ios_base::app);
	if(!file.is_open())	op = 0;
	else op=1;
	if(op == 0){
		ofstream f(fileName);
		f<< "NAME: " << name << "--------------------------------------"<< "SCORE: " << score << endl;
		f.close();
	}
	else if (op == 1){
		file<< "NAME: " << name << "--------------------------------------" << "SCORE: " << score << endl;
		file.close();
	}
}

void HiScore::ShowScore(){
	string text;
	ifstream file(fileName);
	cout << "SCORES" << endl;
	while(getline(file, text)){
		cout << text << endl;
	}
	file.close();
}
		
		

