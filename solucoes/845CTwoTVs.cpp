// Problema 845C - Two TVs- https://codeforces.com/contest/845/problem/C 

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define par pair <lli, lli>

int main(){
    lli i, n, inicio, fim;
    cin>>n;

    par horarios[n];

    for (i=0; i<n;i++){
        cin>> inicio >> fim;
        horarios[i] = {inicio, fim};
    }

    sort(horarios,horarios+n);

    par tvUm = {0,0};
    par tvDois = {0,0};

    for (i=0; i<n;i++){
        if(tvUm.second<horarios[i].first){
            tvUm = {0,0};
        }

        if(tvDois.second<horarios[i].first){
            tvDois = {0,0};
        }

        if(tvUm.second == 0){
            tvUm = horarios[i];
        }else if(tvDois.second == 0){
            tvDois = horarios[i];
        }else{
            cout << "NO";
            return 0;
        }
    }

        cout << "YES";
        return 0;

}

