#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
int b[1001];
int main(){
    int n,m,a;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a;
        b[a]++;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<b[i];++j){
            cout<<i<<" ";
        }
    }
}