#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>

#ifndef DSA_DSA_H
#define DSA_DSA_H

using namespace std;

class Sorting{
private:

    std::vector<std::vector<std::string>> *database;
    
    bool compareBy(int cat1, int cat2, int index1, int index2);
    int partition(std::vector<std::vector<std::string>> &database, int lo, int hi, int criteria);
public:
    Sorting();
    ~Sorting();
    void read_data(std::string file_name);
    void merge(std::vector<std::string> sort);
    void insertion(std::vector<std::string> sort);
    void selection(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    void r_quicksort(std::vector<std::vector<std::string>> &database, int lo, int  hi,int criteria);
    
};

#endif //DSA_DSA_H
