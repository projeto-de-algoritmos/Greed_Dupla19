// Problema 1642B - Power Walking - https://codeforces.com/problemset/problem/1642/B

#include <bits/stdc++.h>
using namespace std;

int main (){
    int total;
    cin >> total;

    while(total--){
        int n;
        cin >> n;

        set<int>dist;
        vector<int> a(n+1);;

        for (int i= 1; i<=n; i++){
            cin >> a[i];
            dist.insert(a[i]);
        }

        int nDist = dist.size();

        for (int i =1; i<=nDist;i++){
            cout << nDist << endl;
        }

        for (int i=nDist+1; i<=n; i++){
            cout << i << endl;
        }
    }
}