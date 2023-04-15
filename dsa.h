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
    
    void merge();
    void insertion();
    void selection();
    void library();
    int partition();
    void r_quicksort();
   

public:
    Sorting();
    ~Sorting();
    void read_data(std::string file_name);
    void merge(std::vector<std::string> sort);
    void insertion(std::vector<std::string> sort);
    void selection(std::vector<std::string> sort);
    void library(std::vector<std::string> sort);
    int partition (std::vector<int> &vec, int lo, int hi,std::vector<int> &vec1);
    void r_quicksort(std::vector<int> &vec, int lo, int  hi,std::vector<int> &vec1);
    
};

#endif //DSA_DSA_H
