#include<stdio.h>
#include<string.h>
int main(){
	int x,arr[100],n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		if(i!=n-1)scanf("%d,",&arr[i]);
		else scanf("%d",&arr[i]);
	}
	scanf("%d",&x);
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]<x){
			low=mid+1;
		}
		else if(arr[mid]==x) {
			printf("%d",mid+1);
			break;
		}
		else high=mid-1;
	}
	return 0;
}