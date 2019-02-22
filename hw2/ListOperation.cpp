#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "ArgumentManager.h"
using namespace std;

struct nb{
    nb *prev;
    int book_id;
    string book_name;
    string book_author;
    nb *next;
};

class lib { // as ADT
private:
    nb *head;
    nb *tail;
public:
    lib() {head = tail = 0;}
    
    bool isempty() {
        return (head==0 ? 1:0);
    };
    
    void insertatbeg(int ibook_id, string ibook_name, string ibook_author) {
        if (book_search("book_id", to_string(ibook_id)) != -1)
            return;
        // create a node
        nb *temp = new nb;
        // fill temp node
        temp -> prev = nullptr;
        temp -> book_id = ibook_id;
        temp -> book_name = ibook_name;
        temp -> book_author = ibook_author;
        temp -> next = head;
        // link it
        if (head != nullptr)
            head -> prev = temp;
        head = temp;
        if (tail == nullptr)
            tail = temp;
    };
    
    void insertatend(int ibook_id, string ibook_name, string ibook_author) {
        if (book_search("book_id", to_string(ibook_id)) != -1)
            return;
        // create a node
        nb *temp = new nb;
        // fill teh node
        temp -> prev = tail;
        temp -> book_id = ibook_id;
        temp -> book_name = ibook_name;
        temp -> book_author = ibook_author;
        temp -> next = nullptr;
        // link it
        if (tail != nullptr)
            tail -> next = temp;
        tail = temp;
        if (head == nullptr)
            head = temp;
    };
    
    void insert(int pos, int ibook_id, string ibook_name, string ibook_author) {
        if (book_search("book_id", to_string(ibook_id)) != -1)
            return;
        // create a node
        nb *temp = new nb;
        temp = head;
        int i = 0; // nodes counter
        // link it
        if (pos==0 || head == nullptr) {
            insertatbeg(ibook_id, ibook_name, ibook_author);
        } else {
            while(i != pos && temp -> next != nullptr) { // linear search
                temp = temp -> next;
                i++;
            };
            if (temp -> next == nullptr) {
                insertatend(ibook_id, ibook_name, ibook_author);
            } else {
                nb *ins = new nb;
                //cout<<"Prev id: "<< temp -> prev -> book_id << endl;
                //cout<<"Inserted id: "<< ibook_id << endl;
                //cout<<"Next id: "<< temp -> book_id << endl;
                
                ins -> prev = temp -> prev;
                ins -> next = temp;
                temp -> prev -> next = ins;
                temp -> prev = ins;
                
                ins -> book_id = ibook_id;
                ins -> book_name = ibook_name;
                ins -> book_author = ibook_author;
                
                //cout<<"Prev upd: "<< ins -> prev -> book_id << endl;
                //cout<<"Inserted upd: "<< ins -> book_id << endl;
                //cout<<"Next upd: "<< ins -> next -> book_id << endl;
            };
        };
    };
    
    void remove(int pos) {
        // create a node
        nb *temp = head;
        int i = 0; // nodes counter
        // fill temp node
        
        // link it
        while(i != pos && temp != nullptr) { // linear search
            temp = temp -> next;
            i++;
        };
        if (temp != nullptr) {
            if (temp -> prev != nullptr)
                temp -> prev -> next = temp -> next;
            else {
                head = temp -> next;
                //tail -> next = temp -> next;
            };
            if (temp -> next != nullptr)
                temp -> next -> prev = temp -> prev;
            else {
                tail = temp -> prev;
                //head -> prev = temp -> prev;
            };
            delete temp;
        };
    };
    
    void sort(string keyword) { //bubble sort
        int swapped;
        nb *temp;
        
        /* Checking for empty list */
        if (isempty())
            return;
        do
        {
            swapped = 0;
            temp = head;
            
            while (temp->next != nullptr)
            {
                if (keyword.find("book_id") != std::string::npos) { //== "book_id") {
                    if (temp->book_id > temp->next->book_id) {
                        swap(temp->book_id, temp->next->book_id);
                        swap(temp->book_name, temp->next->book_name);
                        swap(temp->book_author, temp->next->book_author);
                        swapped = 1;
                    }
                } else if (keyword.find("book_name") != std::string::npos) {// == "book_name") {
                    if (temp->book_name > temp->next->book_name) {
                        swap(temp->book_id, temp->next->book_id);
                        swap(temp->book_name, temp->next->book_name);
                        swap(temp->book_author, temp->next->book_author);
                        swapped = 1;
                    }
                } else if (keyword.find("book_author") != std::string::npos) {// == "book_author") {
                    if (temp->book_author > temp->next->book_author) {
                        swap(temp->book_id, temp->next->book_id);
                        swap(temp->book_name, temp->next->book_name);
                        swap(temp->book_author, temp->next->book_author);
                        swapped = 1;
                    }
                }
                
                temp = temp->next;
            }
        }
        while (swapped);
    }
    
    int book_search(string keyword, string value) { // search for node, return position
        int i = 0; // nodes counter
        nb *temp = head; // temp node, start from head of the list
        
        if (keyword == "pos") {
            while (temp != nullptr) { // linear search
                i++;
                temp = temp -> next;
            };
            if (stoi(value)<i) {
                return stoi(value);
            } else {return -1;}
        };
        
        while (temp != nullptr) { // linear search
            //cout<<"Request: "<< keyword << " " <<value <<endl;
            //cout<<"Current: "<< temp -> book_id << " " << temp->book_name << " " << temp -> book_author << endl;
            if (keyword.find("book_id") != std::string::npos) { //== "book_id") {
                if (temp -> book_id == stoi(value))
                    return i;
            } else if (keyword.find("book_name") != std::string::npos) {// == "book_name") {
                if (temp -> book_name.find(value) != std::string::npos) //(temp -> book_name == value)
                    return i;
            } else if (keyword.find("book_author") != std::string::npos) {// == "book_author") {
                //cout<<"Searching for book author, pattern: "<< value <<endl;
                //cout<<"Searching for book author, current: "<< temp -> book_author <<endl;
                if (temp -> book_author == value)//(temp -> book_author.find(value) != std::string::npos)
                    return i;
            };
            i++;
            temp = temp -> next;
        };
        return -1;
    }
    
