#include "word_List.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

void import_Words() {
        ifstream list;
        student.open("Student list.txt", ios::in | ios:: binary);

        if(student.is_open() ){

                list >> name_;
                student >> gpa_;
                student >> totalCredits_;
                next_ = NULL;


        }
        student.close();

	return;

}

void value_Letters(){

	int size = word_List.size()/5;
	string temp[size];

	for(int i; i < size; i++){
		for(int j; j < 5; j++){
			word_List
		
		}
	}





}
