#include <iostream>
#include <vector>
#include <chrono>

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    //function call here
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 
    std::cout << "Time taken by function: "
        << duration.count() << " microseconds" << std::endl;


    //main options menu
    //Ask the user what they want to do
        //a. insert a song of your choice into the list
        //b. sort two playlists together
            //what do you want to do?
            //a. Make a playlist from scratch
            //b. Choose from a preselected playlist
        //c.



    return 0;

}

