//
// Created by Addie Murphy on 4/13/23.
//
#include <iostream>
#include <vector>
#include <cstring>

#ifndef DSA_DSA_H
#define DSA_DSA_H

// test comment for jake

class Sorting{
private:
    std::vector<int> year;
    std::vector<std::string> artist;
    std::vector<std::string> genre;
    std::vector<int> popularity;
    std::vector<std::string> title;

    void merge();
    void insertion();
    void selection();
    void library();
    int partition();
    void r_quicksort();


public:
    void merge(std::vector<std::string> sort);
    void insertion(std::vector<std::string> sort);
    void selection(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    int partition (int *A, int lo, int hi);
    void r_quicksort(int *A,int lo, int  hi);
    
};

#endif //DSA_DSA_H
