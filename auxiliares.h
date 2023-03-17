#include <iostream>
#include <vector>
#include <utility>
using namespace std;


bool gano(int a, vector<vector<int>> tablero);
void jugar(pair<int,int> pos,int j, vector<vector<int>>& tablero);
bool termino(vector<vector<int>> tablero);
void print(vector<vector<int>> m);
pair<int,int> posicion(int p);