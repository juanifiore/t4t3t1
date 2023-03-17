#include <iostream>
#include <vector>
#include <utility>
#include "auxiliares.h"
using namespace std;

pair<int,int> posicion(int p){
    pair<int,int> p1(0,0),p2(0,1),p3(0,2),p4(1,0),p5(1,1),p6(1,2),p7(2,0),p8(2,1),p9(2,2);
    vector<pair<int,int>> posiciones = {p1,p2,p3,p4,p5,p6,p7,p8,p9};
    return posiciones[p-1];
}


void jugar(pair<int,int> pos,int j, vector<vector<int>>& tablero){
    tablero[pos.first][pos.second] = j;
}

bool esFila(int a, vector<vector<int>> tablero){
    bool res=false;
    int n=tablero.size(),m=tablero[0].size();
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<m;j++){
            if(tablero[i][j]==a)
                k++;
        }
        if(k==3)
            res=true;
    }
    return res;
}

bool esColumna(int a, vector<vector<int>> tablero) {
    bool res = false;
    int n = tablero.size(), m = tablero[0].size();
    for (int j = 0; j < m; j++) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (tablero[i][j] == a)
                k++;
        }
        if (k == 3)
            res = true;
    }
    return res;
}

bool esDiagonal(int a, vector<vector<int>> tablero){
    bool res=false;
    if(tablero[0][0]==a and tablero[1][1]==a and tablero[2][2]==a)
        res=true;
    if(tablero[0][2]==a and tablero[1][1]==a and tablero[2][0]==a)
        res=true;
    return res;
}

bool gano(int a, vector<vector<int>> tablero){
    return esFila(a,tablero) or esColumna(a,tablero) or esDiagonal(a,tablero);
}

bool termino(vector<vector<int>> tablero){
    bool res=true;
    for(int i=0;i<tablero.size();i++){
        for(int j=0;j<tablero[0].size();j++){
            if(tablero[i][j]==0)
                res = false;
        }
    }
    return res;
}

void print(vector<vector<int>> m){
    for(int i=0;i<m.size();i++){
        cout << "[";
        for(int j=0;j<m[0].size()-1;j++){
            cout << m[i][j] << " , ";
        }
        cout << m[i][m[0].size()-1] << " ]" << endl;
    }
    cout << endl<<endl;
}

/*
int k=0;
int i=0,j=0,b=0;
while(i<2 and b==0){
while(j<2 and b==0){
k++;
if(k==p) {
b = 1;
} else {
j++;
}
}
if(k==p) {
b = 1;
} else {
i++;
}
}
return make_pair(i,j);
 */