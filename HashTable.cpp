//Jack Dinkel
//CSCI 2270 - Hoenigman
//Final Project

//HashTable class file

#include <iostream>
#include "HashTable.h" //include the header file

using namespace std;

HashTable::HashTable(int size){
	/*
    Function prototype:
    HashTable::HashTable(size);

    Function Description:
    Constructor for the HashTable Class
    Initializes the hash table as an array of Movies of an inputed size
    Sets each Movie in the hashtable to null

    Example:
    HashTable h(10);

    Pre-condition:
    None

    Post-condition:
    A HashTable of type Movie is created.
    Each Movie is set to null
    */

	hashTable = new Movie[size]; //initialize hashtable as an array
	table_size = size; //set size of table

	for (int i = 0; i < table_size; i++){ //set every value in the hashtable to NULL
		hashTable[i].next = NULL;
	}
}

HashTable::~HashTable(){ //dtor
}

void HashTable::insertMovie(Movie *newMovie){ //inserts a movie into the hashtable
	/*
    Function prototype:
    void HashTable::insertMovie(Movie*);

    Function Description:
    Inserts a movie into the hashtable
    Calls hashFunction() to determine where to store it
    Uses a linked list to manage collisions
    Sorts in the linked list alphabetically

    Example:
    Movie *newMovie = new Movie;
    //set newMovie characteristics (title, year, ranking, etc...)
	h.insertMovie(newMovie);

    Pre-condition:
    A hashTable of type Movie has been initialized
    There can be any number of movies in it

    Post-condition:
    The hashTable will contain newMovie
    */

	int index = hashFunction(newMovie->title); //finds the index by using the hashFunction
	bool added = false; //determines whether to add to the end of a linked list

	//add to beginning of linked list
	if (hashTable[index].next == NULL){
		hashTable[index].next = newMovie;
	}
	//add to the middle of linked list
	else{
		Movie *traverse = new Movie; //Movie node used to move through the linked list

		traverse = &hashTable[index]; //start at the begining of the list

		while (traverse->next != NULL){
			if (newMovie->title < traverse->next->title){ //if it has reached the spot to insert
				newMovie->next = traverse->next;
				traverse->next = newMovie;
				added = true; //do not enter if statement below
				break;
			}
			traverse = traverse->next;
		}

		//add to the end of linked list
		if (!added){
			newMovie->next = NULL;
			traverse->next = newMovie;
		}
	}
	movies_in_table++;
}

Movie* HashTable::findMovie(string in_title){ //searches for a movie inside the hashtable
	/*
    Function prototype:
    Movie* HashTable::findMovie(string);

    Function Description:
    Searches for a movie in the HashTable
    Calculates the index of in_title and searches the linked list stored in that slot in the table
    Returns the found movie. If no movie is found, returns a NULL movie

    Example:
    Movie *myMovie = new Movie;
    string title;
    //set the value of title
	myMovie = h.findMovie(title);

    Pre-condition:
    The hashTable must exist
    There can be any number of movies in it

    Post-condition:
    myMovie will now contain either the found movie or NULL
    */

	int index = hashFunction(in_title); //find location of Movie inside the hashtable
	Movie *traverse = new Movie; //Movie node used to move through the linked list

	traverse = &hashTable[index]; //start at the beginning of the list

	while (traverse->next != NULL){
		if (traverse->next->title == in_title){ //if the titles match
			return traverse->next;
		}
		traverse = traverse->next;
	}

	traverse = NULL;
	return traverse; //return NULL
}

void HashTable::deleteMovie(string in_title){ //remove a movie from the hashtable
	int index = hashFunction(in_title); //find location of Movie inside the hashtable
	Movie *traverse = new Movie; //Movie node used to move through the linked list

	traverse = &hashTable[index]; //start at the beginning of the list

	while (traverse->next != NULL){
		if (traverse->next->title == in_title){ //if the titles match
			traverse->next = traverse->next->next; //overwrite the old node
			return;
		}
		traverse = traverse->next;
	}

	cout << "not found" << endl; //if the node is never found
	return;
}

void HashTable::printInventory(){ //prints the contents of the hashtable
	int count = 0; //used to keep track of whether anything is ever printed
	Movie *traverse = new Movie; //Movie node used to move through the linked list

	for (int i = 0; i < table_size; i++){ //for every linked list in the table
		traverse = &hashTable[i]; //start at the beginning of the list

		while (traverse->next != NULL){
			if (traverse->next->title.size() > 0){ //if the title exists
				cout << "Movie found in position: " << i << endl;
                cout << "\tTitle: " << traverse->next->title << endl;
                cout << "\tYear: " << traverse->next->year << endl;
                cout << "\tRanking: " << traverse->next->ranking << endl;
				count++;
			}
			traverse = traverse->next;
		}
	}

	if (count == 0){ //if nothing was ever printed (the table is empty)
		cout << "empty" << endl;
	}
}

int HashTable::hashFunction(string in_title){ //hash function, adds up ASCII values and mods by hashtable size
	int hash = 0;

	for (int i = 0; i < in_title.length(); i++){ //for each character in the string
		hash += in_title[i]; //add up the ASCII values for each character
	}
	hash %= table_size; //mod by the table size

	return hash;
}

