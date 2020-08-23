#include"Game.h"
#include"utilities.h"
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<chrono>
using namespace std;
Game::Game(){
	srand(time(NULL));
	char randChar = rand() % 24 + 67;
	m_randLetter = randChar;
}
void Game::play() {
	cout << setw(70) << "WELCOME TO CATOS-GORIES"<<endl;
	instruction();
	cout << "Input Number of Players: ";
	int inputPlayer;
	cin >> inputPlayer;
	//storing the player names
	for (int i = 1; i <= inputPlayer; ++i) {
		string playerName;
		cout << "Input the name of Player "<<i<<": ";
		cin >> playerName;
		//m_players.push_back(playerName);
	}
	cout << "Your randomly chosen letter is: "<< m_randLetter <<endl;
	categories();
	cout << '\n'<<setw(90)<<"You now have 120 seconds to come up with words. Your time starts NOW!\n\n";
	timer();
	input();
	//helper function name - hash table for players and their answers too? 
	//helper function: compare 
}

void Game::instruction() {
	cout << "Do you need instructions? Please enter Y/N ";
	char instruction;
	cin >> instruction;
	if (instruction == 'Y' || instruction == 'y') {
		clearScreen();
		ifstream readFile("C:\\Users\\carol\\Desktop\\Scattergories\\Instructions.txt");
		string line; 
		if (!readFile) {
			cout << "not exist";
		}
		else {
			while (!readFile.eof()) {
				getline(readFile, line);
				cout << line << endl;
			}
		}
		readFile.close();
		cout <<"Press any key to resume game";
		int getch();
		int i = getch();
		clearScreen();
		cout << setw(70) << "WELCOME TO CATOS-GORIES"  << endl;
	}
}

void Game::categories(){
	cout << "Your 12 Catos-gories are: "<<endl;
	ifstream categoryFile("C:\\Users\\carol\\Desktop\\Scattergories\\categories.txt");
	if (!categoryFile) {
		cout << "not exist";
	}
	string name;
	for (int i = 1; i < 13; ++i) {
		//could come up with better random number? - works bc keep going through file, have many categories (add more?) 
		int randNum = rand() % 15;
		int counter = 0;
		while (!categoryFile.eof()) {
			getline(categoryFile, name);
			if (randNum == counter) {
				m_categories.push_back(name);
				cout << i << '.' << name << endl;
				break;
			}
			++counter;
		}
	}
	categoryFile.close();
}

void Game::input() {
	for (int j = 0; j < m_categories.size(); ++j) {
		for (int i = 0; i < m_players.size(); ++i) {
			string word;
			cout << "For " <<"Category "<< j+1 << " , please enter " << m_players[i] << "'s word: ";
			cin >> word;
		}
	}
}

void Game::timer() {
	int time = 120;
	std::cout << setw(70)<<"BEGIN - timer has started\n";
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()+ std::chrono::seconds(120);
	while (std::chrono::steady_clock::now() < tend)
	{

	}
	std::cout << setw(65)<< "\n==TIME'S UP==\n";
}