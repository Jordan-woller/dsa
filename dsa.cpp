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
            this->database[i].push_back(temp);
            i++;
        }
    }
}

int Sorting:: partition(std::vector<int> &vec, int lo, int hi,std::vector<int> &vec1){

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
        std::swap(vec1[i], vec1[j]);
    }
    // swap the pivot with A[j]
    std::swap(vec[lo], vec[j]);
    std::swap(vec1[lo], vec1[j]);

    //return pivot's position
    return j;
}

void Sorting:: r_quicksort(std::vector<int> &vec, int lo, int  hi,std::vector<int> &vec1)
{
    if (hi <= lo) return;

    int p = partition(vec, lo, hi,vec1);

    r_quicksort(vec, lo, p - 1,vec1);

    r_quicksort(vec, p + 1, hi,vec1);
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

    std::cout<<std::endl;
    for(int i=0; i<3; i++){
        std::cout<<cooper[i];
    }

}*/
