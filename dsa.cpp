#include <iostream>
#include <vector>
#include <algorithm>
#include "dsa.h"

//what if we had another sorted vector to store into
Sorting::Sorting(){
    this->database = std::vector<std::vector<std::string>> (5, std::vector<std::string>());
}
Sorting::~Sorting(){

}
void Sorting::read_data(std::string file_name){
    std::ifstream file_stream;
    file_stream.open(file_name);
    std::string line;
    std::vector<std::string> temp_vec;
    //looping through list to store values in each column
    int rows = 0;
    while(std::getline(file_stream, line)){
        std::istringstream ss(line);

        //getting each column and storing into vector
        //song, genre, artist, popularity, release year
        int i = 0;

        std::string temp;
        while(std::getline(ss, temp, ',')){
            temp_vec.push_back(temp);

        }

        database[0].push_back(temp_vec[0]);
        database[1].push_back(temp_vec[1]);
        database[2].push_back(temp_vec[2]);
        database[3].push_back(temp_vec[3]);
        database[4].push_back(temp_vec[4]);

        temp_vec.clear();

    }

}

void Sorting::print_database() {

     for (int i = 0 ; i < database[0].size() ; i++){
         for (int j = 0 ; j < 5 ; j++){
             if(j == 4){
                 std::cout << database[j][i];
             }else{
                 std::cout << database[j][i] << ", ";
             }
         }
         std::cout << std::endl;
     }
   std::cout << std::endl;
}

void Sorting::insertion(int insertion_option, std::string song_choice, std::string genre_choice, std::string artist_choice, std::string release_year, std::string popularity){
    //pushing back user entered criteria into the end of the vector
    database[0].push_back(song_choice);
    database[1].push_back(genre_choice);
    database[2].push_back(artist_choice);
    database[3].push_back(release_year);
    database[4].push_back(popularity);

    int size = this->database[0].size();

    for(int i = size; i >= 0; i--){
        int j = size;
        //inserts j in sorted part
        while(j < size and this->database[insertion_option][j-1][0] < this->database[insertion_option][j][0]){
            //swaps every category with each other to be in proper place
            std::swap(this->database[0][j-1], this->database[0][j]);
            std::swap(this->database[1][j-1], this->database[1][j]);
            std::swap(this->database[2][j-1], this->database[2][j]);
            std::swap(this->database[3][j-1], this->database[3][j]);
            std::swap(this->database[4][j-1], this->database[4][j]);
            j++;
        }
    }
}

