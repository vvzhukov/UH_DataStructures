#include <iostream>
using namespace std;

struct point{
    int x;
    int y;
    point *next;
};

class line { // as ADT
private:
    point *head;
public:
    line() {head = 0;}
    void insert(point); // insert at beg,middle,end
    void deletep(point); // delete at beg,middle,end
    void print();
    
    void insert_beg(int a, int b) {
        point *temp = new point;
        temp -> x = a;
        temp -> y = b;
        temp -> next = head;
        head = temp;
    };
    
    void insert_end(int a, int b) {
        point *temp = new point;
        temp -> x = a;
        temp -> y = b;
        temp -> next = nullptr;
        point *curr = head;
        while(curr -> next != nullptr) {
            curr -> next = temp;
        };
        curr -> next = temp;
    };
    
    void insert_mid(int a, int b);
    
};

int main() {
    line myline;
    myline.insert_beg(1,2);
    myline.insert_beg(3,4);
    myline.insert_end(4,0);

    return 0;
}