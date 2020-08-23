#include"Player.h"

//Accessors
std::string Player::getName(){
	return p_name;
}
int Player::getPoints(){
	return p_points;
}
std::vector<std::string> Player::getWords(){
	return p_cat; 
}

//Modifiers
void Player::setName(){}
void Player::setPoints(){}
void Player::setWords(){}