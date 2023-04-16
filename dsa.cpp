#include <iostream>
#include<vector>
#include "dsa.h"

Sorting::Sorting(){}
Sorting::~Sorting(){}

void Sorting::read_data(std::string file_name){
    std::ifstream file_stream;
    file_stream.open(file_name);
    std::string line;
    //looping through list to store values in each column
    while(std::getline(file_stream, line)){
        std::istringstream ss(line);

        //getting each column and storing into vector
        //song, genre, artist, popularity, release year
        int i = 0;
        std::string temp;
        while(ss >> temp){
            (*database)[i].push_back(temp);
            i++;
        }
    }
    // this->merge((*database)[0]);
}

void Sorting::insertion(std::vector<std::string> sort){
    int size = this->database[0].size();

    for(int i = 1; i < size; i++){
        int j = 1;
        //inserts j in sorted part
        while(j > 0 and this->database[0][j-1][0] > this->database[0][j][0]){
            //swaps every category with each other to be in proper place
            std::swap(this->database[0][j-1], this->database[0][j]);
            std::swap(this->database[1][j-1], this->database[1][j]);
            std::swap(this->database[2][j-1], this->database[2][j]);
            std::swap(this->database[3][j-1], this->database[3][j]);
            std::swap(this->database[4][j-1], this->database[4][j]);
            j--;
        }
    }
}


int Sorting:: partition(int lo, int hi, int criteria){
    std::vector<std::string> vec;

    //song, genre, artist, popularity, and release year
    if(criteria==1){
        vec = this->database[0];
    } else if(criteria == 2){
        vec = this->database[1];
    }else if(criteria == 3){
        vec = this->database[2];
    }else if(criteria == 4){
        vec = this->database[3];
    }else if(criteria == 5){
        vec = this->database[4];
    }

    int i = lo;
    int j = hi + 1;
    while (1) {

        // while A[i] < pivot, increase i
        while (vec[++i] < vec[lo])
            if (i == hi) break;

        // while A[i] > pivot, decrease j
        while (vec[lo] < vec[--j])

            if (j == lo) break;

        // if i and j cross exit the loop
        if(i >= j) break;

        // swap A[i] and A[j]
        std::swap(vec[i], vec[j]);
        std::swap(database[0][i], database[0][j]);
        std::swap(database[1][i], database[1][j]);
        std::swap(database[2][i], database[2][j]);
        std::swap(database[3][i], database[3][j]);
        std::swap(database[4][i], database[4][j]);


    }
    std::swap(vec[lo], vec[j]);
    std::swap(database[0][lo], database[0][j]);
    std::swap(database[1][lo], database[1][j]);
    std::swap(database[2][lo], database[2][j]);
    std::swap(database[3][lo], database[3][j]);
    std::swap(database[4][lo], database[4][j]);


    //return pivot's position
    return j;
}

void Sorting:: r_quicksort(std::vector<std::vector<std::string>> &database, int lo, int  hi,int criteria)
{
    if (hi <= lo) return;

    int p = partition(database, lo, hi,criteria);

    r_quicksort(database, lo, p - 1,criteria);

    r_quicksort(database, p + 1, hi,criteria);
}

bool Sorting::compareBy(int cat1, int cat2, int index1, int index2){
    if ((*database)[cat1][index1] < (*database)[cat2][index2]) {
        return true;
    } else if ((*database)[cat1][index1] == (*database)[cat2][index2]) {
        return (*database)[cat1][index1] < (*database)[cat2][index2];
    } else {
        return false;
    }
}



/*
int main() {
    std::vector<int>cassidy;
    std::vector<int>cooper;

    for(int i=3; i>0; i--){
        cassidy.push_back(i);
    }
    // for(int i=0; i<3; i++){
    //      cooper.push_back(i);
    //  }

    for(int i=0; i<3; i++){
        std::cout<<cassidy[i];
    }
    std::cout<<std::endl;

    for(int i=0; i<3; i++){
    std::cout<<cooper[i];
      }

    std::cout<<std::endl;


    r_quicksort(cassidy, 0, 2,cooper);


    for(int i=0; i<3; i++){
        std::cout<<cassidy[i];
    }
}
*/
