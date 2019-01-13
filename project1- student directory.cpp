#include <iostream>
#include <string>
#include <algorithm>
//#include <assert.h>

using namespace std;

//STRUCTURE FOR ENTRIES
struct date
       {
       int day, month, year;
       };

struct Student
       {
       string name;
       int id;
       struct date reg_date; 
       float CGPA;
       bool avlble;
       }std_directory[100];

//INITIALIZING FUNCTIONS & Global variables
void addStudent(struct Student *std);
void search_student(int search_id, int users);
void search_regDate(date search_date, int users);
void directoryList(int users);
void updateStudent(struct Student *std);
struct Student *findStudent(int search_id, int users);
//void deleteStudent(int search_id, int users);
void deleteStudent(struct Student *std, int users, struct Student *std2);
void sortByID(int users);
void sortByRegDate(int users);
bool acompare(Student lhs, Student rhs) { return lhs.id < rhs.id; }
void copyTwoStds(struct Student *std1, struct Student *std2);
void sortByCGPA(int users);

int usero;

//MAIN FUNCTION
int main(){
    int choice, search_id, search_id2, user = 0;
    struct date search_date;

    while(true){
        cout << "**********STUDENTBOOK MAIN MENU**********" << endl;
        cout << "*1- Add a new student to directory" << endl;
        cout << "*2- Delete a student from the directory" << endl;
        cout << "*3- List available students in the directory" << endl;
        cout << "*4- Search directory for a student " << endl;
        cout << "*5- Update student information " /*(give prompt to update all the fields) */<< endl;
        cout << "*6- Sort Students" << endl;
        cout << "*7- Quit program" << endl;
        cout << "*8- copy student 2 to 1" << endl;
        cout << "*****************************************" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            system("cls");
            addStudent(&std_directory[user]);
            user += 1;
            system("cls");
        } else if (choice == 2){
            system("cls");
            cout << "Enter student ID to be deleted:";
            cin >> search_id;
            //deleteStudent(search_id, user);
            //search_id2 = std_directory[user].id;
            search_id2 = std_directory[user-1].id;
            deleteStudent(findStudent(search_id, user), user, findStudent(search_id2, user) );
            user = usero;
        } else if (choice == 3){
            cout << endl;
            directoryList(user);
            cout << endl;
        } else if (choice == 4){
            system("cls");
            choice=0;
            cout << "1 - Search according to student id" << endl;
            cout << "2 - Search according to registration year" << endl;
            cout << "Enter choice: ";
            cin >> choice;
                if (choice==1){
                           system("cls");
			               cout << "Enter search ID: ";
			               cin >> search_id;
			               cout << endl;
			               search_student(search_id, user);
			               cout << endl;
                           }
                else if (choice == 2 ){
                            system("cls");
			                cout << "Enter search date: ";
			                cin >> search_date.day >> search_date.month >> search_date.year ;
			                cout << endl;
			                search_regDate(search_date,/* search_date.month, search_date.year,*/ user);
			                cout << endl;
                            }
            

        } else if (choice == 5){
            system("cls");
            cout << "Enter student ID:";
            cin >> search_id;
            //findStudent(search_id, user);
            updateStudent(findStudent(search_id, user));
        } else if (choice == 6){
            system("cls");
            choice=0;
            cout << "1 - Sort students according to student ID" << endl;
            cout << "2 - sort students according to CGPA" << endl;
            cout << "Enter choice: ";
            cin >> choice;
                if (choice==1){
                           system("cls");
			               cout << endl;
			               sortByID(user);
			               cout << "Done!"<<endl;
                           }
                else if (choice == 2 ){
                            system("cls");
			                cout << endl;
			                sortByCGPA(user);
			                cout << "Done!"<<endl;
                            }
        } else if (choice == 7){
            system("cls");
            cout << "Goodbye!" << endl;
            exit(1);
		} else if (choice == 8){
			system("cls");
			cout << "Enter  source student (no.2)"<< endl;
			cin >> search_id2;
			cout << "Enter  destination student (no.1)"<< endl;
			cin >> search_id;
			copyTwoStds(findStudent(search_id, user), findStudent(search_id2, user));
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

//option one
void addStudent(struct Student *std){
    cout << "Enter student ID: ";
    cin >> std->id;

    cout << "Enter Student registeration date: ";
    cin >> std->reg_date.day >> std->reg_date.month >> std->reg_date.year ;
    //std->reg_date.day=01; std->reg_date.month =9; std->reg_date.year = 2018 ;  //remove later
    cout << "Enter student CGPA: ";
    cin >> std->CGPA;
    //std->CGPA = 4.0 ;  //remove later
    cout << "Enter student name: ";
    cin >> std->name;
    
    std->avlble = 1;

 /*   cout << "Enter mark for final: ";
    cin >> exam->final; */
}

//option 2
void deleteStudent(struct Student *std, int users, struct Student *std2){
     
	if (std){		
		copyTwoStds(findStudent(std->id, users), findStudent(std2->id, users));
		std_directory[users-1].avlble=0 ;  //hiding from listing until filled by another
		users-- ; //so that when adding a new entry it actually updates the one deleted
		usero = users;
		cout << "Done!"<<endl;
	}else{
		cout << "Student ID Doesn't Exist!"<< endl;
		cout << "-------------------------------------" << endl;
	}
	usero = users;
}
//option three //done
void directoryList(int users){
	if(users == 0){
		cout << "Student book is empty!" << endl;
		cout << "-------------------------------------" << endl;
	} else{
        cout << "Entries:" << users << endl;
        cout << endl;
		for(int i = 0; i < users; i++){
			if (std_directory[i].avlble==1){
			
			cout << "Student ID: " << std_directory[i].id << endl;
			cout << "Student Name: " << std_directory[i].name << endl;
			cout << "Student Registration date: " << std_directory[i].reg_date.day<<","<< std_directory[i].reg_date.month<<","<< std_directory[i].reg_date.year<< endl;
			cout << "Student CGPA: " << std_directory[i].CGPA << endl;
			cout << "-------------------------------------" << endl;
			cout << endl;
			}
		}
	}
}

//option 4 A //done

void search_student(int search_id, int users){
	int i = 0;
	for(i; i <= users; i++){
		if(std_directory[i].id == search_id){
			cout << "Student ID: " << std_directory[i].id << endl;
			cout << "Student Name: " << std_directory[i].name << endl;
			cout << "Student CGPA: " << std_directory[i].CGPA << endl;
			cout << "Student Registration date: " << std_directory[i].reg_date.day<<","<< std_directory[i].reg_date.month<<","<< std_directory[i].reg_date.year<< endl;
			cout << "-------------------------------------" << endl;
			break;
		}
	}
	
	if(i == users + 1){
		cout << "Student not found!" << endl;
		cout << "-------------------------------------" << endl;
	}
}


//option 4 B //ýn progress //done
void search_regDate(date search_date, int users){
	int i = 0;
	for(i; i <= users; i++){
		if(std_directory[i].reg_date.year== search_date.year && std_directory[i].reg_date.month== search_date.month && std_directory[i].reg_date.day==search_date.day){
			cout << "Student ID: " << std_directory[i].id << endl;
			cout << "Student Name: " << std_directory[i].name << endl;
			cout << "Student CGPA: " << std_directory[i].CGPA << endl;
			cout << "Student Registration date: " << std_directory[i].reg_date.day<<","<< std_directory[i].reg_date.month<<","<< std_directory[i].reg_date.year<< endl;
			cout << "-------------------------------------" << endl;
			break;
		}
	}
	
	if(i == users + 1){
		cout << "Student not found!" << endl;
		cout << "-------------------------------------" << endl;
	}
}

//option 5 //Done
           //Another Way
void updateStudent(struct Student *std){
    if (std != NULL){
    cout << "Enter student name: ";
    cin >> std->name; 
    cout << "Enter Student registeration date: ";
    cin >> std->reg_date.day >> std->reg_date.month >> std->reg_date.year ;
    cout << "Enter student CGPA: ";
    cin >> std->CGPA;
    cout << "Enter student ID: ";
    cin >> std->id; 
	}
	if (std = NULL){
		cout << "Student ID Does Not Exist!"<< endl;
		cout << "-------------------------------------" << endl;
	}
     
}
     
//option 6
/*bool acompare(Student lhs, Student rhs) { 
return lhs.id < rhs.id; 
}*/
         //Part A
void sortByID(int users){
	 struct Student temp;
	 int i, j;
     //sort(std_directory, std_directory+100, acompare);
     for (i = 1; i<users; i++)             // i indicates the pass number 
        {
              for (j =0; j<users - i; j++)   /* j will indicate the position of the 
                                             value being compared to its neighbor*/
              {                                                                  
                      if (std_directory[ j ].id > std_directory[ j+1 ].id ) // a swap must be made
                      {                          
                             temp =std_directory[j+1];
                             std_directory[j+1]= std_directory[j];
                             std_directory[j]= temp;
                      }          
               }
        }

}
        //Part B
void sortByCGPA(int users){
	struct Student temp;
	 int i, j;
     for (i = 1; i<users; i++)             // i indicates the pass number 
        {
              for (j =0; j<users - i; j++)   /* j will indicate the position of the 
                                             value being compared to its neighbor*/
              {                                                                  
                      if (std_directory[ j ].CGPA < std_directory[ j+1 ].CGPA ) // a swap must be made
                      {                          
                             temp =std_directory[j+1];
                             std_directory[j+1]= std_directory[j];
                             std_directory[j]= temp;
                      }          
               }
        }

}        
        //
void sortByRegDate(int users){
     struct Student temp;
	 int i, j;
     for (i = 1; i<users; i++)             // i indicates the pass number 
        {
              for (j =0; j<users - i; j++)   /* j will indicate the position of the 
                                             value being compared to its neighbor*/
              {                                                                  
                      if (std_directory[ j ].reg_date.year > std_directory[ j+1 ].reg_date.year ) // a swap must be made
                      {                          
                             temp =std_directory[j+1];
                             std_directory[j+1]= std_directory[j];
                             std_directory[j]= temp;
                      } else if(std_directory[ j ].reg_date.year == std_directory[ j+1 ].reg_date.year && std_directory[ j ].reg_date.month > std_directory[ j+1 ].reg_date.month  ){
                      		 temp =std_directory[j+1];
                             std_directory[j+1]= std_directory[j];
                             std_directory[j]= temp;
					  } else if(std_directory[ j ].reg_date.year == std_directory[ j+1 ].reg_date.year && std_directory[ j ].reg_date.month == std_directory[ j+1 ].reg_date.month && std_directory[ j ].reg_date.day > std_directory[ j+1 ].reg_date.day  ){
					  		 temp =std_directory[j+1];
                             std_directory[j+1]= std_directory[j];
                             std_directory[j]= temp;
					  }
               }
        }
}


//returning a pointer function //experimental!
struct Student *findStudent(int search_id, int users){
    int i = 0;
	for(i; i <= users; i++){
		if(std_directory[i].id == search_id){
            return &std_directory[i];
			break;
		}
    }
    if(i == users + 1){
		return NULL;
	} 
}

//copy two structs (destination_std, source_std)
void copyTwoStds(struct Student *std1, struct Student *std2){
	// *std1=*std2;
	 std1->id=std2->id;
	 std1->reg_date.day=std2->reg_date.day; std1->reg_date.month=std2->reg_date.month; std1->reg_date.year=std2->reg_date.year;
	 std1->CGPA=std2->CGPA;
	 std1->name=std2->name;
}




/*<----------------------------------------------------------End!--------------------------------------------------------------->*/
