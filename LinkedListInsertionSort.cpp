#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*next;
};
struct node*createNode(struct node*head,int data)
{
    struct node*temp=new struct node;
    temp->data=data;
    temp->next=NULL;
    
    if(!head)
    return temp;
    
    while(head->next!=NULL)
    head=head->next;
    
    head->next=temp;
    
}

struct node* insertionSort(struct node*head)
{
    struct node*p=head->next;
    struct node*q=head;
    struct node*prev;
    while(p!=NULL)
    {
        struct node*current=head;
       // struct node*q=head;
        if(p->data<head->data)
        {
           q->next=p->next;
           p->next=head;
           head=p;
           p=q->next;
        }
        else
        {
        while(current!=p)
        {
            if(current->data<p->data)
            {
                prev=current;
                current=current->next;
            }
            else break;
        }
        if(current==p)
        {
            p=p->next;
            while(q->next!=p)
            q=q->next;
            continue;
        }
        while(q->next!=p)
          q=q->next;
          
          q->next=p->next;
          p->next=current;
          prev->next=p;
          
          p=q->next;
        }
      
        
    }
    return head;
}
void display(struct node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    struct node*head=NULL;
   // struct node*head=NULL;
    head=createNode(head,4);
    createNode(head,3);
    createNode(head,2);
    createNode(head,10);
    createNode(head,12);
    createNode(head,1);
    createNode(head,5);
    createNode(head,6);
    head=insertionSort(head);
    
    display(head);
}
