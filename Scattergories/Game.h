#ifndef _GAME_ 
#define _GAME_
#include<iostream>
#include<vector>
#include<string>
#include"Player.h"
class Game{
private:
	std::vector<Player*> m_players;
	std::vector<std::string> m_categories;
	char m_randLetter; 
public:
	Game();
	void play();
	void instruction(); 
	void categories();
	void input();
	void timer();
	//error for adding player name since now Player class vector in Game 
	//THINGS TO WORK ON 
	//helper for comparing - BST of all the words, then go through a hash table of names? 
	//different format: category style 
	//have hash of users as well
	//compare also add up scores 
	
	//Timer & user change time (can switch the two above depending) 
	//being able to choose categories: use filestream to add on 
	//graphics?
};

#endif