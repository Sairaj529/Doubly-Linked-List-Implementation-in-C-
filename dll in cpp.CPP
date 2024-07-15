#include <iostream>
#include <conio>
#include <stdlib>
struct node{
int data;
node* next;
node* prev;
};

class dll{
  node* start;
  node* end;

  public:

  dll(){
     start=NULL;
     start->next=NULL;
     end=NULL;
     end->next=NULL;
     }

  void insertBeg(int val){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->data=val;
      newnode->next=NULL;
      newnode->prev=NULL;

      if(start==NULL){
         start=newnode;
         end=newnode;
         }
      else{
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
        }
    }

    void insertEnd(int val){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->data=val;
      newnode->next=NULL;
      newnode->prev=NULL;

      if(start==NULL){
         start=newnode;
         end=newnode;
         }
      else{
        end->next=newnode;
        newnode->prev=end;
        end=newnode;
        }
    }

    node* search(int val){
         node* temp=start;
         while(temp!=NULL){
             if(temp->data==val)
                return temp;
             temp=temp->next;
             }
        return NULL;
       }

    void forwardTraversal(){
       node* temp=start;
       cout<<"\n";
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp=temp->next;
             }
       }

    void reverseTraversal(){
       node* temp=end;
       cout<<"\n";
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp=temp->prev;
             }
       }

    void insertAfter(int val,int aft){
        node* a=search(aft);
        if(a==NULL){
          cout<<"\nNode doesn't exit";
          }
          else if(a==end){
             insertEnd(val);
             }
        else{
             node* newnode=(node*)malloc(sizeof(node));
             newnode->next=a->next;
             newnode->prev=a;
             a->next->prev=newnode;
             a->next=newnode;
             }
      }

      void insertBefore(int val,int aft){
        node* a=search(aft);
        if(a==NULL){
          cout<<"\nNode doesn't exit";
          }
          else if(a==start){
               insertBeg(val);
               }
        else{
             node* newnode=(node*)malloc(sizeof(node));
             newnode->next=a;
             newnode->prev=a->prev;
             a->prev->next=newnode;
             a->prev=newnode;
             }
      }

     node* removeStart(){
         node* temp=start;
         start=start->next;
         start->prev=NULL;
         return temp;
     }

     node* removeEnd(){
         node* temp=end;
         end=end->prev;
         end->next=NULL;
         return temp;
     }


     node* remove(int val){
      node* b=search(val);
        if(b==NULL){
          cout<<"\nNode doesn't exit";
           return NULL;
          }
          else if(b==start){
               return removeStart();
          }
          else if(b==end){
               return removeEnd();
          }
          else{
          node* temp=b;
          b->prev->next=b->next;
          b->next->prev=b->prev;
          return temp;
          }
      }

};


   void main(){

     dll l=dll();
      l.insertBeg(1);
      l.insertEnd(2);
      l.insertAfter(3,1);
      l.forwardTraversal();
      l.remove(1);
      l.reverseTraversal();

      getch();
      }
