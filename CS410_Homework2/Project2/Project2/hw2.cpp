#include <iostream>
#include <fstream>
#include <string>
#include "hw2_functions.h"
using namespace std;

const int SIZE = 15;

struct class_pick {

    string course_name[SIZE];
	string course_numbers[SIZE];
    string course_check[SIZE]; // will be used for checking the requirements
    string holder[SIZE];
    string holder2[SIZE];
};

int main() {

	// read the file
    string myArray[100]; // Will get the elements from the file into here. 
    struct class_pick pick;

    ifstream file("course_catalog.txt");
    if (file.is_open())
    {

        for (int i = 0; i < 28; i++)
        {
            file >> myArray[i];
        }
    }

    // populating the name 
    pick.course_name[0] = myArray[0];
    pick.course_name[1] = myArray[2];
    pick.course_name[2] = myArray[4];
    pick.course_name[3] = myArray[6];
    pick.course_name[4] = myArray[8];
    pick.course_name[5] = myArray[10];
    pick.course_name[6] = myArray[12];
    pick.course_name[7] = myArray[14];
    pick.course_name[8] = myArray[16];
    pick.course_name[9] = myArray[18];
    pick.course_name[10] = myArray[20];
    pick.course_name[11] = myArray[22];
    pick.course_name[12] = myArray[24];
    pick.course_name[13] = myArray[26];

    // populating the course number struct
    pick.course_numbers[0] = myArray[1];
    pick.course_numbers[1] = myArray[3];
    pick.course_numbers[2] = myArray[5];
    pick.course_numbers[3] = myArray[7];
    pick.course_numbers[4] = myArray[9];
    pick.course_numbers[5] = myArray[11];
    pick.course_numbers[6] = myArray[13];
    pick.course_numbers[7] = myArray[15];
    pick.course_numbers[8] = myArray[17];
    pick.course_numbers[9] = myArray[19];
    pick.course_numbers[10] = myArray[21];
    pick.course_numbers[11] = myArray[23];
    pick.course_numbers[12] = myArray[25];
    pick.course_numbers[13] = myArray[27];

    int num_courses = 0;
    message();
    num_courses = how_many_classes();
    cout << "Enter which courses you are taking: " << endl;

    for (int i = 0; i < num_courses; i++) {
        
        int n = 0;
        cin >> n;
        pick.holder[i] = pick.course_name[n];
        pick.holder2[i] = pick.course_numbers[n];     
        pick.course_check[i] = pick.course_numbers[n];
    }
    
    cout << endl << endl;

    string temp;

    for (int i = 0; i < num_courses; i++)
    {
        for (int j = 1; j < num_courses - i; j++)
        {
            if (pick.course_check[j - 1] > pick.course_check[j])
            {
                temp = pick.course_check[j - 1];
                pick.course_check[j - 1] = pick.course_check[j];
                pick.course_check[j] = temp;
            }
        }
    }


    if ((pick.course_check[0][0] != '1') || (pick.course_check[1][0] != '2') || num_courses < 8) {
        fail();
    }
    else {
        cout << "Congratulations!! Krusty has earned enough credits to graduate" << endl;

        for (int i = 0; i < num_courses; i++) {

            cout << pick.holder2[i][0] << "." << pick.holder2[i][2] << "." << pick.holder2[i][4] << "   " << pick.holder[i] << endl;            
        }

        cout << "Thanks for using the UMB graduation status check app!" << endl;
    }
}



