#Student Directory in c++

##Intro:

This project is done as part of the ALGORITHMS&PROGRAMMING course for my undergraduate studies.




##Details of requirement:

Write a complete C++ program to implement a student directory. Structure contains name, student id, registration date and cgpa. Your program should have the following menu. Write necessary functions for the menu:

Menu:
1- Add a new student to directory
2- Delete a student from the directory
3- List available students in the directory
4- Search a student: 
     A – Search according to student id
     B – Search according to registration year
5- Update student information  (give prompt to update all the fields)
6- Sort 
	A – According to ID  
	B – According to cgpa  
7- Quit

    struct date
       {
       int day, month, year;
       };
	struct employee
       {
       
       int ID;
       struct date reg_date; 
       float CGPA;
       }std_directory[100];`
Important notes:

•Write a user defined function for each menu option.


##License:

MIT