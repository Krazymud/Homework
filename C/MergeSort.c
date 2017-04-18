#include <stdio.h>
int print;
void mergesort(int m[], int start, int end_1, int end_2, int com){//¹é²¢ 
	int i,y,min;
	min=m[start];
	for(y=start; y<end_1; y++){
		min=m[y];
		for(i=end_1; i<end_2; i++){
			if(m[i]<min){
				min=m[i];
				m[i]=m[y];
				m[y]=min;
			}
		}
	}
	for(y=end_1; y<end_2; y++){
		min=m[y];
		for(i=y; i<end_2; i++){
			if(m[i]<min){
				min=m[i];
				m[i]=m[y];
				m[y]=min;
			}
		}
	}
	for(y=0; y<com; y++){
		if(y<com-1)
		printf("%d ",m[y]);
		else 
		printf("%d",m[y]);
	}
	printf("\n");		
}
void mergepart(int a[], int first,int last){//·Ö½â 
	int mid;
	mid=((last-first)%2==0)?(first+(last-first)/2):(first+(last-first)/2+1);
	if(first<mid-1){
		mergepart(a,first,mid);
		mergepart(a,mid,last);
	}
	if(mid != last)
	mergesort(a,first,mid,last,print);
}
int main(){
	int n,num;
	scanf("%d",&num);
	int integer[num];
	for(n=0; n<num; n++)
		scanf("%d",&integer[n]);
	print=num;
	mergepart(integer,0,num);
} 
