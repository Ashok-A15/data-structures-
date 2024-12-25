
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
  int data;
  struct NODE *link;
} node;
typedef struct tt {
  int count;
  node *head;
} LIST;
node *getnode(int value) {
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->data = value;
  temp->link = NULL;
  return temp;
}
node* insert_front(int value, LIST *list) {
  node *temp;
  temp = getnode(value);
  if (list->head == NULL) {
    printf("list is empty\n");
    return temp;
  } else {
    temp->link = list->head;
    list->head = temp;
    return list->head;
  }
}
node* insert_rare(int value, LIST *list) {
  node *temp = getnode(value);
  node *cur = list->head;
  if (list->head == NULL) {
    printf("list is empty\n");
    return temp;
  } else {
    while (cur->link != NULL) {
      cur = cur->link;
    }
    cur->link = temp;
    return list->head;
  }
}
node* delete_front(LIST *list){
  node *temp=list->head;
  if(list->head==NULL){
    printf("nothing to delete\n");
    return list->head;
  }
  else{
    list->head=temp->link;
    free(temp);
    return list->head;
  }
}
node* delete_rare(LIST *list){
  node*temp=list->head;
  node *cur=NULL;
  if(list->head==NULL){
    printf("nothing to delete\n");
    return list->head;
  }
  else{
    while(temp->link!=NULL){
      cur=temp;
      temp=temp->link;
    }
    cur->link=NULL;
    free(temp);
    return list->head;
  }
}
node* delete_pos(int pos,LIST *list){
  node *temp=list->head;
  node *cur=NULL;
  if(pos==1){
    list->head=delete_front(list);
    return list->head;
  }
  else{
  while(pos!=1){
    cur=temp;
    temp=temp->link;
    pos--;
    
  }
  cur->link=temp->link;
    free(temp);
    return list->head;
  }
}
node* insert_pos(int value,int pos,LIST *list){
  node*cur=list->head;
  node *sir=NULL;
  
  if(pos==1){
    list->head=insert_front(value,list);
    return list->head;
  }
  node *temp=getnode(value);
    while(pos!=1){
      sir=cur;
      cur=cur->link;
    }
  sir->link=temp;
  temp->link=cur;
  return list->head;
}
int search_key(int key,LIST *list){
  node *temp=list->head;
  int count=0;
  int pos=0;
  int found=0;
  while(temp!=NULL){
    if(temp->data==key){
      pos=count+1;
      found=1;
      break;
    }
    count=count+1;
    temp=temp->link;
  }
  if(found==1){
    return pos;
  }
  else{
    return 0;
  }
}
 node* delete_key(int key,LIST *list){
   node *temp=list->head;
   node *cur=NULL;
   int pos=search_key(key,list);
   if(pos==0){
     printf("key not found\n");
     return list->head;
   }
   else if(pos==1){
     list->head=delete_front(list);
     return list->head;
   }
   else{
     while(pos!=1){
       cur=temp;
       temp=temp->link;
       pos--;
     }
     cur->link=temp->link;
     free(temp);
     return list->head;
   }
 }
void display(LIST *list){
  node *temp=list->head;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->link;
  }
  
}
node* reverse_li(LIST *list){
  node *temp=list->head;
  node *cur=NULL;
  node *prev=NULL;
  while(temp!=NULL){
    cur=temp->link;
    temp->link=prev;
    prev=temp;
    temp=cur;
  }
  list->head=prev;
  return list->head;
}
  int main(){
  int key,value,pos,ch;
    LIST *list;
    list=(LIST*)malloc(sizeof(LIST));
    list->head=NULL;
    list->count=0;
    printf("1.insert front\t 2.insertrare\t3.delete front\t");
    for(;;)
    {

      printf("\n enter the choice:\n");
      scanf("%d\n",&ch);
      switch(ch)
      {
        case 1:printf("enter the value\n");
            scanf("%d\n",&value);
               list->head=insert_front(value,list);
                 break;
        case 2:printf("enter the value\n");
                 scanf("%d\n",&value);
                list->head=insert_rare(value,list);
                    break;
        case 3:list->head=delete_front(list);
                printf("yes delete front\n");
                     break;
        case 4:list->head=delete_rare(list);
                   printf("yes delete rare\n");
                   break;
        case 5:printf("enter the posi\n");
                  scanf("%d\n",&pos);
                  list->head=delete_pos(pos,list);
                     printf("yes delete pos\n");
                          break;
        case 6:printf("enter the posi\n");
        scanf("%d\n",&pos);
          printf("enter the value\n");
          scanf("%d\n",&value);
        list->head=insert_pos(value,pos,list);
        printf("yes insrt pos\n");
        break;
        case 7:printf("enter the key\n");
        scanf("%d\n",&key);
        list->head=delete_key(key,list);
         printf("yes delete key\n");
        break;
        case 9:display(list);
        break;
        case 10: list->head=reverse_li(list);
        printf("yes reverse\n");
        break;
        case 11 :printf("raja buy");
        exit(0);
        default:printf("enter the valid choice");
        break;
           }
    }
    return 0;
  }  
          
     
        
      
    
   
