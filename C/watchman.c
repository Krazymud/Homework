#include <stdio.h>
void escape(int m,int s, int t);
int main(){
	int magic, far, time_left;
	while(scanf("%d%d%d",&magic,&far,&time_left) != EOF)
		escape(magic,far,time_left);
	
} 
void escape(int m,int s,int t){
	int time;
	int dis=s;
	for(time=t; time>0; time--){
		if(m>=10){
			m-=10;
			s-=60;
		}
		else{
			if(s<=17){
				s-=17;
			}
			else{
				if(m>=6 && time>=2){
					m+=4;
					continue;
				}
				else if(time>=2){
					if(s<=34){
						s-=34;
						time-=1;
					}
					else{
						if(m>=2){
							m+=8;
							s-=60;
							m-=10;
							time-=2;
						}
						else if(m<2){
							s-=17;	
							continue;
						}
					}	
				}
				else if(time<2)
					s-=17;
			}
		}
		if(s<=0){
			time--;
			break;
		}
	}
	if(s<=0){
		printf("Yes\n");
		printf("%d\n",t-time);	
	}
	else{
		printf("No\n");
		printf("%d\n",dis-s);
	}
}
