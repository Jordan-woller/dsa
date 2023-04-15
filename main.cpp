#include <iostream>
#include <vector>
#include <chrono>
#include "dsa.h"

int main(){
    int initial_choice;
    std::string song_choice;
    std::string genre_choice;
    std::string artist_choice;
    int release_year;
    int popularity;

    auto start = std::chrono::high_resolution_clock::now();
    //function call here
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);




    while(initial_choice != 5){ //5 is the quit option
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Insert a song of your choice into the database." << std::endl;
        std::cout << "2. Get a personalized series of song recommendations based on music you like." << std::endl;
        std::cout << "3. Re-shuffle the playlist by criteria of your choosing." << std::endl;
        std::cout << "4. Printout songs of a certain critera" << std::endl;
        std::cin >> initial_choice;
        while(initial_choice != 1 and initial_choice != 2 and initial_choice != 3 and initial_choice != 4){
            std::cout << "Invalid entry, please enter one of the listed options." << std::endl;
        }
    }

    //Handling for the different choices
    if(initial_choice == 1){
        std::cout << "Enter the name of the song you want to add to the playlist:" << std::endl;
        std::cin >> song_choice;
        //TODO add error checking for song choice
        std::cout << "Enter the genre for this song:" << std::endl;
        std::cin >> genre_choice;
        //TODO add error checking for ggenre choice
        std::cout << "Enter the artist of this song:" << std::endl;
        std::cin >> artist_choice;
        //TODO add error checking for artist choice
        std::cout << "Enter the release year of this song:" << std::endl;
        std::cin >> release_year;
        //TODO add error checking for release year choice
        std::cout << "Enter the popularity of this song (on a scale from 0-100)" << std::endl;
        std::cin >> popularity;
        //TODO add error checking for popularity choice
        //displays the song the user chose
        std::cout << "You chose the following song: " << song_choice << ", " << genre_choice << ", " << artist_choice  << ", " << release_year  << ", " << popularity << std::endl;
        std::cout << std::endl << "Here is the new playlist with your song added: " << std::endl;
        //TODO add function call to insertion method that sorts the added song into playlist database
    }
    if(initial_choice == 2){

    }
    if(initial_choice == 3){

    }
    if(initial_choice == 4){

    }




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






    std::cout << "Time taken by function: "
        << duration.count() << " microseconds" << std::endl;


    return 0;

}

