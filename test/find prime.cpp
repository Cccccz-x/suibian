#include<stdio.h>
#include<math.h>
int main(){
	int n,flag;
	int r=scanf("%d",&n);
	if(r!=1||n<=1){
		printf("error");
		return 0;
	}
	for(int i=1;i<=n;++i){
		flag=1;
		for(int j=2;j<=sqrt(float(i));++j){
			if(i%j==0){
				flag=0;	
				break;
			}
		}
		if(flag==1){
			printf("%d,",i);
		}
	}
	return 0;
}