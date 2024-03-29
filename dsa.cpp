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
        while(std::getline(ss, temp, '#')){
            temp_vec.push_back(temp);
        }

        database[0].push_back(temp_vec[0]);
        database[1].push_back(temp_vec[1]);
        database[2].push_back(temp_vec[2]);
        database[3].push_back(temp_vec[3]);
        database[4].push_back(temp_vec[4]);

        temp_vec.clear();

    }
    file_stream.close();
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
//allows for a cin to take in multiple spaced characters so that songs/artists and genre can have more than one word
std::string Sorting::multi_line(){
    std::string choice;
    while(std::getline(std::cin, choice)){
        if(choice.empty()) continue;
        if(!choice.empty()) break;
        std::istringstream is(choice);
    }
    return choice;
}

//if the first character in the string is an actual character and not a digit, it transforms it to an uppercase
std::string Sorting::upper(std::string word){
    //if word is not a number, it calls toupper to convert to upper case
    if(!std::isdigit(word[0])){
        word[0] = std::toupper(word[0]);
    }
    //std::cout << "word: " <<  word << std::endl;
    return word;
}

//sorts database by insertion sort. Takes in song and all criteria for song along with the criteria the user chose to sort by
void Sorting::insertion(int insertion_option, std::string song_choice, std::string genre_choice,
                        std::string artist_choice, std::string release_year, std::string popularity){
    //calls upper function for song, genre, and artist to ensure they are properly capitalized
    song_choice = upper(song_choice);
    genre_choice = upper(genre_choice);
    artist_choice = upper(artist_choice);

    //pushing back user entered criteria into the end of the vector
    database[0].push_back(song_choice);
    database[1].push_back(genre_choice);
    database[2].push_back(artist_choice);
    database[3].push_back(popularity);
    database[4].push_back(release_year);

    int size = database[0].size()-1; //getting size of database

    //if the insertion option is a string, it does insertion sort by ascii character value
    if(insertion_option == 0 or insertion_option == 1 or insertion_option == 2){
        for(int i = size; i > 0; i--){ //goes through size of database
            int j = i; //sets j to i
            while(j > 0){
                //calls comparestr method to compare by ascii value
                if(comparestr(database[insertion_option][j],
                              database[insertion_option][j-1])){
                    //swaps every category with each other to be in proper place
                    std::swap(database[0][j-1], database[0][j]);
                    std::swap(database[1][j-1], database[1][j]);
                    std::swap(database[2][j-1], database[2][j]);
                    std::swap(database[3][j-1], database[3][j]);
                    std::swap(database[4][j-1], database[4][j]);
                }
                j--; //decrements j to iteratively compare elements to the left
            }
        }
    } else{ //if insertion option is 4 or 5, it compares by integer value
        for(int k = size; k > 0; k--){ //goes through size of database
            int l = k;
            while(l > 0){
                //converts string of priority of year into an int to be compared
                int a = std::stoi(database[insertion_option][l-1]);
                int b = std::stoi(database[insertion_option][l]);

                if(a > b){
                    //swaps every category with each other to be in proper place
                    std::swap(database[0][l-1], database[0][l]);
                    std::swap(database[1][l-1], database[1][l]);
                    std::swap(database[2][l-1], database[2][l]);
                    std::swap(database[3][l-1], database[3][l]);
                    std::swap(database[4][l-1], database[4][l]);
                }
                l--; //decrements j to iteratively compare elements to the left
            }
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
    while (true) {
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

}

//compares two strings based on ascii values
bool Sorting::comparestr(std::string str1, std::string str2){
    unsigned int length = (str1.length() > str2.length()) ? str1.length() : str2.length();

    for (int i = 0 ; i < length ; i++){
        if (str1[i] < str2[i]) {
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
    //current indexes of subarrays
    int i = lo, j = mid + 1, k = 0;
    //creating temp vector of same size as database
    std::vector<std::vector<std::string>> temp (5, std::vector<std::string> (hi - lo + 1, " "));

    //while not to the end of either sub vector, call comparestr function on vector of that criteria
    //if true, first vector index at i is moved to temp, otherwise second vector index at j is moved to temp
    while (i <= mid && j <= hi){
        if (comparestr(database[criteria-1][i], database[criteria-1][j])){
            temp[0][k] = database[0][i];
            temp[1][k] = database[1][i];
            temp[2][k] = database[2][i];
            temp[3][k] = database[3][i];
            temp[4][k] = database[4][i];
            i++;
        } else {
            temp[0][k] = database[0][j];
            temp[1][k] = database[1][j];
            temp[2][k] = database[2][j];
            temp[3][k] = database[3][j];
            temp[4][k] = database[4][j];
            j++;
        }
        k++;
    }

    //if we run out of elements in one of the vectors, use the other to fill temp
    while (i <= mid){
        temp[0][k] = database[0][i];
        temp[1][k] = database[1][i];
        temp[2][k] = database[2][i];
        temp[3][k] = database[3][i];
        temp[4][k] = database[4][i];
        i++;
        k++;
    }

    while (j <= hi){
        temp[0][k] = database[0][j];
        temp[1][k] = database[1][j];
        temp[2][k] = database[2][j];
        temp[3][k] = database[3][j];
        temp[4][k] = database[4][j];
        j++;
        k++;
    }

    //copy data from temp over into database
    for (int x = lo ; x <= hi ; x++){
        database[0][x] = temp[0][x-lo];
        database[1][x] = temp[1][x-lo];
        database[2][x] = temp[2][x-lo];
        database[3][x] = temp[3][x-lo];
        database[4][x] = temp[4][x-lo];
    }
}

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

std::string Sorting::getYear(int index){
    return database[4][index-1];
}

void Sorting::popularity_print(int pop_lookup){
    int y = 1;
    for(int i=0; i<database[3].size(); i++ ){
        int x= std::stoi(database[3][i]);
        if(x > pop_lookup ){
            std::cout << y << ": " << database[0][i] << ", " <<  database[1][i] << ", " << database[2][i] << ", " << database[3][i] << ", " << database[4][i] << std::endl;
            y++;
        }
    }
}

//stores all of 1 songs data from the database in a vector
std::vector<std::string> Sorting::get(int row){
    std::vector<std::string> temp;
    for(int i = 0; i < 5; i++){
        temp.push_back(database[i][row]);
    }
    return temp;
}

//gets all indexs of songs with a certain category or criteria
std::vector<int> Sorting::getIndexs(std::string criteria, int category){
    std::vector<int> returner;
    for(int i = 0; i < database[category].size(); i++){
        if(database[category-1][i] == criteria){
            returner.push_back(i);
        }
    }
    return returner;
}

//public call for heap sort
void Sorting::heapSort(int criteria){
    std::vector<std::string> temp = (database[criteria-1]);
    heap_sort(temp);
}

//private call for heap sort
void Sorting::heap_sort(std::vector<std::string>& myVec){
    int n = myVec.size();
    
    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(myVec, n, i);
 
    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(myVec[0], myVec[i]);

        swap(database[0][0], database[0][i]);
        swap(database[1][0], database[1][i]);
        swap(database[2][0], database[2][i]);
        swap(database[3][0], database[3][i]);
        swap(database[4][0], database[4][i]);

        heapify(myVec, i, 0);
    }
}

//private helper function for heapsort
void Sorting::heapify(std::vector<std::string>& myVec, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && myVec[left] > myVec[largest])
        largest = left;
 
    if (right < n && myVec[right] > myVec[largest])
        largest = right;
 
    if (largest != i) {
        swap(myVec[i], myVec[largest]);

        swap(database[0][i], database[0][largest]);
        swap(database[1][i], database[1][largest]);
        swap(database[2][i], database[2][largest]);
        swap(database[3][i], database[3][largest]);
        swap(database[4][i], database[4][largest]);

        heapify(myVec, n, largest);
    }
}

void Sorting::heap_sort2(std::vector<std::string>& myVec, std::vector<std::vector<std::string>>& mVec){
    int n = myVec.size();
    
    // Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify2(myVec, n, i, mVec);
    
    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(myVec[0], myVec[i]);

        swap(mVec[0][0], mVec[i][0]);
        swap(mVec[0][1], mVec[i][1]);
        swap(mVec[0][2], mVec[i][2]);
        swap(mVec[0][3], mVec[i][3]);
        swap(mVec[0][4], mVec[i][4]);
        
        heapify2(myVec, i, 0, mVec);
    }
}

void Sorting::heapify2(std::vector<std::string>& myVec, int n, int i, std::vector<std::vector<std::string>>& mVec){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && myVec[left] > myVec[largest])
        largest = left;
 
    if (right < n && myVec[right] > myVec[largest])
        largest = right;
 
    if (largest != i) {
        swap(myVec[i], myVec[largest]);

        swap(mVec[i][0], mVec[largest][0]);
        swap(mVec[i][1], mVec[largest][1]);
        swap(mVec[i][2], mVec[largest][2]);
        swap(mVec[i][3], mVec[largest][3]);
        swap(mVec[i][4], mVec[largest][4]);

        heapify2(myVec, n, largest, mVec);
    }
}

std::vector<std::vector<std::string>> Sorting::getRecommend
    (std::vector<int> genreVec, std::vector<std::vector<std::string>> song_choice_vec){
    int average = std::stoi(song_choice_vec[1][0]) + std::stoi(song_choice_vec[1][1]) 
        + std::stoi(song_choice_vec[1][2]) + std::stoi(song_choice_vec[1][3]) + std::stoi(song_choice_vec[1][4]);
    average /= 5;
    std::vector<int> indexsofgoodyears;
    for(int i = 0; i < genreVec.size(); i++){
        if(std::stoi(database[4][genreVec[i]]) >= average - 5 and std::stoi(database[4][genreVec[i]]) <= average + 5 ){
            indexsofgoodyears.push_back(genreVec[i]);
        }
    }
    std::vector<std::vector<std::string>> songsinrange;
    for(int i = 0; i < indexsofgoodyears.size(); i++){
        std::vector<std::string> temp = get(indexsofgoodyears[i]);
        songsinrange.push_back(temp);
        
    }

    std::vector<std::string> temp;  
    for(int i = 0; i < songsinrange.size(); i++){
        temp.push_back(songsinrange[i][3]);
    }
    
    heap_sort2(temp, songsinrange);
    return songsinrange;
}