#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node* next;
} node ;
int n; 
int size; // the size of linked list
node* head; // the head of linkedlist

//insert the value to the right position
//if the position is not valid, return false
//if insert successfully, return true
bool insert(int position, int value);

// return the value in the given position
int get(int position);

//clear the linkedlist, remember to free the memory you allocated
void clear();

int get(int position){
	node *pointer;
	pointer=head;
	for(n=0; n<position; n++){
		pointer=pointer->next;
	}
	return pointer->value;
}

void clear(){
  node *pointer[size];
	for(n=0; n<size; n++){
		pointer[n]=head;
    head=head->next;
	}
  for(n=0; n<size; n++)
    free(pointer[n]);
}

bool insert(int position, int value){
	int i;
	if(position<0 || position >size){
		return 0;
  }
	else{
		if(head==NULL){//no data
			head=(node *)malloc(sizeof(node));
			(*head).value=value;
			(*head).next=NULL;
			size++;
			return 1;
		}
		else{
      		node* current;
			node* nextone;
			node* insert=(node* )malloc(sizeof(node));
			current=head;
			nextone=head;
			if(position==0){
				nextone=head;
				head=insert;
				head->value=value;
				head->next=nextone;
			}
			else{
				for(n=0; n<position; n++){//find position to connect
					nextone=nextone->next;
				}
				for(i=0; i<position-1; i++){//find position to insert
					current=current->next;
				}
				current->next=insert;
				insert->value=value;//assign value
				if(position==size)//assign next pointer
					insert->next=NULL;
				else
					insert->next=nextone;
			}
				size++;
     
				return 1;
		}
	}
}
void print() {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", get(i));
	}
	printf("\n");
}


int main() {
	head = NULL;
	size = 0;
	int n, i, position, value;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &position, &value);
		if (insert(position, value)) {
			print();
		} else {
			printf("position is not valid\n");
		}
	}
	clear();
	return 0;
}
