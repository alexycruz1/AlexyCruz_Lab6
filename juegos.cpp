#include "juegos.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;

Game::Game(int id, string name, int year, string developers, string genre){
	this -> id = id;
	this -> name = name;
	this -> year = year;
	this -> developers = developers;
	this -> genre = genre;
}
	
int Game::getId(){
	return id;
}
	
string Game::toString()const{
	stringstream ss;
	ss << "El ID es: " << id << " y el nombre es: " << name;
	return ss.str();
}