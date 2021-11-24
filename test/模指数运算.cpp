#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
    int i=0,x,bit[32]={0};
    cin>>x;//指数，小于32位
    for(i;x!=0;++i){
        bit[i]=x%2;
        x=x>>1;
    }
    int a,n,s=1;//底数 模数
    cin>>a>>n;
    while(i--){
        s=s*s;
        if(bit[i]==1)s*=a;
        s%=n;
    }
    cout<<s<<endl;
}