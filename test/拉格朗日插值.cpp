#include<vector>
#include<iostream>
using namespace std;
vector<float>x,y;

float xx,k,a,b;

float lianc(int j){
    float l=1;
    for(int i=0;i<k;i++){
        if(i==j)continue;
        l*=(xx-x[i])/(x[j]-x[i]);
    }
    return l;
}

float sum(){
    float s=0;
    for(int i=0;i<k;i++){
        s+=y[i]*lianc(i);
    }
    return s;
}

int main(){
    cin>>k;    
    for(int i=0;i<k;i++){
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    cin>>xx;
    cout<<sum();
}