#include <iostream>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
void printList(ListNode* head){
    while( head ){
        cout<<head->val<<" " ;
        head = head->next ;
    }cout<<endl ;
}

ListNode* mergeList(ListNode* head1,ListNode* head2){
    if( !head1 ){
        return head2 ;
    }
    if( !head2 ){
        return head1 ;
    }
    ListNode* newHead ;
    ListNode* point ;
    if( head1->val<head2->val ){
        newHead = head1 ;
        head1 = head1->next ;
    }
    else{
        newHead = head2 ;
        head2 = head2->next ;
    }
    // newHead->next = NULL ;
    point = newHead ;
    
    while( head1 && head2 ){
        if( head1->val<head2->val ){
            point->next = head1 ;
            head1 = head1->next ;
        }
        else{
            point->next = head2 ;
            head2 = head2->next ;
        }
        point = point->next ;
    }    
    if( !head1 ){
        point->next = head2 ;
    }
    else{
        point->next = head1 ;
    }
    printList(newHead) ;
    return newHead ;
}

ListNode* divideList(ListNode* head1 ){
    if( head1==NULL ){
        return NULL ;
    }
    ListNode* fast = head1->next ;
    ListNode* slow = head1 ;
    
    while(fast && fast->next ){
        fast = fast->next->next ;
        slow = slow->next ;
    }
    fast = slow ;
    slow = slow->next ;
    fast->next = NULL ;
    return slow ;
    // cout<<"slow->val = "<<slow->val<<endl ;
}

ListNode* merge(ListNode* head){
    if( head ){
        ListNode* head1 = NULL ;
        if( head->next ){
            head1 = divideList(head) ;
            cout<<"head->val = "<<head->val<<endl;
            if( head1 ){
                cout<<"head1->val = "<<head1->val<<endl;
            }
            return mergeList(merge(head),merge(head1)) ;
        }
        return head ;
    }
    else{
        return NULL ;
    }
}

ListNode* sortList(ListNode* head) {
    return merge(head) ;
}


ListNode* createList(){
    int array[] = {4,5,2,1} ;
    ListNode* head = NULL ;
    ListNode* tail = NULL ;
    for( int i=0;i<4;++i ){
        ListNode* p = new ListNode(array[i]) ;
        if( head == NULL ){
            head = p ;
            tail = p ;
        }
        else{
            tail->next = p ;
            tail = tail->next ;
        }
    }
    return head ;
}



int main(){

    ListNode* head = createList() ;
    head = sortList(head) ;
    printList(head) ;
    return 0 ;
}