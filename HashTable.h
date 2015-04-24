//Jack Dinkel
//CSCI 2270 - Hoenigman
//Final Project

//HashTable header file

#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Movie{
    std::string title;
    int year;
    int ranking;
    Movie *next;
    Movie *alphaLeft;
    Movie *alphaRight;
    Movie *numLeft;
    Movie *numRight;

    Movie(){};

    Movie(std::string in_title, int in_year)
    {
        title = in_title;
        year = in_year;
        next = NULL;
        alphaRight = NULL;
        alphaLeft = NULL;
        numRight = NULL;
        numLeft = NULL;
    }
};

class HashTable
{
    public:
        HashTable(int size);
        ~HashTable();
        void insertMovie(Movie *newMovie);
        Movie* findMovie(std::string in_title);
        void deleteMovie(std::string in_title);
        void printInventory();
        int hashFunction(std::string in_title);
        bool ham(std::string in_title, std::string compare_title);
        Movie* buildMovieArray();
        Movie* movieMatch(std::string in_title);

        void Tree_InsertNUM(Movie *newNode, Movie *root);
        void Tree_InsertSTRING(Movie *newNode, Movie *root);
        void buildBSTString(Movie *root);
        void buildBSTNum(Movie *root);
        void PrintThatTreeString(Movie *root);
        void PrintThatTreeNum(Movie *root);
        Movie *root;
    protected:
    private:
        int table_size;
        int movies_in_table = 0;
        Movie *hashTable;


};

#endif // HASHTABLE_H