bool HashTable::ham(string in_title, string compare_title){
	string in_title_inverse = "";
	string compare_title_inverse = "";
	float ham = 0;
	float score1;
	float score2;

	for (int i = in_title.length()-1; i >= 0; i--){
        in_title_inverse += in_title[i];
    }
    for (int i = compare_title.length()-1; i >= 0; i--){
        compare_title_inverse += compare_title[i];
    }


    for (int i = 0; i < in_title.length(); i++){
        if (in_title[i] != compare_title[i]){
            ham++;
        }
    }

    score1 = (in_title.length() - ham) / in_title.length();

    //cout << score1 << endl;


    ham = 0;


    for (int i = 0; i < in_title_inverse.length(); i++){
        if (in_title_inverse[i] != compare_title_inverse[i]){
            ham++;
        }
    }

    score2 = (in_title_inverse.length() - ham) / in_title_inverse.length();

    //cout << score2 << endl;
    if (score1 < score2){
    	score1 = score2;
    }
    if (score1 >= .5){
    	return true;
    }
    else{
    	return false;
    }
}

Movie* HashTable::buildMovieArray(){
	Movie *movieArray = new Movie[movies_in_table];
	Movie *traverse = new Movie; //Movie node used to move through the linked list
	int x = 0;

	for (int i = 0; i < table_size; i++){ //for every linked list in the table
		traverse = &hashTable[i]; //start at the beginning of the list

		while (traverse->next != NULL){
			if (traverse->next->title.size() > 0){ //if the title exists
				movieArray[x] = *traverse->next;
				x++;
			}
			traverse = traverse->next;
		}
	}
	return movieArray;
}

Movie* HashTable::movieMatch(string in_title){
	Movie *movieArray = new Movie[movies_in_table];
	int count = 0;

	cout << "No match found. Searching for close matches..." << endl;
	

	movieArray = buildMovieArray(); //convert hashtable into an array that can be searched through

	for (int i = 0; i < movies_in_table; i++){
		if (ham(in_title, movieArray[i].title)){
			cout << "Close match found:" << endl;
			cout << "\tTitle: " << movieArray[i].title << endl;
            cout << "\tYear: " << movieArray[i].year << endl;
            cout << "\tRanking: " << movieArray[i].ranking << endl;
			count++;
		}
	}
	if (count == 0){
		cout << "No close matches found." << endl;
	}

}


void HashTable::Tree_InsertNUM(Movie *newNode, Movie *root){
    Movie *x = new Movie;
    x = root;

    Movie *p = new Movie;

    // make sure not at bottom of tree
    while(x != NULL){
        p = x;

        // left branch
        if (newNode->ranking > x->ranking){
            x = x->numLeft;
        }

        // right branch
        else{
            x = x->numRight;
        }
    }   

    if (newNode->ranking > p->ranking){
        p->numLeft = newNode;   
    }

    else{
        p->numRight = newNode;
    }
}

void HashTable::Tree_InsertSTRING(Movie *newNode, Movie *root){
    Movie *traverse = new Movie; //Movie node used for moving through the tree
    Movie *parent = new Movie; //Movie node used to keep track of the parent of newNode

    traverse = root; //set traverse to start at root

    //navigate through tree to correct location
    while(traverse != NULL){ // make sure not at bottom of tree
        parent = traverse;

        if (newNode->title < traverse->title){ // left branch
            traverse = traverse->alphaLeft;
        }
        else{ // right branch
            traverse = traverse->alphaRight;
        }
    }

    //insert newNode
    if (newNode->title < parent->title){
        parent->alphaLeft = newNode;   
    }
    else{
        parent->alphaRight = newNode;
    }
}

void HashTable::buildBSTString(Movie *root){
    Movie *traverse = new Movie; //Movie node used to move through the linked list
    for (int i = 0; i < 10; i++){ //for every linked list in the table
        traverse = &HashTable::hashTable[i]; //start at the beginning of the list
        while (traverse->next != NULL){
            if (traverse->next->title.size() > 0 && traverse->next->title != root->title){ //if the title exists
                Tree_InsertSTRING(traverse->next, root);
            }
            traverse = traverse->next;
        }
    }
}

void HashTable::buildBSTNum(Movie *root){
    Movie *traverse = new Movie; //Movie node used to move through the linked list
    for (int i = 0; i < 10; i++){ //for every linked list in the table
        traverse = &HashTable::hashTable[i]; //start at the beginning of the list
        while (traverse->next != NULL){
            if (traverse->next->title.size() > 0 && traverse->next->title != root->title){ //if the title exists
                Tree_InsertNUM(traverse->next, root);
            }
            traverse = traverse->next;
        }
    }
}

void HashTable::PrintThatTreeString(Movie *root){
	if (root->alphaLeft != NULL)
	{
		PrintThatTreeString(root->alphaLeft);
	}
	//print statements
    cout << "\tTitle: " << root->title << endl;
    cout << "\tYear: " << root->year << endl;
    cout << "\tRanking: " << root->ranking << endl;
  	if (root->alphaRight != NULL)
  	{
    	PrintThatTreeString(root->alphaRight);
  	}
}

void HashTable::PrintThatTreeNum(Movie *root){
	if (root->numLeft != NULL)
	{
		PrintThatTreeNum(root->numLeft);
	}
	//print statements
    cout << "\tTitle: " << root->title << endl;
    cout << "\tYear: " << root->year << endl;
    cout << "\tRanking: " << root->ranking << endl;
  	if (root->numRight != NULL)
  	{
    	PrintThatTreeNum(root->numRight);
  	}
}