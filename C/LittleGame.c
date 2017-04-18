#include <stdio.h>
#include <stdlib.h>
void readMap(const size_t map_size);
void printMap (const size_t map_size);
void move(size_t map_size, int *is_alive, int *is_stop);
char dire,map[15][15]={};
int human_x = 0, human_y = 0;
int main(){
	int alive=5,stop=5,n,j;
	int *is_alive, *is_stop;
	is_alive=&alive;
	is_stop=&stop;
	int move_size, map_size;
	scanf("%d",&move_size);getchar();
	map_size=move_size+2;
	readMap(map_size);
	for(n=0; n<map_size; n++){
		for(j=0; j<map_size; j++)
			if(map[n][j]=='A'){
				human_x = j;
				human_y = n;
				break;
			}
		if(human_x != 0)
			break;
	}
	while(scanf(" %c",&dire) != EOF){
		move(map_size, is_alive, is_stop);
		if(*is_alive==0)
			break;
	}
}
void move(size_t map_size, int *is_alive, int *is_stop){
	if(*is_stop != 1){
		if(dire=='a'){//left
			if(human_x==1){
				map[human_y][human_x]=' ';
				map[human_y][map_size-2]='A';
				human_x=map_size-2;
			}
			else if(map[human_y][human_x-1]=='@'){
	  			*is_stop=1;
	  			map[human_y][human_x-1]='A';
	  			map[human_y][human_x]=' ';
	  			human_x--;
			}
			else if(map[human_y][human_x-1]=='$')
				*is_alive=0;
			else if(map[human_y][human_x-1]==' '){
				map[human_y][human_x-1]='A';
				if(*is_stop==0){
					map[human_y][human_x]='@';
					*is_stop=5;
				}
				else
					map[human_y][human_x]=' ';
				human_x--;
				}
		}
		if(dire=='d'){//right
			if(human_x==map_size-2){
				map[human_y][human_x]=' ';
				map[human_y][1]='A';
				human_x=1;
			}
			else if(map[human_y][human_x+1]=='@'){
				*is_stop=1;
				map[human_y][human_x+1]='A';
				map[human_y][human_x]=' ';
				human_x++;
			}
			else if(map[human_y][human_x+1]=='$')
				*is_alive=0;
			else if(map[human_y][human_x+1]==' '){
				map[human_y][human_x+1]='A';
				if(*is_stop==0){
					map[human_y][human_x]='@';
					*is_stop=5;
				}
				else
					map[human_y][human_x]=' ';
				human_x++;
				}
		}
		if(dire=='w'){//up
			if(human_y==1){
				map[map_size-2][human_x]='A';
				map[human_y][human_x]=' ';
				human_y=map_size-2;
			}
			else if(map[human_y-1][human_x]=='@'){
				*is_stop=1;
				map[human_y-1][human_x]='A';
				map[human_y][human_x]=' ';
				human_y--;
			}
			else if(map[human_y-1][human_x]=='$')
				*is_alive=0;
			else if(map[human_y-1][human_x]==' '){
				map[human_y-1][human_x]='A';
				if(*is_stop==0){
					map[human_y][human_x]='@';
					*is_stop=5;
				}
				else
					map[human_y][human_x]=' ';
				human_y--;
				}
		}
		if(dire=='s'){//down
			if(human_y==map_size-2){
				map[1][human_x]='A';
				map[human_y][human_x]=' ';
				human_y=1;
			}
			else if(map[human_y+1][human_x]=='@'){
				*is_stop=1;
				map[human_y+1][human_x]='A';
				map[human_y][human_x]=' ';
				human_y++;
			}
			else if(map[human_y+1][human_x]=='$')
				*is_alive=0;
			else if(map[human_y+1][human_x]==' '){
				map[human_y+1][human_x]='A';
				if(*is_stop==0){
					map[human_y][human_x]='@';
					*is_stop=5;
				}
				else
					map[human_y][human_x]=' ';
				human_y++;
				}
		}
	}
	else if(*is_stop==1){
		*is_stop=0;
	}
	if(*is_alive==0)
		printf("Game Over!\n");
	else
		printMap (map_size);
}

void readMap(const size_t map_size){
	int n;
	for(n=0; n<map_size; n++)
		fgets(map[n], 30, stdin);
}

void printMap (const size_t map_size){
	int n;
	for(n=0; n<map_size; n++)
		printf("%s",map[n]);
}
