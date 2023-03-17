#include <iostream>
#include <vector>
#include <utility>
#include "auxiliares.h"
using namespace std;



int main() {
    vector<vector<int>> tablero(3,vector<int>(3,0));
    vector<vector<int>> posiciones = {{1,2,3},{4,5,6},{7,8,9}};
    int j1=1,j2=2;
    int p;
    while(!gano(j1,tablero) and !gano(j2,tablero) and !termino(tablero)){
        //JUGADOR 1
        cout<<endl<<"Jugador 1 ingrese posicion a jugar"<<endl<<endl;
	    cout<<"Posiciones:"<<endl;
        print(posiciones);
        cout<<endl;
        cout<<"Juego actual"<<endl;
        print(tablero);
        cin>> p;
        pair<int,int> pos = posicion(p);
        while(tablero[pos.first][pos.second] != 0){
            cout<<endl<<"Posicion ya jugada"<<endl<<endl;
            cout<<"Jugador 1 ingrese posicion a jugar"<<endl;
	        cout<<"Posiciones:"<<endl;
            print(posiciones);
            cout<<endl;
            cout<<"Juego actual"<<endl;
            print(tablero);
            cin>> p;
            pos = posicion(p);
        }
        jugar(pos,j1,tablero);

        if(!gano(j1,tablero) and !termino(tablero)) {

            //JUGADOR 2
            cout <<endl<< "Jugador 2 ingrese posicion a jugar" << endl << endl;
            cout << "Posiciones:" << endl;
            print(posiciones);
            cout<<endl;
            cout<<"Juego actual"<<endl;
            print(tablero);
            cin >> p;
            pos = posicion(p);
            while (tablero[pos.first][pos.second] != 0 and !termino(tablero)) {
                cout <<endl<< "Posicion ya jugada" << endl << endl;
                cout << "Jugador 2 ingrese posicion a jugar" << endl;
                cout << "Posiciones:" << endl;
                print(posiciones);
                cout<<endl;
                cout<<"Juego actual"<<endl;
                print(tablero);
                cin >> p;
                pos = posicion(p);
            }
            jugar(pos, j2, tablero);

        }
    }
    if(gano(j1,tablero)){
        cout << "GANADOR JUGADOR 1" <<endl;
    } else if(gano(j2,tablero)){
        cout << "GANADOR JUGADOR 2" <<endl;
    } else {
        cout <<"EMPATE"<<endl;
    }
    print(tablero);
}
