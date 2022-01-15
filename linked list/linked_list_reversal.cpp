//a sample for linked list reversal

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
void insert(int newdata)
{
    struct node*  newnode=new struct node;
    newnode->data=newdata;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        struct node* ptr=start;
        while(ptr->next!=NULL)
        {
        ptr=ptr->next;;
        }
        ptr->next=newnode;
}
}
void display()
{
    struct node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void rev()
{
    struct node* prev;
      struct node* current;
        struct node*after;
    prev=NULL;
    current=start;
    after=NULL;
        while(current!=NULL)
    {
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
    }
    start=prev;
    

}
int main()
{  insert(23);
   insert(43);
   insert(65);
   display();
   rev();
   display();
    return 0;
}
