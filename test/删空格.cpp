#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
void deleteblank(char*,char*);
int main(){
    char a[100]="1011 1100 0011 0001 0010 1011 0001";
    char b[100];
    deleteblank(a,b);
    printf("%s",b);
    return 0;
}
void deleteblank(char*a,char*b){
    int n=strlen(a);
    
    for(int i=0,j=0;i<n;++i){
        if(a[i]!=' '){
            b[j++]=a[i];
        }
    }
    return;
}