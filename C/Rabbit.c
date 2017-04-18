// num should be equal to or smaller than 44
#include <stdio.h>
#include <math.h>
void birth(int );
int sum;
int main(){
	int num;
	while(scanf("%d",&num) != EOF){
		sum=1;
		if(num<3)
			printf("2\n");
		else{
			int time=num;
			birth(time);
			printf("%d\n",sum*2);
		}	
	}
	return 0;
}

void birth(int time){
	int t; 
	for(t=time-2; t>0; t--){
		sum+=1;
		birth(t);
	}
}
