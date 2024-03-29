#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>

#ifndef DSA_DSA_H
#define DSA_DSA_H

class Song{
public:
    std::string song_name;
    std::string genre;
    std::string artist;
    std::string popularity;
    std::string release_year;
    Song(std::string name, std::string genre, std::string artist, std::string popularity, std::string year){
        this->song_name = name;
        this->genre = genre;
        this->artist = artist;
        this->popularity = popularity;
        this->release_year = year;
    }
    friend class Sorting;
};


class Sorting{
private:
    std::vector<std::vector<std::string>> database;
    void r_merge(int lo, int hi, int criteria);
    void merge(int lo, int mid, int hi, int criteria);
    int partition (int lo, int hi, int criteria);
    bool comparestr(std::string str1, std::string str2);
    void r_quicksort(int lo, int hi, int criteria);
    std::string upper(std::string word);
    void heapify(std::vector<std::string>& myVec, int n, int i);
    void heapify2(std::vector<std::string>& myVec, int n, int i, std::vector<std::vector<std::string>>& mVec);

public:
    Sorting();
    ~Sorting();
    void print_database();
    void read_data(std::string file_name);
    void merge_sort(int criteria);
    void insertion(int insertion_option, std::string song_choice, std::string genre_choice, std::string artist_choice, std::string release_year, std::string popularity);
    void shuffle(int criteria);
    void heapSort(int criteria);
    void heap_sort(std::vector<std::string>& myVec);
    void heap_sort2(std::vector<std::string>& myVec, std::vector<std::vector<std::string>>& mVec);
    void genre_print(int genre_lookup, int mode);
    bool checkSong(int index, std::string genre);
    void popularity_print(int pop_lookup);
    std::vector<std::string> get(int row);
    std::string getTitle(int index);
    std::string getYear(int index);
    std::vector<int> getIndexs(std::string criteria, int category);
    std::vector<std::vector<std::string>> getRecommend(std::vector<int> genreVec, std::vector<std::vector<std::string>> song_choice_vec);
    std::string multi_line();
};

#endif //DSA_DSA_H
