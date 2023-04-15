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
    std::vector<std::vector<std::string>> database;
    
    void merge();
    void insertion();
    void selection();
    void library();
    int partition();
    void r_quicksort();


public:
    Sorting();
    void merge(std::vector<std::string> sort);
    void insertion(std::vector<std::string> sort);
    void selection(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    int partition (std::vector<int> &vec, int lo, int hi,std::vector<int> &vec1);
    void r_quicksort(std::vector<int> &vec, int lo, int  hi,std::vector<int> &vec1);
    
};

#endif //DSA_DSA_H
