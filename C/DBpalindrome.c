#include <stdio.h>
#include <math.h>
int output(int i);
int main(){
	int com,cases,n,integer,s=0;
	scanf("%d",&cases);
	for(n=0; n<cases; n++){
		scanf("%d",&integer);
		for(com=integer+1;com<1000000;com++){
		s=output(com);
		if(s!=0)
			break;
		}
	}
	return 0;
}
int output(int i){
	int m,j,count=0;
	int p=0;
	int num[100];
	int cpr=i;
	for(j=2; j<=10; j++){
		for(m=0;i!=0;m++){
			num[m]=i%j;
			i=i/j;
		}
		int a=m-1,b=m;
		for(m=0; m<b; m++){
			if(num[m]==num[a]){
				a--;
				continue;
			}
			else
				break;
		}
		if(m==b)
			count++;
		if(count>=2)
			break; 
		i=cpr;
	}
	if(count>=2){
		printf("%d\n",cpr);
		p=cpr;
	}
	return p;
}
