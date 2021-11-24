#include<bits/stdc++.h>
using namespace std;

typedef vector<short> bigint;
typedef unsigned long long ULL;
void print(bigint c){
    reverse(c.begin(),c.end());
    for(auto i:c)cout<<i;
}
bigint ulltobigint(ULL n){
    bigint res;
    while(n){
        res.push_back(n%10);
        n/=10;
    }
    return res;
}
bigint add(bigint a,bigint b){
    auto maxz=max(a.size(),b.size()),minz=min(a.size(),b.size());
    bigint res;
    short carry=0;
    for(int i=0;i<minz;++i){
        auto c=a[i]+b[i]+carry;
        res.push_back(c%10);
        carry=c/10;
    }
    a=a.size()>b.size()?a:b;
    for(int i=minz;i<maxz;++i){
        auto c=carry+a[i];
        res.push_back(c%10);
        carry=c/10;        
    }
    if(carry)res.push_back(carry);
    return res;
}
bigint sub(bigint a,bigint b){
    //假定a大
    bigint res;
    short carry=0;
    for(int i=0;i<b.size();i++){
        auto c=a[i]-b[i]-carry;
        carry=0;
        if(c<0){
            carry=1;
            c+=10;
        }
        res.push_back(c);
    }
    for(int i=b.size();i<a.size();i++){
        auto c=a[i]-carry;
        if(c<0){
            carry=1;
            c+=10;
            res.push_back(c);
        }
        else{
            res.push_back(c);
            for(int j=i+1;j<a.size();j++){
                res.push_back(a[j]);
            }
            break;
        }
    }
    return res;
}
bigint leftshift(bigint a,int n){
    bigint res;
    while(n--)res.push_back(0);
    for(auto i:a)res.push_back(i);
    return res;
}
bigint karatsuba(bigint a,bigint b){
    while(a.size()<b.size()) a.push_back(0);
    while(a.size()>b.size()) b.push_back(0);
    bigint res,la,lb,ra,rb,lalb,rarb,lr;
    if(a.size()==0)return ulltobigint(0);
    if(a.size()==1)return ulltobigint(a[0]*b[0]);
    int m=a.size()/2,sz=a.size();
    for(int i=0;i<m;i++){
        rb.push_back(b[i]);
        ra.push_back(a[i]);
    }
    for(int i=m;i<a.size();++i){
        la.push_back(a[i]);
        lb.push_back(b[i]);
    }
    lalb=karatsuba(la,lb);
    rarb=karatsuba(ra,rb);
    lr=sub(sub(karatsuba(add(la,ra),add(lb,rb)),rarb),lalb);
    lalb=leftshift(lalb,m*2);
    lr=leftshift(lr,m);
    res=add(add(lalb,rarb),lr);
    return res;
}
int main(){
    for(int i=0;i<10;i++)cout<<i<<endl;
    print(karatsuba(ulltobigint(114555),ulltobigint(11144)));
    cout<<endl<<114555*11144<<endl;
    print(sub(ulltobigint(5844522),ulltobigint(1058860)));
    cout<<5844522-1058860;
}