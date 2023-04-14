//
// Created by Addie Murphy on 4/13/23.
//
#include <iostream>
#include <vector>

#ifndef DSA_DSA_H
#define DSA_DSA_H

class Sorting{
private:
    std::vector<int> main;

    void merge();
    void insertion();
    void quicksort();
    void library();

public:
    void merge(std::vector<std::string> sort);
    void insertion(std::vector<std::string> sort);
    void quicksort(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
};

#endif //DSA_DSA_H
