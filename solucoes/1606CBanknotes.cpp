// Problema 1606C - Banknotes - https://codeforces.com/contest/1606/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
    int total;
    cin >> total;

    vector <long long> potencia(10);
    potencia[0]=1;
    for(int i = 1; i<10; i++){
        potencia[i] = potencia[i-1] * 10;
    }

    while(total--){
        int n, k;
        cin >> n >> k;
        vector <long long> a(n);
        vector <long long> numTotal(n);

        long long somaTotal = 0;

        for (int i=0; i<n;i++){
            cin >> a[i];
        }

        for (int i =0; i<n;i++){
            if(k<0){
                break;
            }

            numTotal[i] = k+1;
            
            if(i!=(n-1)){
                numTotal[i] =  min(numTotal[i],potencia[a[i+1]]/(potencia[a[i]])-1);
            }

            k -= numTotal[i];
            somaTotal += numTotal[i]*potencia[a[i]];
        }

        cout << somaTotal << endl;
    }

    return 0;
}