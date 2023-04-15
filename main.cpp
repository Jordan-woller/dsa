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
    int playlist_select;
    int dif_playlist;
    int criteria;
    int single_criteria;
    std::string use_criteria;



    std::vector<std::string>criteria_vec = {"Song", "Genre", "Artist", "Popularity", "Release Year"};
    std::vector<bool>criteria_truth; //parallel vector with criteria_vec with true and false



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
        //by choosing a playlist, it will display the songs in that playlist.
        //user has the option to either confirm that playlist selection or go back and choose another playlist
        while(dif_playlist != 2) { //while user does not confirm their selected playlist
            std::cout
                    << "Choose a playlist you like, and the song recommender will choose songs best suited towards your music taste."
                    << std::endl;
            std::cout << "1. Country" << std::endl;
            std::cout << "2. Pop" << std::endl;
            std::cout << "3. Rap" << std::endl;
            std::cout << "4. 80s Rock" << std::endl;
            std::cout << "5. Indie Rock" << std::endl;
            std::cin >> playlist_select;
            //error checking for playlist option
            while (playlist_select != 1 and playlist_select != 2 and playlist_select != 3 and playlist_select != 4 and
                   playlist_select != 5) {
                std::cout << "Invalid, please enter an option 1-5";
                std::cin >> playlist_select;
            }
            //for playlist options 1-5, it will display the playlist.
            //user can either confirm their selection or go back and choose another playlist
            if (playlist_select == 1) {
                std::cout << "Here is the Country playlist:" << std::endl;
                //TODO cout the playlist
                std::cout << "Would you like to confirm this playlist selection, or choose another playlist?"<< std::endl;
                std::cout << "1. Go back to playlist options" << std::endl;
                std::cout << "2. Confirm playlist selection" << std::endl;
                std::cin >> dif_playlist;
            }
            if (playlist_select == 2) {
                std::cout << "Here is the Pop playlist:" << std::endl;
                //TODO cout the playlist
                std::cout << "Would you like to confirm this playlist selection, or choose another playlist?"<< std::endl;
                std::cout << "1. Go back to playlist options" << std::endl;
                std::cout << "2. Confirm playlist selection" << std::endl;
                std::cin >> dif_playlist;
            }
            if (playlist_select == 3) {
                std::cout << "Here is the Rap playlist:" << std::endl;
                //TODO cout the playlist
                std::cout << "Would you like to confirm this playlist selection, or choose another playlist?"<< std::endl;
                std::cout << "1. Go back to playlist options" << std::endl;
                std::cout << "2. Confirm playlist selection" << std::endl;
                std::cin >> dif_playlist;
            }
            if (playlist_select == 4) {
                std::cout << "Here is the 80s Rock playlist:" << std::endl;
                //TODO cout the playlist
                std::cout << "Would you like to confirm this playlist selection, or choose another playlist?"<< std::endl;
                std::cout << "1. Go back to playlist options" << std::endl;
                std::cout << "2. Confirm playlist selection" << std::endl;
                std::cin >> dif_playlist;
            }
            if (playlist_select == 5) {
                std::cout << "Here is the Indie Rock playlist:" << std::endl;
                //TODO cout the playlist
                std::cout << "Would you like to confirm this playlist selection, or choose another playlist?"<< std::endl;
                std::cout << "1. Go back to playlist options" << std::endl;
                std::cout << "2. Confirm playlist selection" << std::endl;
                std::cin >> dif_playlist;
            }
        }
        //once playlist has been confirmed:
        std::cout << std::endl << "How many criteria would you like to sort your personalized song recommendations by?" << std::endl;
        std::cout << "Enter a number 1-5 (the criteria are song, genre, artist, popularity, and release year" << std::endl;
        std::cin >> criteria;
        //error check to make sure criteria is valid
        while(criteria != 1 and criteria != 2 and criteria != 3 and criteria != 4 and criteria != 5){
            std::cout << "Invalid criteria, try again." << std::endl;
            std::cin >> criteria;
        }

        //if the criteria is 1, it asks the user what criteria that is and uses merge sort to return top songs based on that criteria
        if(criteria == 1){
            std::cout << "Choose from one of the criteria to get your song recommendations based off: " << std::endl;
            std::cout << "1. Song" << std::endl;
            std::cout << "2. Genre" << std::endl;
            std::cout << "3. Artist" << std::endl;
            std::cout << "4. Popularity" << std::endl;
            std::cout << "5. Release Year" << std::endl;
            std::cout << "Enter your choice as a number 1-5:" << std::endl;
            std::cin >> single_criteria;
            //error checking for single criteria choice
            while (single_criteria != 1 and single_criteria != 2 and single_criteria != 3 and single_criteria != 4 and single_criteria != 5){
                std::cout << "Invalid option, try again." << std::endl;
                std::cin >> single_criteria;
            }
            //TODO pass single_criteria into method vector for merge sort
        }
        //if the criteria is greater than 1, library sort is used to recommend songs based on the multiple criteria.
        else if(criteria == 2 or criteria == 3 or criteria == 4 or criteria == 5) {
            std::cout << "Enter y for yes or n for no if you would like to use the prompted criteria" << std::endl;
            //goes through all given criteria and asks user if they want to sort by each (vector with given criteria defined at top)
            for(int i = 0; i < criteria_vec.size(); i++){
                std::cout << "Would you like " << criteria_vec[i] << "to be used as a criteria?" << std::endl << "Enter y or n" << std::endl;
                std::cin >> use_criteria;
                std::cout << std::endl;
                //if they want to use criteria, corresponding truth table sets to true at that value
                if(use_criteria == "y"){
                    criteria_truth[i] = 1;
                }else{
                    criteria_truth[i] = 0;
                }
            }
            //TODO now that criteria is known, use library sort method to be created to sort
        }

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

