#include "usuarios.h"
#include "juegos.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char*argv[]){
	int opcion;
	vector <User> usuarios;
	vector <Game> juegos;

	int continuar = 1;
	while(continuar == 1){
		cout << "-----------------------------------------------------" << endl;
		cout << "1.- Agregar usuario" << endl
		 	 << "2.- Modificar usuario" << endl
		 	 << "3.- Eliminar usuario" << endl
		 	 << "4.- Agregar un juego" << endl
			 << "5.- Eliminar un juego" << endl
			 << "6.- Listar usuarios" << endl
		 	 << "7.- Listar juegos" << endl
		 	 << "Ingrese una opcion: ";
		cin >> opcion;
		cout << "-----------------------------------------------------" << endl;
		cout << endl;

		if (opcion == 1){//agregar usuario
			string username, password;
			cout << "Ingrese el nombre de usuario: ";
			cin >> username;

			cout << "Ingrese el password: ";
			cin >> password;
			cout << endl;

			bool agregar = true;

			for (int i = 0; i < usuarios.size(); i++){
				if (usuarios[i].getUsername() == username){
					agregar = false;
				}
			}

			if (agregar){
				User s(username, password);
				usuarios.push_back(s);
			}
		 	
		}else if (opcion == 2){//Modificar usuario
			int opcion2;

			cout << "1.- Agregar juego" << endl
				 << "2.- Eliminar juego" << endl
				 << "3.- Modificar password" << endl
				 << "Ingrese una opcion: ";
			cin >> opcion2;

			if (opcion2 == 1){//modificar, agregar juego
				int id, indice1, indice2;
				bool agregar = false;
				string username, password;

				for (int i = 0; i < usuarios.size(); i++){
					cout << juegos[i].toString();
					cout << endl;
				}
				cout << endl;

				cout << "Ingrese el id del juego a agregar: ";
				cin >> id;

				for (int i = 0; i < juegos.size(); i++){
					if (juegos[i].getId() == id){
						agregar = true;
					}
				}

				cout << "Ingrese el username: ";
				cin >> username;

				cout << "Ingrese el password: ";
				cin >> password;

				for (int i = 0; i < usuarios.size(); i++){
					if ((usuarios[i].getUsername() == username)){
						agregar = true;
						indice1 = i;
					}
				}

				for (int i = 0; i < usuarios.size(); i++){
					if ((usuarios[i].getPassword() == password)){
						agregar = true;
						indice2 = i;
					}
				}

				if (indice1 == indice2){
					agregar = true;
				}else{
					agregar = false;
				}

				if (agregar){
					usuarios[indice1].addGame(id);
				}
				cout << endl;

			}else if (opcion2 == 2){//Modificar, eliminar juego
				cout << endl;
				int id, indice1, indice2;
				bool eliminar = false;
				string username, password;

				cout << "Ingrese el username: ";
				cin >> username;

				cout << "Ingrese el password: ";
				cin >> password;
				cout << endl;

				for (int i = 0; i < usuarios.size(); i++){
					if ((usuarios[i].getUsername() == username)){
						eliminar = true;
						indice1 = i;
					}
				}

				for (int i = 0; i < usuarios.size(); i++){
					if ((usuarios[i].getPassword() == password)){
						eliminar = true;
						indice2 = i;
					}
				}

				cout << "Los juegos son: " << endl;
				for (int i = 0; i < usuarios.size(); i++){
					if (i == indice2){
						cout << usuarios[i].gamesToString();
					}
				}
				cout << endl;

				cout << "Ingrese el id del juego a eliminar: ";
				cin >> id;


				if (indice1 == indice2){
					eliminar = true;
				}else{
					eliminar = false;
				}

				if (eliminar){
					usuarios[indice1].deleteGame(id);
				}
				
			}else if (opcion2 == 3){//modificar, modificar password
				cout << endl;
				string username, password;
				bool cambiar = false;

				cout << "Ingrese el username al que desea cambiar el password: ";
				cin >> username;

				cout << "Ingrese el nuevo password: ";
				cin >> password;

				for (int i = 0; i < usuarios.size(); i++){
					if ((usuarios[i].getUsername() == username)){
						cambiar = true;
					}

					if (cambiar){
						usuarios[i].setPassword(password);
					}
				}
			}
			cout << endl;

		}else if (opcion == 3){//eliminar usuario
			bool eliminar = false;
			string username;
			cout << "Ingrese el username: ";
			cin >> username;

			for (int i = 0; i < usuarios.size(); i++){
				if (usuarios[i].getUsername() == username){
					eliminar = true;
				}

				if (eliminar){
					usuarios.erase(usuarios.begin() + i);
				}
			}

		}else if (opcion == 4){//agregar un juego
			int id;
			string name;
			int year;
			string developers;
			string genre;
			bool agregar = true;

			cout << "Ingrese el id del juego: ";
			cin >> id;

			cout << "Ingrese el nombre del juego: ";
			cin >> name;

			cout << "Ingrese la fecha (2001) de creacion: ";
			cin >> year;

			cout << "Ingrese el developer: ";
			cin >> developers;

			cout << "Ingrese el genero: ";
			cin >> genre;
			cout << endl;

			for (int i = 0; i < juegos.size(); i++){
				if (juegos[i].getId() == id){
					agregar = false;
				}
			}

			if (agregar){
				Game g(id, name, year, developers, genre);
				juegos.push_back(g);
			}
			
		}else if (opcion == 5){//eliminar juego
			bool eliminar = false;
			int id;
			cout << "Ingrese el ID del juego a eliminar: ";
			cin >> id;

			for (int i = 0; i < juegos.size(); i++){
				if (juegos[i].getId() == id){
					eliminar = true;
				}

				if (eliminar){
					juegos.erase(juegos.begin() + i);
				}
			}

		}else if (opcion == 6){//listar usuarios
			for (int i = 0; i < usuarios.size(); i++){
				cout << usuarios[i].toString();
				cout << endl;
			}
			cout << endl;
		}else if (opcion == 7){//listar juegos
			for (int i = 0; i < usuarios.size(); i++){
				cout << juegos[i].toString();
				cout << endl;
			}
		}

		cout << "1.- Continuar" << endl;
		cout << "2.- Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> continuar;
		cout << endl;
	}

	return 0;
}