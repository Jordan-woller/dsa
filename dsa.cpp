#include <iostream>
#include <vector>
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
        std::vector<std::string> temp_vec;
        while(ss >> temp){
            temp_vec.push_back(temp);
            i++;
        }
        database[i].push_back(temp_vec);
    }
//     this->m_sort((*database)[0]);
}

void Sorting::insertion(std::vector<std::string> sort){
    int size = this->database[0].size();

    for(int i = 1; i < size; i++){
        int j = 1;
        //inserts j in sorted part
        while(j > 0 and this->database[0][j-1][0] > this->database[0][j][0]){
            //swaps every category with each other to be in proper place
            std::swap(this->database[0][j-1], this->database[0][j]);
            std::swap(this->database[1][j-1], this->database[1][j]);
            std::swap(this->database[2][j-1], this->database[2][j]);
            std::swap(this->database[3][j-1], this->database[3][j]);
            std::swap(this->database[4][j-1], this->database[4][j]);
            j--;
        }
    }
}

int Sorting::partition(int lo, int hi, int criteria){
    std::vector<std::string> vec;

    //song, genre, artist, popularity, and release year
    if(criteria==1){
        vec = (*database)[0];
    } else if(criteria == 2){
        vec = (*database)[1];
    }else if(criteria == 3){
        vec = (*database)[2];
    }else if(criteria == 4){
        vec = (*database)[3];
    }else if(criteria == 5){
        vec = (*database)[4];
    }

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
        std::swap(database[0][i], database[0][j]);
        std::swap(database[1][i], database[1][j]);
        std::swap(database[2][i], database[2][j]);
        std::swap(database[3][i], database[3][j]);
        std::swap(database[4][i], database[4][j]);
    }

    std::swap(vec[lo], vec[j]);
    std::swap(database[0][lo], database[0][j]);
    std::swap(database[1][lo], database[1][j]);
    std::swap(database[2][lo], database[2][j]);
    std::swap(database[3][lo], database[3][j]);
    std::swap(database[4][lo], database[4][j]);


    //return pivot's position
    return j;
}

void Sorting::r_quicksort(int lo, int hi, int criteria)
{
    if (hi <= lo) return;

    int p = partition(lo, hi, criteria);

    r_quicksort(lo, p - 1, criteria);

    r_quicksort(p + 1, hi, criteria);
}

bool Sorting::compareBy(int cat1, int cat2, int index1, int index2){
    if ((*database)[cat1][index1] < (*database)[cat2][index2]) {
        return true;
    } else if ((*database)[cat1][index1] == (*database)[cat2][index2]) {
        return (*database)[cat1][index1] < (*database)[cat2][index2];
    } else {
        return false;
    }
}

//compares two strings
int Sorting::comparestr(std::string str1, std::string str2){
    unsigned int length = (str1.length() > str2.length()) ? str1.length() : str2.length();

    for (int i = 0 ; i < length ; i++){
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }

    return 0;
}

//public function to make aux vector and call r_merge
void Sorting::m_sort(std::vector<std::string> *vec){
    auto aux = vec;
    r_merge(vec, aux, 0, (*aux).size() - 1);
    delete aux;
}

//private function to recursively separate vector
void Sorting::r_merge(std::vector<std::string> *vec, std::vector<std::string> *aux, int lo, int hi) {

    //basecase(single element or empty list)
    if (hi <= lo) return;

    //divide
    int mid = lo + (hi - lo) / 2;

    //recursively sort halves
    r_merge(vec, aux, lo, mid);
    r_merge(vec, aux, mid + 1, hi);

    //merge
    merge(vec, aux, lo, mid, hi);
}

//private function to merge each vector together
void Sorting::merge(std::vector<std::string> *vec, std::vector<std::string> *aux, int lo, int mid,int hi) {

    // copy array - ask about this in office hours
    std::memcpy(aux + lo, vec + lo, (hi - lo + 1 * (*vec).size()));

    // merge
    int i = lo, j = mid + 1;

    for (int k = lo; k <= hi; k++) {
        if (i > mid){
            (*vec)[k] = (*aux)[j++];
        }
        else if (j > hi){
            (*vec)[k] = (*aux)[i++];
        }
        else if (comparestr((*aux)[j], (*aux)[i]) == -1){
            (*vec)[k] = (*aux)[j++];
        }
        else{
            (*vec)[k] = (*aux)[i++];
        }
    }
}

