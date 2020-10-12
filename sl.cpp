#include <iostream>
#include <vector>
#include<string.h>
#include<iterator>
#include<cmath>

using namespace std;

//defining struct student to contain four variables
struct Student {

  char firstName[20];
  char lastName[20];
  int studentId;
  float GPA;

};
//declaring the methods implemented later on in the code
void addStudent(vector<Student> &studentList1);
void printStudent(vector<Student> studentList1);
void deleteStudent(vector<Student> &studentList1);

int main() {
  //create a vector of 20 students
  vector<Student> studentList(20);
  //this while goes on forever, but can be broken by typing quit
  while(true){
    cout << "Type add,print,delete, or quit" <<  endl;
    char input[20];
    cin >> input;
    if(input[0]=='a' || input[0]=='A'){
      addStudent(studentList);
    }
    else if(input[0]=='p' || input[0]=='P'){
      printStudent(studentList);
    }
    else if(input[0]=='d' || input[0]=='D'){
      deleteStudent(studentList);
    }
    else if(input[0]=='q' || input[0]=='Q'){
      break;
    }
  }
  
  return 0;
  
}
void addStudent(vector<Student>  &studentList1){
  //read in all the variables from cin
	cout << "Please enter the student's first name" << endl;
	char firstNamee[20];
	cin >> firstNamee;
	cout << "Please enter the student's last name" << endl;
	char lastNamee[20];
	cin >> lastNamee;
	cout << "Please enter the studen't id number" << endl;
	int studentIdd;
	cin >> studentIdd;
	cout << "Please enter the student's GPA" << endl;
	float GPAA;
	cin >>  GPAA;
	//create a new instance of struct
	struct Student addS;
	//copy the inputs into the struct variables
	strcpy(addS.firstName,firstNamee);
	strcpy(addS.lastName,lastNamee);
	addS.studentId = studentIdd;
	addS.GPA = GPAA;
	//add the student to the end of the vector
	studentList1.push_back(addS);
}

void printStudent(vector<Student> studentList1){
  //create an iterator
  vector<Student>::iterator ptr;
  //cycle through the student list using iterator
  for(ptr = studentList1.begin(); ptr < studentList1.end(); ptr++){
        if(ptr->firstName[0]=='\0'){
	  //if null, do nothing
        }
	else{
	  char output1[20];
	  strcpy(output1,ptr->firstName);
	  for(int a = 0; a < 20; a++){
	    if(output1[a]=='\0'){
	      break;
	    }
	    //cycle through the letters of student's first name and print them out
	    cout<<output1[a];
	  }
	  cout<<" ";
	  //copy last name to an output array
	  strcpy(output1,ptr->lastName);
	  //cycle through the letters of the student's last name and print them out
	  for(int a = 0; a < 20; a++){
	    if(output1[a]=='\0'){
	      break;
	    }
	    cout<<output1[a];
	  }
	  //to round to two decimals, first multiply by 100 to get all the needed numbers to the left side of the decimal
	  //then add 0.5 to ensure proper rounding to the whole number
	  //after the number is truncated, divide by 100 
	  float gpa1 = floor(ptr->GPA*100+0.5)/100;
	  cout<<", " << ptr->studentId << ", " << gpa1 << endl;
	}
      }  
      
}

void deleteStudent(vector<Student> &studentList1){
  cout << "Enter the ID number of the student you would like to delete" << endl;
  int inputId;
  cin >> inputId;
  //create an iterator for the vector
  vector<Student>::iterator ptr;
  //cycle through studentList
  for(ptr = studentList1.begin(); ptr < studentList1.end(); ptr++){
    if(ptr->firstName[0]=='\0'){
    }
    //if the studentId of the ptr is the same as the id the user inputted, delete it
    else if(ptr->studentId==inputId){
      studentList1.erase(ptr);
      return;
    }
  }
  cout << "No students match that ID" << endl;
}
