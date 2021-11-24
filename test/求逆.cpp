#include<iostream>
#include<bitset>
using namespace std;
//gcd
int gcd(int a,int b){
    if(a<b)swap(a,b);
    a%=b;
    if(a==0)return b;
    return gcd(b,a);
}
//枚举
int mj(int x,int n){
    x%=n;
    if(gcd(x,n)!=1){
        cout<<"NONE";
        return 0; 
    }
    for(int i=1;i<n;i++){
        if(x*i%n==1) return i;
    }
    cout<<"NONE";
    return 0;
}
//欧几里得
//gcd pro
void gcdp(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    gcdp(b,a%b,y,x);
    y-=a/b*x;
}

int ojld(int x,int n){
    x%=n;
    if(gcd(x,n)!=1){
        cout<<"NONE";
        return 0;
    }
    int xx,yy;
    gcdp(x,n,xx,yy);
    while(xx<0){
        xx+=n;
    }
    return xx;
}

//费马小定理(有局限性，p只能为质数)
//a^(p-1)=1(mod p)
//a*a^(p-2)=1(mod p)
//a^(p-2)mod p即是
int fm(int a,int n){
    //快速幂1
    int m=n-2,i;
    bitset<32>b;
    for(i=0;m>0;++i){
        b[i]=m&1;
        m>>=1;
    }
    int l=i-1,j=1;
    for(i=l;i>=0;--i){
        j=(j*j) % n;
        if(b[i]==1){
            j=j*a % n;
        }
    }
    return j;
}
int fpow(int a,int n){
    //快速幂2 没写mod n
    int j=1;
    while(n){
        if(n&1) j*=a;
        a*=a;
        n>>=1;
    }
    cout<<j;
    return j;
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<fpow(x,y);
    
    return 0;
}