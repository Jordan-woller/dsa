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
    void r_merge(std::vector<std::string> *vec, std::vector<std::string> *aux, int lo, int hi);
    void merge(std::vector<std::string> *vec, std::vector<std::string> *aux, int lo, int mid, int hi);
    bool compareBy(int cat1, int cat2, int index1, int index2);
    int partition (int lo, int hi, int criteria);
    int comparestr(std::string str1, std::string str2);

public:
    Sorting();
    ~Sorting();
    void read_data(std::string file_name);
    void m_sort(std::vector<std::string> *vec);
    void insertion(std::vector<std::string> sort);
    void selection(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    void r_quicksort(int lo, int hi, int criteria);
    void genre_print(int genre_lookup);
    bool song_search(std::string song_lookup);
    
};

#endif //DSA_DSA_H
