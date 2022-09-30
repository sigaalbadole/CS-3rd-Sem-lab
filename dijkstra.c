#include<stdio.h>
#include<stdlib.h>
struct item;
typedef struct node{
int val;
struct node* next;
struct item it;
}node;
typedef struct item{
node head;
node tail;
}item;
node hash[100];
void make(int a){
item* newset=(item*)malloc(sizeof(item));
newset->head= (node*)malloc(sizeof(node));
newset->tail=newset->head;
newset->head->val=a;
newset->head->it=newset;
newset->head ->next= NULL;
hash[a]=newset->head;
}
item* find(int a){
return (hash[a])->it;
}
void Union(item* i1,item* i2){
node* cur=i2->head;
while(cur){
cur->it=i1;
hash[cur->val]=i1->head;
cur=cur->next;
}
(i1->tail)->next=i2->head;
i1->tail=i2->tail;
free(*i2);
}
int main(){
int ch1,inp1,inp2,ch2;
while(1){
printf("\n1. add a vertex.\n2.union to vertex.\n3.prnt address of a vertex.\n4.exit\n\n\tenter your choice: ");
scanf("%d",&ch1);
switch(ch1){
case 1:
L1:
printf("\nEnter the vertex: ");
scanf("%d",&inp1);
make(inp1);
printf("\nsuccessful");
printf("\n\tdo you want to enter more vertex(1|0)? ");
scanf("%d",&ch2);
if(ch2==1)
goto L1;
break;
case 2:
L2:
printf("\nEnter vertex 1: ");
scanf("%d",&inp1);
printf("\nEnter vertex 2: ");
scanf("%d",&inp2);
Union(find(inp1),find(inp2));
printf("\nsuccessfull");
printf("\n\tdo you want to do more unions(1|0)? ");
scanf("%d",&ch2);
if(ch2==1)
goto L2;
break;
case 3:
L3:
printf("\nEnter the vertex whose address to check: ");
scanf("%d",&inp1);
printf("\n ADD- %p \t PARENT- %d ",find(inp1),find(inp1)->head->val);
printf("\n\tdo you want to check more addresses(1|0)? ");
scanf("%d",&ch2);
if(ch2==1)
goto L3;
break;
case 4:
exit(0);
default:
printf("\nretry");
}
}
return 0;
}