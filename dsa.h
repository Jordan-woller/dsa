#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>

#ifndef DSA_DSA_H
#define DSA_DSA_H

class Sorting{
private:

    std::vector<std::vector<std::string>> *database;
    void r_merge(int lo, int hi, int criteria);
    void merge(int lo, int mid, int hi, int criteria);
    bool compareBy(int cat1, int cat2, int index1, int index2);
    int partition (int lo, int hi, int criteria);
    bool comparestr(std::string str1, std::string str2);

public:
    Sorting();
    ~Sorting();
    void print_database();
    void read_data(std::string file_name);
    void merge_sort(int criteria);
    void insertion(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    void r_quicksort(int lo, int hi, int criteria);
    void genre_print(int genre_lookup);
    bool song_search(std::string song_lookup);
    void popularity_print(int pop_lookup);
    
};

#endif //DSA_DSA_H
