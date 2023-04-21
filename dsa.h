#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>

#ifndef DSA_DSA_H
#define DSA_DSA_H

class Sorting{
private:

    std::vector<std::vector<std::string>> database;
    void r_merge(int lo, int hi, int criteria);
    void merge(int lo, int mid, int hi, int criteria);
    bool compareBy(int cat1, int cat2, int index1, int index2);
    int partition (int lo, int hi, int criteria);
    bool comparestr(std::string str1, std::string str2);
    void r_quicksort(int lo, int hi, int criteria);

public:
    Sorting();
    ~Sorting();
    void print_database();
    void read_data(std::string file_name);
    void merge_sort(int criteria);
    void insertion(int insertion_option, std::string song_choice, std::string genre_choice, std::string artist_choice, std::string release_year, std::string popularity);
    void library(std::vector<std::string> sort);
    void shuffle(int criteria);
    void genre_print(int genre_lookup, int mode);
    bool checkSong(int index, std::string genre);
    bool song_search(std::string song_lookup);
    void popularity_print(int pop_lookup);
    void try_quicksort(int criteria);
    std::string getTitle(int index);
};

//class Song{
//private:
//    std::string song_name;
//    std::string genre;
//    std::string artist;
//    int popularity;
//    int release_year;
//public:
//    Song(){
//        this->song_name =
//    }
//};

#endif //DSA_DSA_H
