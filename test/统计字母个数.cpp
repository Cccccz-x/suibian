#include<cstdio>
using namespace std;
int main(){
    char a[]="cqvjlvovqqtvoevvwshwbjmzrooevtzuhv";
    int i=0,count[26];
    char b[26];
    b[0]='a';
    for(int i=0;i<=25;++i){
        count[i]=0;
        b[i]=b[0]+i;
        }
    
    for(int i=0;a[i]!='\0';++i){
        for(int j=0;j<=25;++j){
            if(a[i]==b[j]){ 
                count[j]++;
                continue;
            }
        }
    }
    for(int i=0;i<=25;++i)
    printf("%d",count[i]);
}