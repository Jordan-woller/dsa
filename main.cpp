#include <iostream>
#include <vector>
#include <chrono>
#include "dsa.h"
#include <cctype>

int main(int argc, char*argv[]){
    std::string initial_choice;
    std::string song_choice, genre_choice, artist_choice, use_criteria, song_lookup, release_year, popularity;
    int criteria, single_criteria, insertion_option;
    int song_select;
    std::string shuffle_criteria;
    std::string pop_lookup;
    std::string genre_lookup;
    std::string playlist_select;
    std::string lookup;

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

    auto start = std::chrono::high_resolution_clock::now();
    playlist.merge_sort(4);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by merge sort function: " << duration.count() << " microseconds" << std::endl;

    bool keepGoing = true;

    while(keepGoing) { //5 is the quit option
        std::cout << "Hello!\n";
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Insert a song of your choice into the database." << std::endl;
        std::cout << "2. Get a personalized series of song recommendations based on songs you like." << std::endl;
        std::cout << "3. Re-shuffle the playlist by criteria of your choosing." << std::endl;
        std::cout << "4. Printout songs of a certain criteria" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> initial_choice;
        if ( initial_choice != "1" and initial_choice != "2" and initial_choice != "3" and initial_choice != "4" and initial_choice != "5" ) {
            std::cout << "Invalid entry, please enter one of the listed options." << std::endl;
            std::cin >> initial_choice;
        }
        //Handling for the different choices
        if (initial_choice == "1") {
            std::cout << "Enter the name of the song you want to add to the playlist:" << std::endl;
            std::getline(std::cin, song_choice);  //no need to error check for song choice because songs can be numbers, characters, or strings
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
            //this line isnt working
            std::getline(std::cin, artist_choice);; //no need to error check for artist because artist can be numbers, characters, or strings
            std::cout << "Enter the release year of this song:" << std::endl;
            std::cin >> release_year;
            //error checking for release year
            while(!std::isdigit(release_year[0]) or std::stoi(release_year) > 2023){
                std::cout << "Invalid year, please enter a valid year:" << std::endl;
                std::cin >> release_year;
            }
            std::cout << "Enter the popularity of this song (on a scale from 0-100)" << std::endl;
            std::cin >> popularity;
            //error checking for popularity
            while(!std::isdigit(popularity[0]) or std::stoi(popularity) < 0 or std::stoi(popularity) > 100){
                std::cout << "Invalid popularity, please enter a popularity value 0-100:" << std::endl;
                std::cin >> popularity;
            }
            //displays the song the user chose
            std::cout << "You chose the following song: " << song_choice << ", " << genre_choice << ", "
                      << artist_choice << ", " << release_year << ", " << popularity << std::endl;
            std::cout << "How would you like the playlist to be sorted by? Choose an option 1-5." << std::endl;
            std::cout << "1. Song Title" << std::endl;
            std::cout << "2. Genre" << std::endl;
            std::cout << "3. Artist" << std::endl;
            std::cout << "4. Popularity" << std::endl;
            std::cout << "5. Release Year" << std::endl;
            std::cin >> insertion_option;
            while (insertion_option != 1 and insertion_option != 2 and insertion_option != 3 and
                   insertion_option != 4 and insertion_option != 5) {
                std::cout << "Invalid entry, try again." << std::endl;
                std::cin >> insertion_option;
            }
            std::cout << std::endl << "Here is the new playlist with your song added: " << std::endl;
            //calls quick sort shuffle to sort the playlist by whatever criteria the user wants
            auto start = std::chrono::high_resolution_clock::now();
            playlist.shuffle(insertion_option);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Time taken by quick sort function: " << duration.count() << " microseconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            playlist.insertion(insertion_option, song_choice, genre_choice, artist_choice, release_year, popularity);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Time taken by insertion sort function: " << duration.count() << " microseconds" << std::endl;
        }

        if (initial_choice == "2") {
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
                while (playlist_select != "1" and playlist_select != "2" and playlist_select != "3" and playlist_select != "4" and playlist_select != "5") {
                    std::cout << "Invalid, please enter an option 1-5";
                    std::cin >> playlist_select;
                }
                //for playlist options 1-5, it will display the playlist.
                //user can either confirm their selection or go back and choose another playlist
                if (playlist_select == "1") {
                    std::string playlistGenre = "Country";
                    std::cout << "Here is the Country playlist:" << std::endl;
                    playlist.genre_print(1,2);
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)" << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (playlist.checkSong(song_select, playlistGenre)) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == "2") {
                    std::string playlistGenre = "Pop";
                    std::cout << "Here is the Pop playlist:" << std::endl;
                    playlist.genre_print(2,2);
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (playlist.checkSong(song_select, playlistGenre)) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == "3") {
                    std::string playlistGenre = "Rap";
                    std::cout << "Here is the Rap playlist:" << std::endl;
                    playlist.genre_print(3,2);
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (playlist.checkSong(song_select, playlistGenre)) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == "4") {
                    std::string playlistGenre = "80s Rock";
                    std::cout << "Here is the 80s Rock playlist:" << std::endl;
                    playlist.genre_print(4,2);
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (playlist.checkSong(song_select, playlistGenre)) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                if (playlist_select == "5") {
                    std::string playlistGenre = "Indie Rock";
                    std::cout << "Here is the Indie Rock playlist:" << std::endl;
                    playlist.genre_print(5,2);
                    std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)"
                              << std::endl;
                    std::cin >> song_select;
                    //error checking for song choice
                    while (playlist.checkSong(song_select, playlistGenre)) {
                        std::cout << "Invalid, please enter a valid song choice:";
                        std::cin >> song_select;
                    }
                }
                song_choice_vec.push_back(playlist.getTitle(song_select));
            }

            //once user playlist has been filled with 5 songs
            std::string ranking;
            std::vector<std::string> topics = {"Genre", "Release Year", "Popularity"};
            std::vector<std::string> order;
            std::cout << std::endl << "Please rank the following criteria" << std::endl;
            std::cout << std::endl << "For Genre enter 1" << std::endl;
            std::cout << std::endl << "For Release Year enter 2" << std::endl;
            std::cout << std::endl << "For Popularity enter 3" << std::endl;
            std::cout << std::endl << "For ex: Release Year, Popularity, Genre: enter 231" << std::endl;
            std::cin >> ranking;

                //error check to make sure criteria is valid
                while (ranking != "231" and ranking != "123" and ranking != "132" and ranking != "321" and ranking != "312" and ranking != "213") {
                    std::cout << "Invalid criteria, try again." << std::endl;
                    std::cin >> criteria;
                }

            std::cout << "\n\n";
        }
        //TODO add another choice to shuffle just a genre
        if (initial_choice == "3") { //reshuffle playlist by criteria of users choosing
            std::cout << "How do you want to shuffle the playlist?" << std::endl;
            std::cout << "(enter an option 1-5)" << std::endl;
            std::cout << "1. Shuffle based on song title" << std::endl;
            std::cout << "2. Shuffle based on genre" << std::endl;
            std::cout << "3. Shuffle based on artist" << std::endl;
            std::cout << "4. Shuffle based on popularity" << std::endl;
            std::cout << "5. Shuffle based on release year" << std::endl;

            std::cin >> shuffle_criteria;
            //error checking for shuffling criteria
            while (shuffle_criteria != "1" and shuffle_criteria != "2" and shuffle_criteria != "3" and
                   shuffle_criteria !="4" and shuffle_criteria != "5") {
                std::cout << "Invalid option, try again." << std::endl;
                std::cin >> shuffle_criteria;
            }
           int x = std::stoi(shuffle_criteria);
            //once criteria is chosen, goes into quicksort method that shuffles based on the criteria
            start = std::chrono::high_resolution_clock::now();
            playlist.shuffle(x);
            stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Time taken by quick sort function: " << duration.count() << " microseconds" << std::endl;
        }

        if (initial_choice == "4") {
            std::cout << "What would you like to see?" << std::endl;
            std::cout << "1. Print songs of a certain genre " << std::endl;
            std::cout << "2. Print songs that are above a certain popularity " << std::endl;
            std::cin >> lookup;
            //error checking for lookup options
            while (lookup != "1" and lookup != "2") {
                std::cout << "Invalid option, try again." << std::endl;
                std::cin >> lookup;
            }
            //choices
            if (lookup == "1") {
                std::cout << "Which genre would you like to see songs of?" << std::endl;
                std::cout << "1. Country" << std::endl;
                std::cout << "2. Pop" << std::endl;
                std::cout << "3. Rap" << std::endl;
                std::cout << "4. 80s Rock" << std::endl;
                std::cout << "5. Indie Rock" << std::endl;
                std::cin >> genre_lookup;
                //error checking for genre lookup
                while (genre_lookup != "1" and genre_lookup != "2" and genre_lookup != "3" and genre_lookup != "4" and
                       genre_lookup != "5") {
                    std::cout << "Invalid, please enter an option 1-5";
                    std::cin >> genre_lookup;
                }

                int x =std::stoi(genre_lookup);
                playlist.genre_print(x, 1);
            }
            if (lookup == "2") {
                std::cout << "Enter a popularity to see songs only above that level of popularity:" << std::endl;
                std::cin >> pop_lookup;
                //TODO add error checking for popularity to ensure it is an integer between 1-100
                //TODO add method to display songs above that level of popularity
                while (true) {
                    bool pass_check = true;
                    std::cin >> pop_lookup;
                    for (auto &c : pop_lookup) {
                        if (!std::isdigit(c)) {
                            std::cout << "Invalid, please enter an option 1-100" << '\n';
                            pass_check = false;
                        }
                    }
                    if (pass_check) {
                        if (std::stoi(pop_lookup) < 1 || std::stoi(pop_lookup) > 100) {
                            std::cout << "Invalid, please enter an option 1-100" << '\n';
                        } else {
                            break;
                        }
                    }
                }

                playlist.popularity_print(std::stoi(pop_lookup));
            }
        }

        if (initial_choice == "5") {
            keepGoing=false;
        }

        //resetting necessary variables
        initial_choice = "0";
    }
}

