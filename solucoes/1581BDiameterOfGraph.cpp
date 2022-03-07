// Problema 1581B - Diameter of Graph - https://codeforces.com/contest/1581/problem/B
// Referência teoria de grafos: https://www.youtube.com/watch?v=OAtOVNMdqkk&t=34s 

#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(){
    int total;
    cin >> total; 

    while(total--){
        lli nos, arestas, diametro;
        cin >> nos >> arestas >> diametro;
        diametro -=2;

        if(arestas<(nos-1)){
            cout << "NO" << endl;
        }else if (arestas>nos*(nos-1)/2){
            cout << "NO" << endl;
        }else if (diametro<=-1){
            cout << "NO" << endl;
        }else if (diametro == 0 ){
            if(nos == 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if( diametro == 1){
            if(arestas == nos * (nos -1)/2){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "YES" << endl;
        }
    }

    return 0;

}