#include "usuarios.h"
#include <string>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;
using std::endl;

User::User(string username, string password){
	this->username = username;
	this->password = password;
}

bool User::addGame(int id){
	bool repetido = false;
	for (int i = 0; i < games.size(); i++){
		if (games[i] == id){
			repetido = true;
		}
	}

	if (repetido == false){
		games.push_back(id);
	}
	return repetido;
}

bool User::deleteGame(int id){
	bool encontrado = false;
	int indice;
	for (int i = 0; i < games.size(); i++){
		if (games[i] == id){
			encontrado = true;
			indice = i;
		}
	}

	if (encontrado){
		games.erase(games.begin() + indice);
	}
	return encontrado;
}

void User::changePassword(string password, string username){

}

void User::setPassword(string password){
	this -> password = password;
}
	
string User::getUsername(){
	return username;
}

string User::getPassword(){
	return password;
}
	
bool User::isValidPassword(string username, string password){
	
}

string User::toString()const{
	stringstream ss;
	ss << "El usuario es: " << username << " y el password es: " << password << endl;
	ss << "Los juegos son: ";
	for (int i = 0; i < games.size(); ++i){
		ss << games[i] << endl;
	}

	return ss.str();
}

string User::gamesToString()const{
	stringstream ss;

	for (int i = 0; i < games.size(); ++i){
		ss << games[i] << endl;
	}

	return ss.str();
}
