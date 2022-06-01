#include <iostream>
#include "hw2_functions.h"
using namespace std;

// function that ask for how many classes the person will take. 
int how_many_classes() {

    int num = 0;


    cout << "How many classes will you take: ";
    cin >> num;

    return num;
}

// function that serves as a banner. 
void message() {


    cout << "Welcome to the UMB graduation status check app!" << endl << endl;
}

// function that prints krusty will not graduate
void fail() {
    cout << "Krusty hasn't earned enough credits to graduate yet!" << endl;
    cout << "Thanks for using the UMB graduation status check app!" << endl;
}
