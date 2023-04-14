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
        //a. insert a song of your choice into the database (insertion)
        //b. Recommend songs from playlist based on another playlist (merge)
        //c. Re-shuffle playlist by a given criteria (quicksort)
        //d. Printout songs of a certain criteria


     //Option B: Recommend songs from playlist based on another playlist
            //what do you want to do?
            //a. Make a playlist from scratch


                    //asks the user how many criteria they want to be used to recommend them songs.
                    //If the amount of criteria is greater than 1, then use library sort to best recommend songs from
                    //database that fit the multiple criteria

                    //if the criteria is 1, it asks the user what criteria they want the songs recommended by
                    // (returns top recommendation based on the criteria using merge sort)
                            //a. year
                            //b. song title
                            //c. popularity
                            //etc...
            //b. Choose from a preselected playlist
                    //asks the user what criteria they want the songs recommended by (returns top recommendation
                    //based on the criteria)
                            //a. year
                            //b. song title
                            //c. popularity
                            //etc...

        //C. Option C: Re-shuffle playlist by a given criteria (quicksort)
            //How do you want to shuffle the playlist? (playlist is currently shuffled by song title)
                //a. Shuffle based on popularity
                //b. Shuffle based on song year
                //c. Shuffle based on genre

        //D. Option D: What would you like to lookup?
            //a. print songs of a certain genre
                //asks for what genre
            //b print out if a specific song the user enters exists
            //c. prints songs that are above a certain popularity



    return 0;

}

