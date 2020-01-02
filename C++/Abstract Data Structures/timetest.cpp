#include <iostream>
#include <fstream>
#include <cstdlib>
#include "CPUTimer.h"
#include "CursorList.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "QueueAr.h"
#include "SkipList.h"


using namespace std;
vector<CursorNode <int> > cursorSpace(500000);
int getChoice();
void RunCursorList(char* filename);
void RunList(char* filename);
void RunStackAr(char* filename);
void RunStackLi(char* filename);
void RunQueueAr(char* filename);
void RunSkipList(char* filename);


int main()
{

    CPUTimer ct;
    char filename[10];
    int choice;

    cout << "Filename >> ";
    cin >> filename;
     //cout << filename << " \n" << endl;
    do
    {
     choice = getChoice();
     ct.reset();
     switch (choice)
     {
     case 1: RunList(filename); break;
     case 2: RunCursorList(filename); break;
     case 3: RunStackAr(filename); break;
     case 4: RunStackLi(filename); break;
     case 5: RunQueueAr(filename); break;
     case 6: RunSkipList(filename); break;
     } // switch
     cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while(choice > 0);

  return 0;
} // main())

int getChoice()
{

    int choice;
    do{
        cout << endl;
        cout << "      ADT MENU" << endl;
        cout << "0. Quit" << endl;
        cout << "1. LinkedList" << endl;
        cout << "2. CursorList" << endl;
        cout << "3. StackAr" << endl;
        cout << "4. StackLi" << endl;
        cout << "5. QueueAr" << endl;
        cout << "6. SkipList" << endl;
        cout << "Your choice >> ";
        cin >> choice;

    if  (choice < 0 || choice > 6)
      cout << "Your choice must be between 0 and 6. Please try again.\n";
  } while(choice < 0 || choice > 6);

    return choice;

}

void RunCursorList(char* filename){

ifstream inf(filename);
  CursorList <int> cursorlist(cursorSpace);
  CursorListItr <int> itr = cursorlist.zeroth();

char command;
char line[550];
int value;

    inf.getline(line, 500);
    while(inf >> command >> value){
        if (command == 'i')
            cursorlist.insert(value, itr);
        else
            cursorlist.remove(value);
    }


}

void RunList(char* filename){

 List <int> list;
 ListItr <int> itr = list.zeroth();
 ifstream inf(filename);
    char command;
    char line[550];
    int value;

    inf.getline(line, 500);
    while(inf >> command >> value){
        if (command == 'i')
            list.insert(value, itr);
        else
            list.remove(value);
    }

}

void RunStackAr(char* filename){

    StackAr <int> staklist(500000);
    ifstream inf(filename);
    char command;
    char line[550];
    int value;
    inf.getline(line, 500);

    while(inf >> command >> value){
    if (command == 'i')
        staklist.push(value);
    else
       staklist.pop();
    }



}

void RunStackLi(char* filename){

    StackLi <int> staklist;
    ifstream inf(filename);
    char command;
    char line[550];
    int value;
    inf.getline(line, 500);

    while(inf >> command >> value){
    if (command == 'i')
        staklist.push(value);
    else
        staklist.pop();
    }

}

void RunQueueAr(char* filename){

    Queue <int> que(500000);
    ifstream inf(filename);
    char command;
    char line[550];
    int value;
    inf.getline(line, 500);

    while(inf >> command >> value){
    if (command == 'i')
        que.enqueue(value);
    else
       que.dequeue();
    }

}

void RunSkipList(char* filename){
    SkipList <int> skiplist(0, 500000);
        ifstream inf(filename);
    char command;
    char line[550];
    int value;
    inf.getline(line, 500);

    while(inf >> command >> value){
    if (command == 'i')
        skiplist.insert(value);
    else
        skiplist.deleteNode(value);
    }

}


