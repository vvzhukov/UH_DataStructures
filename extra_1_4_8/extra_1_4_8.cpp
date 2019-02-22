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
    
    void delete_from_mid_by_index(int loc, int &dx, int &dy) {
        point *temp;
        point *cu = head;
        for (int i = 1; i <= loc-1; i++) {
            cu = cu -> next;
            //Debug: cout << "i = " << i << " loc = " << loc-1 << endl;
        };
        temp = cu -> next;
        //Debug: cout << "temp -> x: " << temp -> x << endl;
            
        dx = temp -> x;
        dy = temp -> y;
        cu -> next = temp -> next;
        delete temp;
    };
    
    void delete_from_mid_by_Xcontent(int value, int &dx, int &dy) {
        point *prev = 0;
        point *cu = head;
        while (cu -> x != value) {
            cout << "cu -> x: " << cu -> x << endl;
            prev = cu;
            cu = cu -> next;
        };
        prev -> next = cu -> next;
        dx = cu -> x;
        dy = cu -> y;
    };

    void insert_beg(int a, int b) {
        point *temp = new point;
        temp -> x = a;
        temp -> y = b;
        temp -> next = head;
        cout << temp -> x << " <-x Inserting y-> " << temp -> y << endl;
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
    
    void insert_mid(int a, int b) {
        point *temp = new point;
        temp -> x = a;
        temp -> y = b;
        temp -> next = nullptr;
    };
};

int main() {
    line verticalline;
    int a, b;
    int c = 2;
    verticalline.insert_beg(17, 44);
    verticalline.insert_beg(7, 11);
    verticalline.insert_beg(18, 46);
    verticalline.insert_beg(22, 76);
    verticalline.delete_from_mid_by_Xcontent(18, a, b);
    cout << "Node deleted, values extracted: " << a << " and " << b << endl;
    verticalline.delete_from_mid_by_index(c, a, b);
    cout << "Node deleted, values extracted: " << a << " and " << b << endl;
    return 0;
}
