#pragma once
#include <string>
#include <vector>
#include <cstring>

using std::string;
using std::vector;

class User{
	string username;
	string password;
	vector <int> games;
public:
	User(string, string);
	bool addGame(int id);
	bool deleteGame(int id);
	void changePassword(string password, string username);
	string getUsername();
	string getPassword();
	void setPassword(string password);
	bool isValidPassword(string username, string password);
	string toString()const;
	string gamesToString()const;
};