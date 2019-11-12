#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//#include<windows.h>
struct Node{
	int Data;
	struct Node *next;
};
typedef struct Node *node;
         node start;
         node newnode;
       	node tmp;
void create_link(int info){// function to create a linked list
	newnode = (node)malloc(sizeof(node));
	newnode->Data=info;
	newnode->next=NULL;
      if(start==NULL){
      	start=newnode;
      }
	else{
		tmp=start;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=newnode;
		
	}
	
}

void AddBegin(int info){// function to add a linked list at the begining

	newnode=(node*)malloc(sizeof(node));
	newnode->Data=info;
	if(start==NULL){
		newnode->next=NULL;
	}
	else
   newnode->next=start;
   start=newnode;
 printf("The element add at the begining sucessfully\n\n");
}
void AddEnd(int info){
 newnode=(node*)malloc(sizeof(node));
 newnode->Data=info;
 newnode->next=NULL;
 if(start==NULL){
 	start=newnode;
 }	
 else{
 	tmp=start;
 	while(tmp->next!=NULL)
 		tmp=tmp->next;
 	}
 	tmp->next=newnode;
 	printf("node added at the end sucessfully\n\n");
 
}
void anyPosition(int info,int p){
	int k=1;
	 newnode=(node*)malloc(sizeof(node));
     newnode->Data=info;
     newnode->next=NULL;
     tmp=start;
     while(tmp->next!=NULL){
     	if(k==p-1)
     	break;
     	else{
     	
     	tmp=tmp->next;
     	k=k+1;
     }
     }
     newnode->next=tmp->next;
     tmp->next=newnode;
     printf("The element inserted\n\n");
}

void search(int info){
	int k=1;
	if(start==NULL){
		printf("There is no linked list\n");
	}
	else{
		tmp=start;
		while(tmp!=NULL){
			if(tmp->Data==info){
			printf("found in location %d\n",k);	
			}
			tmp=tmp->next;
			k=k+1;
		}
	}
}
void display(){
	printf("\t The linked list\n");
	if(start==NULL)
		printf("\n list is empty\n");
		else{
			tmp=start;
			while(tmp!=NULL){
				printf("%d\n",tmp->Data);
				tmp=tmp->next;
			}
		}
	}
void Delete(int info){
	  node hold;
if (start->Data ==info)
{
tmp=start;
start=start->next; /*First element deleted*/
free(tmp);
return;
}
hold=start;
while(hold->next->next != NULL)
{
if(hold->next->Data == info) /*Element deleted in between*/
{
tmp=hold->next;
hold->next=tmp->next;
free(tmp);
return;
}
hold=hold->next;
}/*End of while */
if(hold->next->Data==info) /*Last element deleted*/
{
tmp=hold->next;
free(tmp);
hold->next=NULL;
return;
}
printf ("\n\nElement %d not found",info);
getch();
}

int main(){	
	int choice,pos,i,num,element;
	while(1){
	
		printf("\n\t\tChoose Your operation\n");
	   printf("\t\t----------------------------\n");
	    printf("\t\t----------------------------\n");
		printf("\t\t1,Create a linked list\n");
		printf("\t\t2,Add At The begining\n");
		printf("\t\t3,Add at the end\n");
		printf("\t\t4,Add at any position\n");
		printf("\t\t5,Delete\n");
		printf("\t\t6,Search\n");
		printf("\t\t7,Display\n");
		printf("\t\t8,Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
				printf("How many nodes you want to create\n");
				scanf("%d",&num);
				printf("Enter the elements\n");
				for(i=0;i<num;i++){
					scanf("%d",&element);
					create_link(element);
					
				}
				display();
				printf("Linked list sucessfully created\n\n");
				break;
		case 2:
					printf("Enter an element to insert at the begining\n");
					scanf("%d",&element);
					AddBegin(element);
					display();
					break;
		case 3:
			         printf("Enter an element to insert at the end\n");
					scanf("%d",&element);
					AddEnd(element);
					display();
					break;	
	    case 4:
	    	printf("the position you want to insert\n");
	    	scanf("%d",&pos);
	    	printf("Enter an element to insert at any position\n");
	    	scanf("%d",&element);
	    	anyPosition(element,pos);
	    	display();
	    	break;
		case 5:
			printf("Enter the the number to delete\n");
			scanf("%d",&num);
			Delete(num);
			display();
			break;
		case 6:
	     	printf("Enter an element to search at any position\n");
	    	scanf("%d",&element);
	    	search(element);
	    	display();
	    	break;
	  case 7:
	  	 display();
	  	 break;
	
	case 8:
		exit(0);
		break;
    default:
		printf("No more option\n");	
	    }
	}
}