    void print(bool fileflag = false, string file = ""){
        nb *temp = new nb;
        temp = head;
        ofstream ofile;
        if(fileflag == true)
            ofile.open (file);
        
        while (temp != nullptr){
            if (fileflag == false) {
                cout << "book_id:" << temp -> book_id
                << ", book_name:" << temp -> book_name
                << ", book_author:" << temp -> book_author << endl;}
            else {
                ofile   << "book_id:" << temp -> book_id
                << ", book_name:" << temp -> book_name
                << ", book_author:" << temp -> book_author << endl;
            }
            temp = temp->next;
        };
        if (ofile.is_open())
            ofile.close();
    };
};


int main (int argc, char** argv) {
    
    if (argc < 2) {
        std::cout <<
        "Usage: ListOperation \"input=<file>;command=<file>;output=<file>\""
        << std::endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    
    string A = am.get("input");
    string B = am.get("command");
    string C = am.get("output");
    /*
    string A = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw2_new/hw2-archive/input29.txt";
    string B = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw2_new/hw2-archive/command29.txt";
    string C = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw2_new/hw2-archive/tmp29.txt";
     */
    int n = 0; //lines counter
    string line = ""; //string from txt
    lib list;
    
    ifstream ifile1 (A);
    if (ifile1.is_open())
    {
        while ( getline (ifile1, line) ) //go through each line
        {
            if (line.length() != 0) {
                //line Format: book_id:book id, book_name:book name, book_author:author name
                int arg11 = stoi(line.substr(line.find("book_id:")+8,5));
                string arg21 = line.substr(line.find("book_name:")+10,
                                           line.find(", book_author")-line.find("book_name:")-10);
                string arg31 = line.substr(line.find("book_author:")+12);
                //cout<<"Adding book: "<<arg11 <<", "<<arg21 <<", "<<arg31 <<endl;
                list.insertatend(arg11,arg21,arg31);
                n++;
            }
        }
        ifile1.close();
    }
    
    ifstream ifile2 (B);
    if (ifile2.is_open())
    {
        while ( getline (ifile2, line) ) //go through each line
        {
            if (line.length() != 0) {
                //line Format: add/remove/sort ...
                //cout<<line<<endl;
                if (line.substr(0,line.find(" ")) == "add") {
                    int arg12 = stoi(line.substr(line.find("book_id:")+8,5));
                    string arg22 = line.substr(line.find("book_name:")+10,
                                               line.find(", book_a")-line.find("book_name:")-10);
                    //cout<<"Start: "<<line.find("book_name:")<<endl;
                    //cout<<"Length: "<<line.find(", book_a")-line.find("book_name:")<<endl;
                    //cout<<"End: "<<line.find(", book_a")<<endl;
                    //cout<<arg22<<endl;
                    string arg32 = line.substr(line.find("book_author:")+12);
                    int arg02 = stoi(line.substr(line.find("pos:")+4,
                                                 line.find("book_name:")-line.find("pos:")-10));
                    //cout<<"Args: "<<arg02<<", "<<arg12<<", "<<arg22<<", "<<arg32<<endl;
                    
                    list.insert(arg02,arg12,arg22,arg32);
                    
                } else if (line.substr(0,line.find(" ")) == "sort") {
                    list.sort(line.substr(line.find(" ")+1));
                } else if (line.substr(0,line.find(" ")) == "remove") {
                    
                    //cout<<"Book search arg1: "<< line.substr(line.find(" ")+1,
                                                            //line.find(":")-line.find(" ")-1) <<endl;
                    
                    //cout<<"Book search arg2: "<< line.substr(line.find(":")+1)<<endl;
                    
                    //cout<<"Search pre-cycle result: "<<list.book_search(line.substr(line.find(" ")+1,
                                                                                //line.find(":")-line.find(" ")-1),
                                                                    //line.substr(line.find(":")+1))<<endl;
                    
                    while (list.book_search(line.substr(line.find(" ")+1,
                                                        line.find(":")-line.find(" ")-1),
                                            line.substr(line.find(":")+1))!=-1) {
                        
                        //cout<<"Search cycle result: "<<list.book_search(line.substr(line.find(" ")+1,
                                                                              //line.find(":")-line.find(" ")-1),
                                                                  //line.substr(line.find(":")+1))<<endl;
                        
                        list.remove(list.book_search(line.substr(line.find(" ")+1,
                                                                 line.find(":")-line.find(" ")-1),
                                                     line.substr(line.find(":")+1)));
                    }
                }
                /*
                 int arg1 = stoi(line.substr(line.find("book_id:")+8,5));
                 string arg2 = line.substr(line.find("book_name:")+10,line.find(", book_author")-25);
                 string arg3 = line.substr(line.find("book_author:")+12);
                 list.insertatbeg(arg1,arg2,arg3);
                 */
                n++;
            }
        }
        ifile2.close();
    }
    /* lib list1;
     list1.insert(0, 1, "cname1", "Bauthor1");
     list1.insert(1, 2, "bname2", "Cauthor2");
     list1.insert(2, 3, "aname3", "Aauthor3");
     list1.remove(0);
     
     list1.sort("book_id");
     list1.print(); */
    
    list.print(true,C);
    return 0;
}

