#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node*next;///mane next name akta pointer thakbe ja kina Node typer ,mane onno kono node ke point korbe
    Node(int value)///making a constructor to initialize their value
    {
        data=value;
        next=NULL;
    }
};
void print(Node*&head)////reference mane aikane je head er je change ta hbe ta main head e o hbe
{
    Node* temp=head;///mane temp ta initially head ke point kore ja nijeo akta Node typer pointer
    while(temp!=NULL)
    {
        ////erpor pura linked list take traverse korbo amra
        cout<<temp->data<<" ";
        ///erpor temp ta next node ke point korbe
        temp=temp->next; ///mane new temp hbe ager temp er next
    }
    cout<<endl;
}
void insertAThead(Node* &head,int d)
{
    Node* temp=new Node(d);///mane new node akta create korbo nton value d er jnno jathe oi new node e d value ta store hoi.
    ///new node ta jehuto head e add korbo tie oi temp namok new node er next thakbe ager head e
    temp->next=head;
    ///mane newly added temp er next initial head er dike
    head=temp;// mane new head ta hbe je temp namok node ta newly add korci
}
int main()
{
    int n,h,i;
    Node* node1=new Node(10);///MANE node 1 name akta pointer make korlam ja kina new keyword ta dynamically allocate kora new arekta node class  ke point kore jathe amra 10 pass kori dibo data hisebe
    ///akon head name akta pointer make korlam ja kina initial node ke point kore
    Node *head=node1;///mane head initially amader node1 point kore
    Node *tail=node1;//mane initially jkon onno kono kicu add kori nie ja head tie tail
    ///mane head and tail pointer akoi node ke point korbe
    cout<<"Initially linked list : ";
    print(head);///mane amra head take pass korlam
    cout<<"Enter how many elements you want to add at head ??  ";
    cin>>n;
    cout<<"Enter the elements ----->"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>h;///je value ta insert korte cacci ta holo h
        insertAThead(head,h);
    }
    print(head);
}