int Sorting::partition(int lo, int hi, int criteria){
    std::vector<std::string> vec;

    //song, genre, artist, popularity, and release year
    if(criteria==1){
        vec = database[0];
    } else if(criteria == 2){
        vec = database[1];
    }else if(criteria == 3){
        vec = database[2];
    }else if(criteria == 4){
        vec = database[3];
    }else if(criteria == 5){
        vec = database[4];
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


void Sorting::r_quicksort(int lo, int hi, int criteria){
    if (hi <= lo) return;

    int p = partition(lo, hi, criteria);

    r_quicksort(lo, p - 1, criteria);

    r_quicksort(p + 1, hi, criteria);
}

void Sorting::shuffle(int criteria){
    int hi = database[0].size()-1;

  //print_database();
    r_quicksort(0, hi, criteria);
    print_database();
}

bool Sorting::compareBy(int cat1, int cat2, int index1, int index2){
    if (database[cat1][index1] < database[cat2][index2]) {
        return true;
    } else if (database[cat1][index1] == database[cat2][index2]) {
        return database[cat1][index1] < database[cat2][index2];
    } else {
        return false;
    }
}

//compares two strings based on ascii values
bool Sorting::comparestr(std::string str1, std::string str2){
    unsigned int length = (str1.length() > str2.length()) ? str1.length() : str2.length();

    for (int i = 0 ; i < length ; i++){
        if (str1[i] <= str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        }
    }
    return true;
}

//public function to make aux vector and call r_merge
void Sorting::merge_sort(int criteria){
    auto aux = database[criteria-1];
    r_merge(0, aux.size() - 1, criteria);
}

//private function to recursively separate vector
void Sorting::r_merge(int lo, int hi, int criteria) {
    std::vector<std::vector<std::string>> temp = database;
    //basecase(single element or empty list)
    if (lo >= hi) {return;}

    //divide
    int mid = lo + ((hi - lo) / 2);

    //recursively sort halves
    r_merge(lo, mid, criteria);
    r_merge(mid + 1, hi, criteria);

    //merge
    merge(lo, mid, hi, criteria);
}

//private function to merge each vector together
void Sorting::merge(int lo, int mid, int hi, int criteria) {
    int i = 0, j = mid + 1, k = 0;
    std::vector<std::vector<std::string>> temp (5, std::vector<std::string> (hi - lo + 1, " "));

    while (i <= mid && j <= hi){
        if (comparestr(database[criteria-1][i], database[criteria-1][j])){
            temp.at(0).at(k) = database.at(0).at(i);
            temp.at(1).at(k) = database.at(1).at(i);
            temp.at(2).at(k) = database.at(2).at(i);
            temp.at(3).at(k) = database.at(3).at(i);
            temp.at(4).at(k) = database.at(4).at(i);
            i++;
        } else {
            temp.at(0).at(k) = database.at(0).at(j);
            temp.at(1).at(k) = database.at(1).at(j);
            temp.at(2).at(k) = database.at(2).at(j);
            temp.at(3).at(k) = database.at(3).at(j);
            temp.at(4).at(k) = database.at(4).at(j);
            j++;
        }
        k++;
    }

    while (i <= mid){
        temp.at(0).at(k) = database.at(0).at(i);
        temp.at(1).at(k) = database.at(1).at(i);
        temp.at(2).at(k) = database.at(2).at(i);
        temp.at(3).at(k) = database.at(3).at(i);
        temp.at(4).at(k) = database.at(4).at(i);
        i++;
        k++;
    }

    while (j <= hi){
        temp.at(0).at(k) = database.at(0).at(j);
        temp.at(1).at(k) = database.at(1).at(j);
        temp.at(2).at(k) = database.at(2).at(j);
        temp.at(3).at(k) = database.at(3).at(j);
        temp.at(4).at(k) = database.at(4).at(j);
        j++;
        k++;
    }

    for (int x = lo ; x <= hi ; x++){
        database.at(0).at(x) = temp.at(0).at(x-lo);
        database.at(1).at(x) = temp.at(1).at(x-lo);
        database.at(2).at(x) = temp.at(2).at(x-lo);
        database.at(3).at(x) = temp.at(3).at(x-lo);
        database.at(4).at(x) = temp.at(4).at(x-lo);
    }
}

//song, genre, artist, popularity, release year
//Country
// Pop
//Rap
//80s Rock
//Indie Rock
void Sorting::genre_print(int genre_lookup, int mode){
    int x = 1;
    if(mode == 1){
        for(int i=0; i<database[1].size(); i++ ){
            if(genre_lookup==1 and database[1][i]=="Country" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
                x++;
            }else if(genre_lookup==2 and database[1][i]=="Pop" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
                x++;
            }else if(genre_lookup==3 and database[1][i]=="Rap" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
                x++;
            }else if(genre_lookup==4 and database[1][i]=="80s Rock" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
                x++;
            }else if(genre_lookup==5 and database[1][i]=="Indie Rock" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
                x++;
            }
        }
    }
    if(mode == 2){
        for(int i=0; i<database[1].size(); i++ ){
            if(genre_lookup==1 and database[1][i]=="Country" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            }else if(genre_lookup==2 and database[1][i]=="Pop" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            }else if(genre_lookup==3 and database[1][i]=="Rap" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            }else if(genre_lookup==4 and database[1][i]=="80s Rock" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            }else if(genre_lookup==5 and database[1][i]=="Indie Rock" ){
                std::cout << x << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            }
            x++;
        }

    }
}

bool Sorting::checkSong(int index, std::string genre){
    if( database[1][index-1] == genre ){
        return false;
    }
    return true;
}

std::string Sorting::getTitle(int index){
    return database[0][index-1];
}
 
bool Sorting::song_search(std::string song_lookup){
    for(int i=0; i<database[0].size(); i++ ){
      if(database[0][i] ==song_lookup ){
          std::cout<<"Found";
          return true;
      }
    }
    std::cout<<"Not Found";
    return false;
}

void Sorting::popularity_print(int pop_lookup){
    for(int i=0; i<database[3].size(); i++ ){
        int x= std::stoi(database[3][i]);
        if(x > pop_lookup ){
            std::cout<<database[3][i];
        }
    }
}