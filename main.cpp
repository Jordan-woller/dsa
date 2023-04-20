#include <iostream>
#include <vector>
#include <chrono>
#include "dsa.h"
#include <cctype>

int main(int argc, char*argv[]){
    int initial_choice = 0;
    std::string song_choice, genre_choice, artist_choice, use_criteria;
    int release_year, popularity, playlist_select, criteria, single_criteria;
    int shuffle_criteria, lookup, genre_lookup, song_lookup, pop_lookup, song_select;

    std::vector<std::string>criteria_vec = {"Song", "Genre", "Artist", "Popularity", "Release Year"};
    std::vector<bool>criteria_truth; //parallel vector with criteria_vec with true and false
    std::vector<std::string>song_choice_vec;

    Sorting playlist;

    //passing files into the read_data function to get columns
    playlist.read_data(argv[1]);
    playlist.read_data(argv[2]);
    playlist.read_data(argv[3]);
    playlist.read_data(argv[4]);
    playlist.read_data(argv[5]);

    // auto start = std::chrono::high_resolution_clock::now();
    // //function call here
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    while(initial_choice != 5) { //5 is the quit option
        std::cout << "Hello!\n";
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Insert a song of your choice into the database." << std::endl;
        std::cout << "2. Get a personalized series of song recommendations based on songs you like." << std::endl;
        std::cout << "3. Re-shuffle the playlist by criteria of your choosing." << std::endl;
        std::cout << "4. Printout songs of a certain criteria" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> initial_choice;
        while ( initial_choice != 1 || initial_choice != 2 || initial_choice != 3 || initial_choice != 4 || initial_choice != 5 ) {
            std::cout << "Invalid entry, please enter one of the listed options." << std::endl;
            std::cin >> initial_choice;
        }


        //Handling for the different choices
        if (initial_choice == 1) {
            std::cout << "Enter the name of the song you want to add to the playlist:" << std::endl;
            std::cin >> song_choice;  //no need to error check for song choice because songs can be numbers, characters, or strings
            std::cout << "Enter the genre for this song:" << std::endl;
            std::cin >> genre_choice;
            //error checking for genre_choice loops through each character in the variable to ensure it is not a number
            bool genre_check = true;
            for(int i = 0; i < genre_choice.length()-1; i++) {
                if(std::isdigit(genre_choice[i]) and genre_check) {
                    genre_check = false;
                }
                while(!genre_check){
                    std::cout << "Please enter a valid genre:" << std::endl;
                    std::cin >> genre_check;
                    genre_check = true;
                }
            }
            std::cout << "Enter the artist of this song:" << std::endl;
            std::cin >> artist_choice; //no need to error check for artist because artist can be numbers, characters, or strings
            std::cout << "Enter the release year of this song:" << std::endl;
            std::cin >> release_year;
            //error checking for release year
            while(!std::isdigit(release_year) and release_year <= 2023){
                std::cout << "Invalid year, please enter a valid year:" << std::endl;
                std::cin >> release_year;
            }
            std::cout << "Enter the popularity of this song (on a scale from 0-100)" << std::endl;
            std::cin >> popularity;
            //error checking for popularity
            while(!std::isdigit(popularity) and popularity >= 0 and popularity <= 100){
                std::cout << "Invalid popularity, please enter a popularity value 0-100:" << std::endl;
                std::cin >> popularity;
            }
            //displays the song the user chose
            std::cout << "You chose the following song: " << song_choice << ", " << genre_choice << ", "
                      << artist_choice << ", " << release_year << ", " << popularity << std::endl;
            std::cout << std::endl << "Here is the new playlist with your song added: " << std::endl;
            //TODO add function call to insertion method that sorts the added song into playlist database
            //calls insertion method to sort added song into playlist database


        }
        if (initial_choice == 2) {
            //by choosing a playlist, it will display the songs in that playlist.
            //user has the option to either confirm that playlist selection or go back and choose another playlist
            while (song_choice_vec.size() < 5) { //while the song vector of users choices is not filled with 5 songs
                std::cout << "Choose 5 songs you like from the different genre playlists below." << std::endl;
                std::cout << "Chose an option 1-5 to display one of the playlists." << std::endl;
                std::cout << "1. Country" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. Rap" << std::endl;
                std::cout << "4. 80s Rock" << std::endl;
                std::cout << "5. Indie Rock" << std::endl;
                std::cin >> playlist_select;
                //error checking for playlist option
                while (playlist_select != 1 and playlist_select != 2 and playlist_select != 3 and
                       playlist_select != 4 and
                       playlist_select != 5) {
                    std::cout << "Invalid, please enter an option 1-5";
                    std::cin >> playlist_select;
                }
                //for playlist options 1-5, it will display the playlist.
                //user can either confirm their selection or go back and choose another playlist
                if (playlist_select == 1) {
                    std::cout << "Here is the Country playlist:" << std::endl;
                    //TODO cout the playlist
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (song_select < 1 || song_select > 25) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }

                }
                if (playlist_select == 2) {
                    std::cout << "Here is the Pop playlist:" << std::endl;
                    //TODO cout the playlist
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (song_select < 1 || song_select > 25) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == 3) {
                    std::cout << "Here is the Rap playlist:" << std::endl;
                    //TODO cout the playlist
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (song_select < 1 || song_select > 25) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == 4) {
                    std::cout << "Here is the 80s Rock playlist:" << std::endl;
                    //TODO cout the playlist
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (song_select < 1 || song_select > 25) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == 5) {
                    std::cout << "Here is the Indie Rock playlist:" << std::endl;
                    //TODO cout the playlist
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (song_select < 1 || song_select > 25) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
            }
            //once user playlist has been filled with 5 songs
            std::cout << std::endl
                      << "How many criteria would you like to sort your personalized song recommendations by?"
                      << std::endl;
            std::cout << "Enter a number 1-5 (the criteria are song, genre, artist, popularity, and release year"
                      << std::endl;
            std::cin >> criteria;
            //error check to make sure criteria is valid
            while (criteria != 1 and criteria != 2 and criteria != 3 and criteria != 4 and criteria != 5) {
                std::cout << "Invalid criteria, try again." << std::endl;
                std::cin >> criteria;
            }

            //if the criteria is 1, it asks the user what criteria that is and uses merge sort to return top songs based on that criteria
            if (criteria == 1) {
                std::cout << "Choose from one of the criteria to get your song recommendations based off: "
                          << std::endl;
                std::cout << "1. Song" << std::endl;
                std::cout << "2. Genre" << std::endl;
                std::cout << "3. Artist" << std::endl;
                std::cout << "4. Popularity" << std::endl;
                std::cout << "5. Release Year" << std::endl;
                std::cout << "Enter your choice as a number 1-5:" << std::endl;
                std::cin >> single_criteria;
                //error checking for single criteria choice
                while (single_criteria != 1 and single_criteria != 2 and single_criteria != 3 and
                       single_criteria != 4 and single_criteria != 5) {
                    std::cout << "Invalid option, try again." << std::endl;
                    std::cin >> single_criteria;
                }
                //TODO pass single_criteria and song_choice_vec into method vector for merge sort
            }
                //if the criteria is greater than 1, library sort is used to recommend songs based on the multiple criteria.
            else if (criteria == 2 or criteria == 3 or criteria == 4 or criteria == 5) {
                std::cout << "Enter y for yes or n for no if you would like to use the prompted criteria" << std::endl;
                //goes through all given criteria and asks user if they want to sort by each (vector with given criteria defined at top)
                for (int i = 0; i < criteria_vec.size(); i++) {
                    std::cout << "Would you like " << criteria_vec[i] << "to be used as a criteria?" << std::endl
                              << "Enter y or n" << std::endl;
                    std::cin >> use_criteria;
                    std::cout << std::endl;
                    //if they want to use criteria, corresponding truth table sets to true at that value
                    if (use_criteria == "y") {
                        criteria_truth[i] = true;
                    } else {
                        criteria_truth[i] = false;
                    }
                }
                //TODO now that criteria is known, use library sort method to be created to sort
            }

        }
        //TODO add another choice to shuffle just a genre
        if (initial_choice == 3) { //reshuffle playlist by criteria of users choosing
            std::cout << "How do you want to shuffle the playlist?" << std::endl;
            std::cout << "(enter an option 1-5)" << std::endl;
            std::cout << "1. Shuffle based on song title" << std::endl;
            std::cout << "2. Shuffle based on genre" << std::endl;
            std::cout << "3. Shuffle based on artist" << std::endl;
            std::cout << "4. Shuffle based on popularity" << std::endl;
            std::cout << "5. Shuffle based on release year" << std::endl;

            std::cin >> shuffle_criteria;
            //error checking for shuffling criteria
            while (shuffle_criteria != 1 and shuffle_criteria != 2 and shuffle_criteria != 3 and
                   shuffle_criteria != 4 and shuffle_criteria != 5) {
                std::cout << "Invalid option, try again." << std::endl;
                std::cin >> shuffle_criteria;
            }
            //once criteria is chosen, goes into quicksort method that shuffles based on the criteria
//            r_quicksort(int lo, int  hi, int shuffle_criteria);
        }


        if (initial_choice == 4) {
            std::cout << "What would you like to see?" << std::endl;
            std::cout << "1. Print songs of a certain genre " << std::endl;
            std::cout << "2. See if a specific song exists in the playlist " << std::endl;
            std::cout << "3. Print songs that are above a certain popularity " << std::endl;
            std::cin >> lookup;
            //error checking for lookup options
            while (lookup != 1 and lookup != 2 and lookup != 3) {
                std::cout << "Invalid option, try again." << std::endl;
                std::cin >> lookup;
            }
            //choices
            if (lookup == 1) {
                std::cout << "Which genre would you like to see songs of?" << std::endl;
                std::cout << "1. Country" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. Rap" << std::endl;
                std::cout << "4. 80s Rock" << std::endl;
                std::cout << "5. Indie Rock" << std::endl;
                std::cin >> genre_lookup;
                //error checking for genre lookup
                while (genre_lookup != 1 and genre_lookup != 2 and genre_lookup != 3 and genre_lookup != 4 and
                       genre_lookup != 5) {
                    std::cout << "Invalid, please enter an option 1-5";
                    std::cin >> genre_lookup;
                }
                //TODO add method and method call to only print songs of selected genre
                //IDK WHY THIS IS ERRORING!!!
                 playlist.genre_print(genre_lookup);
            }
            if (lookup == 2) {
                std::cout << "Enter a song:" << std::endl;
                std::cin >> song_lookup;
                //TODO add some sort of method that converts song to proper capitalization ex if all is lower case
                //TODO add method to see if song exists
            }
            if (lookup == 3) {
                std::cout << "Enter a popularity to see songs only above that level of popularity:" << std::endl;
                std::cin >> pop_lookup;
                //TODO add error checking for popularity to ensure it is an integer between 1-100
                //TODO add method to display songs above that level of popularity
            }
        }

        if (initial_choice == 5) {
            break;
        }

        //resetting necessary variables
        initial_choice = 0;
    }

    exit(0);

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

