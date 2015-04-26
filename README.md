# Dinkel_CSCI2270_FinalProject
Repo for my final project for CSCI 2270: Data Structures


Project Summary:
	This project is an expansion on Assignment9 that dealt with using
	a hashtable to store movie information. This expansion will be a
	tool to help users keep track of their favorite movies. As such,
	it will prompt users to input a ranking, 1-10 for each movie they
	store. The program will then give the options of printing the movies
	in order of rank, or in alphabetical order. This implementation will
	be done by storing the movies in a binary search tree.

	The expansion will also add additional functionality to the search
	function. The user input should not have to directly match the name
	of a movie, but should just be similar enough so that the program
	can find a reasonable match. For example: 'Interstelar' should be
	similar enough to still return 'Interstellar.'


How to Run:
	This program is intended to run on Linux, and was specifically tested on
	Ubuntu 14.04 'Trusty Tahr'

	Download all files and store in the same directory.
	This can be done by using the Download Zip button on the bottom left of
	the page for the repo on Github.com, or by cloning directly into the repo.

	To clone, first make sure you have git installed on your computer. If you
	do not, use the Linux command: sudo apt-get install git

	Use the command line to navigate into the directory in which you wish to
	store the repo. Then use the command:
	git clone https://github.com/JackDinkel/Dinkel_CSCI2270_FinalProject.git

	Now use the cd command to navigate into the directory containing the repo
	that has just been created

	To compile, use the Linux command: g++ -std=c++11 Main.cpp HashTable.cpp
	To run, use the Linux command: ./a.out
	Code should run.

	If code does not compile correctly, verify that g++ is properly installed.
	To install g++, use the Linux command: sudo apt-get install g++

	Additionally, a precompiled version of the original program can be found
	inside the exe folder. To run this, navigate to the directory in the
	comand line and use the command: ./a.out


Dependencies:
	None


System Requirements:
	This program is written specifically to be run on Linux, but should
	work on any operating system with a command line compiler.


Group Members:
	Jack Dinkel
	Derek Gorthy


Contributors:


Open Issues/Bugs:
	Possible Expansion:
	The "Delete movie" option on the main menu does not have a movie match
	functionality similar to the "Find movie" option. The functionality could
	be added in a future version of this project.