#include <iostream>
#include <stdio.h>
// #include <malloc.h>4
#include <stdlib.h>
using namespace std;


typedef struct Node{
char data;
struct Node *next;
}Node, *Linklist;

void creat( Linklist& l){
    l=(Linklist)malloc(sizeof(Node));
    l->next = NULL ;
}

int len( Linklist l ){ 
    Node *p = l;
    int k=0 ;

    cout<<"into len"<<endl ;
    while( p->next ){
        cout<<p->data<<endl ;
        p=p->next ;
        ++k;
        // cout<<k<<endl ;
    }
    cout<<"end while"<<endl ;
    return k;
}

void insertinto(Linklist l,int i,int e){
    Node *s;
    Node *pre;
    pre=l;
    int k=0;
    while(k<i-1){
        pre=pre->next;
        k++;
    }
    s=(Node *)malloc(sizeof(Node));
    s->data=e;
    s->next=pre->next;
    pre->next=s;

}


void deletnumber(Linklist l,int i){
    Node *r;
    Node *pre;
    pre=l;
    int k=0;
    while(k<i-1){
        pre=pre->next;
        k++;
        r=pre->next;
        pre->next=r->next;
    }
}

int main()
{
    Linklist l ;
    creat(l);

    Node *s;
    int a;
    printf("choose the count of input:\n");
    cin>>a;
    //scanf("%d",&a);
    int i=0;

    while(i<a){
        char c;
        cin>>c ;
        //c=getchar();
        //scanf("%c",&c);
        // cout<<c<<endl ;
        // s =  new Node() ;
        s=(Node *)malloc(sizeof(Node));
        // printf("i am here") ;
        s->data=c;
        s->next=l->next;
        l->next=s;
        i++;
    }

    int loc;
    int insnumber;

    // printf("the length of the linklist is %d\n",len(l));
    cout<<len(l)<<endl ;

    printf("the location of the insert number is %d\n",loc);
    scanf("%d",&loc);
    printf("the insert number is %d\n",insnumber);
    scanf("%d",&insnumber);
    insertinto(l,loc,insnumber);

    return 0;
}
