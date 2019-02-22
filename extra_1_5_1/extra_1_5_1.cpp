#include <iostream>
using namespace std;

// extra 1_5_1
struct nb{
    nb *prev;
    int v;
    nb *next;
};

class counting { // as ADT
private:
    nb *head;
    nb *tail;
public:
    counting() {head = tail = 0;}
    
    bool isempty() {
        return (head==0 ? 1:0);
    };
    
    int lsearch(){
        return 1;
    };
    
    void insertatbeg(int value) {
        // create a node
        nb *temp = new nb;
        // fill teh node
        temp -> prev = nullptr;
        temp -> v = value;
        temp -> next = head;
        // link it
        if (head != nullptr)
            head -> prev = temp;
        head = temp;
        if (tail == nullptr)
            tail = temp;
    };
    
    void insertatend(int value) {
        // create a node
        nb *temp = new nb;
        // fill teh node
        temp -> prev = tail;
        temp -> v = value;
        temp -> next = nullptr;
        // link it
        if (tail != nullptr)
            tail -> next = temp;
        tail = temp;
        if (head == nullptr)
            head = temp;
    };
    
    void print(){
        nb *temp = new nb;
        temp = head;
        cout << "Printing list" << endl; //How to address name of the entity from its func?
        cout << "Head: " << head -> v << endl;
        cout << "Tail: " << tail -> v << endl;
        while (temp -> next != nullptr){
            cout << temp -> v << endl;
            temp = temp->next;
        }
        cout << temp -> v << endl;
    };
    
    //write a function to find out if 2 lists are equal
    bool isequal(counting l2){
        nb *temp1 = new nb;
        nb *temp2 = new nb;
        temp1 = head;
        temp2 = l2.head;
        while (temp1 -> next != nullptr) {
            //cout << "V1 " << temp1->v <<" V2 "<<temp2->v<<endl;
            if (temp1 -> v != temp2 -> v)
                return false;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        if (temp2 -> next != nullptr)
            return false;
        return true;
    };
    //writa a function to find out if 2 lists are one the reverse of the second
    bool isreverse(counting l2){
        nb *temp1 = new nb;
        nb *temp2 = new nb;
        temp1 = head;
        temp2 = l2.tail;
        while (temp1 -> next != nullptr) {
            //cout << "V1 " << temp1->v <<" V2 "<<temp2->v<<endl;
            if (temp1 -> v != temp2 -> v)
                return false;
            temp2 = temp2->prev;
            temp1 = temp1->next;
        }
        if (temp2 -> prev != nullptr)
            return false;
        return true;
    };
    
    bool deletefrommid(int key, int &value) {
        nb *cu = head;
        if (!isempty()){
            while(cu->v!=key && cu->next!=nullptr) //linear search
                cu=cu->next;
            
            if (cu->next==nullptr) {
                cout << "value not found";
                return false; }
            else {
                nb *temp=cu;
                value = temp -> v;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return true;
            };
        }
        else {
            cout << "can not delete because the list is empty()";
            return false;
        };
    };
};

int main() {
    counting list1;
    counting list2;
    counting list3;
    int retvalue;

    for(int i=0;i<5;i++) {
        list1.insertatbeg(i*4);
        list2.insertatbeg(i*4);
        list3.insertatend(i*4);
    };
    
    list1.print();
    list3.print();
        
    if (list1.isequal(list2))
        cout << "List1 is equal to List2\n";
    
    if (list1.isreverse(list3))
        cout << "List1 is reverse to List3\n";
    
    list1.deletefrommid(4,retvalue);
    cout << "The value deleted from List1 is " << retvalue << endl;

    if (list1.isequal(list2))
        cout << "List1 is equal to List2\n";
    
    
    return 0;
}