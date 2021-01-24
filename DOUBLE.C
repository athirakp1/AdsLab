#include<stdlib.h>
struct node
{
 struct node *left;
 int data;
 struct node *right;
};
struct node *head=NULL;
struct node *Getnode();
void insertFirst();
void insertLast();
void display();
void search();
void insertpos();
void deleteFirst();
void deleteLast();
void deletepos();
void main()
{
 int opt=0;
 while (opt!=9)
 {
 printf("\nMENU\n1.INSERT FIRST\n2.INSERT LAST\n3.DISPLAY\n4.INSERT AT A POSITION\n5.DELETE FIRST\n6.DELETE LAST\n7.DELETE AT A POSITION\n8.SEARCH\n9.EXIT\nEnter the choice:");
 scanf("%d",&opt);
 switch (opt)
 {
   case 1: insertFirst();
	break;
   case 2: insertLast();
	break;
   case 3: display();
	break;
   case 4: insertpos();
	break;
   case 5: deleteFirst();
	break;
   case 6: deleteLast();
	break;
   case 7: deletepos();
	break;
   case 8: search();
	break;
 }
}
 printf("Good Bye");
 getch();
}
void display()
{
 struct node *ptr=head;
 if(head==NULL)
 {
  printf("\n List Empty");
  return;
 }
 ptr=head;
 while(ptr!=NULL)
 {
  printf("%d\t",ptr->data);
  ptr=ptr->right;
 }
}
struct node *Getnode()
{
 int x;
 struct node *ne=(struct node*)malloc(sizeof(struct node));
 if (ne==NULL)
 printf("insufficient memory\n");
 else
 {
  printf("Enter the value to insert");
  scanf("%d",&x);
  ne->left=NULL;
  ne->right=NULL;
  ne->data=x;
 }
  return ne;
}
void insertFirst()
{
 struct node *ne;
 ne=Getnode();
 if(ne==NULL)
 return;
 if(head==NULL)
   head=ne;
 else
 {
  head->left=ne;
  ne->right=head;
  head=ne;
 }
 display();
}
void insertLast()
{
 struct node*ne,*ptr;
 ne=Getnode();
 if(ne==NULL)
 return;
 if(head==NULL)
 head=ne;
 else
 {
  ptr=head;
  while (ptr->right!=NULL)
  {
   ptr=ptr->right;
  }
  ptr->right=ne;
  ne->left=ptr;
 }
 display();
}
void insertpos()
{
 int value;
 struct node *ne,*ptr,*ptr1;
 ne=Getnode();
 if(ne==NULL)
 return;
 if(head==NULL)
 {
 printf("List is Empty so the node is inserted as the first node");
 head=ne;
 return;
 }
 printf("enter the key value after the node has to be inserted\n");
 scanf("%d",&value);
 ptr=head;
 while(ptr->right!=NULL && ptr->data!=value)
 {
 ptr=ptr->right;
 }
 if (ptr->right==NULL)
 {
 ptr->right=ne;
 ne->left=ptr;
 printf("\n node is inserted at the last position");
 }
 else
 {
 ptr1=ptr->right;
 ne->right=ptr1;
 ne->left=ptr;
 ptr->right=ne;
 ptr->left=ne;
 }
 printf("\nthe Element is inserted\n");
 display();
}
void deleteFirst()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("list is empty\n");
  return;
 }
 ptr=head;
 head=head->right;
 if(head!=NULL)
 head->left=NULL;
 free(ptr);
 display();
}
void deleteLast()
{
 struct node *ptr,*prev;
 if (head==NULL)
 {
 printf("\nlist is empty");
 return;
 }
 if(head->right==NULL)
 {
  free(head);
  head=NULL;
 }
 ptr=head->right;
 while (ptr->right!=NULL)
 {
  ptr=ptr->right;
 }
 prev=ptr->left;
 prev->right=NULL;
 free(ptr);
 display();
}
void deletepos()
{
 struct node *ptr,*prev,*next;
 int x;
 if (head==NULL)
 {
  printf("\nlist is empty\n");
  return;
 }
printf("Enter the element to delete");
scanf("%d",&x);
if(head->data==x)
{
 ptr=head;
 head=ptr->right;
 if(head!=NULL)
 {
  head->left=NULL;
 }
  free(ptr);
  return;
 }
 ptr=head;
 while(ptr->data!=x && ptr->right!=NULL)
 {
  ptr=ptr->right;
 }
 if(ptr->data==x)
 {
  next=ptr->right;
  prev=ptr->left;
  prev->right=ptr->right;
  if(next!=NULL)
  next->left=ptr->left;
  free(ptr);
  return;
 }
 printf("\nElement not present in the list\n");
}
void search()
{
 struct node *ptr;
 int x;
 if(head==NULL)
 {
  printf("\nLinked list is empty");
  return;
 }
 printf("Enter element to search");
 scanf("%d",&x);
 ptr=head;
 while(ptr!=NULL)
 {
  if(ptr->data==x)
  {
   printf("\nElement present in the list\n");
   break;
  }
  ptr=ptr->right;
 }
 if(ptr==NULL)
 printf("\n Element not in the list\n");
}

