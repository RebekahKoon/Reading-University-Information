## Program name: lab4
## Author:       Rebekah Koon
## Date:         7/18/19
## Description:  Makefile for lab 4, which contains information about
##               students, instructors, and buildings at Oregon State
##               University. Can add new students, instructors, or 
##               buildings, save the student/instructor information to
##               a file, or read student/instructor information from
##               a file.

lab4: University.o Building.o Person.o Student.o Instructor.o Menu.o validInput.o main.o
	g++ -g University.o Building.o Person.o Student.o Instructor.o Menu.o validInput.o main.o -o lab4

University.o: University.cpp University.hpp
	g++ -c University.cpp

Building.o: Building.cpp Building.hpp
	g++ -c Building.cpp

Person.o: Person.cpp Person.hpp
	g++ -c Person.cpp

Student.o: Student.cpp Student.hpp
	g++ -c Student.cpp

Instructor.o: Instructor.cpp Instructor.hpp
	g++ -c Instructor.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab4