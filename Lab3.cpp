
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct node{
  int info;
  node *next;
};

class List{
  node *head;
  public:
    List() {head=NULL;}
    ~List();
    void input(int n);
    void show();
    void pop(int n);
    void push_beg(int n);
    void push_end(int n);
    void pop_end();
    void pop_beg();
    void push_list(int,List);
    node *get_head(){return head;};
    void pop_list();
};

List::~List(){
  while (head!=NULL){
    node *temp=head->next;
    delete head;
    head=temp;
  }
}

void List::input(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}

void List::show(){
  node *temp=head;
  while (temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->next;
}

void List::pop(int n){
  node *temp=head;
  if (head!=NULL){
    for (int i=0;i<n+1;i++)
      temp=temp->next;
    cout<<temp->info<<" "<<endl;
  }
  cout<<endl;
}

void List::push_beg(int n){
  node *temp1=new node;
  temp1->info=n;
  node *temp2=head;
  while(temp2->next)
    temp2=temp2->next;
  temp2->next=temp1;
  temp1->next=0;
  temp1=0;
}

void List::push_end(int n){
  node *temp=new node;
  temp->info=n;
  temp->next=head;
  head=temp;
}

void List::pop_end(){
  node *temp=head;
  head=head->next;
  delete temp;
  temp=0;
}

void List::pop_beg(){
  node *temp2;
  node *temp=head;
  while(temp->next->next)
    temp=temp->next;
  temp2=temp->next;
  temp->next=0;
  temp2->next=0;
  delete temp2;
  temp2=0;
}

void List::push_list(int n,List spis_t){ //Ne rabotaet
  node *temp1=head;
  node *temp2;
  while(temp1->info!=n)
    temp1=temp1->next;
  temp2=temp1->next;
  temp1=spis_t.get_head();
  while(temp1->next)
    temp1=temp1->next;
  temp1->next=temp2;
  //temp2->next=0;
  //temp2=0;

}



int main(){
  int m,m1,n,n1,k,z;
  List spis,spis_t;
  while(1){
    cout<<endl<<"Select an action: "<<endl;
    cout<<"__________________"<<endl;
    cout<<"1.Sozdat' spisok: "<<endl;
    cout<<"2.Dobavit' element v nachalo: "<<endl;
    cout<<"3.Daobavit' element v konec: "<<endl;
    cout<<"4.Udalit' element iz nachala: "<<endl;
    cout<<"5.Udalit' element iz konca: "<<endl;
    cout<<"6.Vstavit' podspisok: "<<endl;
    cout<<"7.Udalit' podspisok: "<<endl;
    cout<<"8.Exit:"<<endl;
    cin>>z;
    switch(z){
       case 1:{
         cout<<endl<<"Vvedite kolichestvo elementov spiska: "; cin>>m;
         for (int i=0;i<m;i++){
           cout<<"Vvedite "<<i+1<<" element spiska: "; cin>>n;
           spis.input(n);
         }
         spis.show();
         break;
       }
       case 2:{
         cout<<endl<<"Vvedite element dlya dobavlenia v nachalo: ";cin>>n;
         spis.push_beg(n);
         spis.show();
         break;
       }
       case 3:{
         cout<<endl<<"Vvedite element dlya dobavlenia v konec: ";cin>>n;
         spis.push_end(n);
         spis.show();
         break;
       }
       case 4:{
         cout<<endl<<"Udalyaem element:"<<endl;
         spis.pop_beg();
         spis.show();
         break;
       }
       case 5:{
         cout<<endl<<"Udalyaem element:"<<endl;
         spis.pop_end();
         spis.show();
         break;
       }
       case 6:{
         cout<<endl<<"Vvedite kolichestvo elementov,kotoroe hotite dobavit': ";cin>>m;
         cout<<endl<<"Vvedite cifru,posle kotoroi vstavit' podstroku: "; cin>>n;
         for(int i=0;i<m;i++){
           cout<<"Vvedite "<<i+1<<" element spiska: "; cin>>k;
           spis_t.input(k);
         }
         spis_t.show();
         spis.push_list(n,spis_t);
         spis.show();
         break;
       }
       case 7:{
         cout<<endl<<"Vvedite kolichestvo elementov,kotoroe hotite udalit': ";cin>>m;
         cout<<endl<<"Vvedite cifru,posle kotoroi udalit podstroku: "; cin>>n;

         spis.show();
       }
       case 8:{
         cout<<"Good-Bye!"<<endl;
         getch();
         exit(1);
       }
    }
  }
  getch();
  return 0;
}
