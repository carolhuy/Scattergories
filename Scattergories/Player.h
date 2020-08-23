#ifndef _PLAYER_
#define _PLAYER_
#include<iostream>
#include<vector>
class Player {
	std::string p_name;
	std::vector<std::string> p_cat;
	int p_points;
public:
	//Accessors
	std::string getName();
	int getPoints();
	std::vector<std::string> getWords(); 
	//Modifiers
	void setName();
	void setPoints();
	void setWords();
};
#endif