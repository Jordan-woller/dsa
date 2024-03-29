#include <iostream>
#include <vector>
#include <chrono>
#include "dsa.h"
#include <cctype>
#include <algorithm>


int main(int argc, char*argv[]){
    std::string initial_choice;
    std::string song_choice, genre_choice, artist_choice, use_criteria, song_lookup, release_year, popularity;
    int criteria, single_criteria, insertion_option;
    std::string song_select, shuffle_criteria, pop_lookup, genre_lookup, playlist_select, lookup;

    std::vector<std::string>criteria_vec = {"Song", "Genre", "Artist", "Popularity", "Release Year"};
    std::vector<bool>criteria_truth; //parallel vector with criteria_vec with true and false
    std::vector<std::vector<std::string>> song_choice_vec(2, std::vector<std::string> (0,"")); // title then year

    Sorting playlist;

    for(int i = 1; i < argc; i++){
        playlist.read_data(argv[i]);
    }

    bool keepGoing = true;

    std::cout << "Hello!\n";
    while(keepGoing) { //5 is the quit option
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Insert a song of your choice into the database." << std::endl;
        std::cout << "2. Get a personalized series of song recommendations based on songs you like." << std::endl;
        std::cout << "3. Re-shuffle the playlist by criteria of your choosing." << std::endl;
        std::cout << "4. Printout songs of a certain criteria" << std::endl;
        std::cout << "5. Time each sorting function" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cin >> initial_choice;
        //error checking for choices
        if ( initial_choice != "1" and initial_choice != "2" and initial_choice != "3" and initial_choice != "4" and initial_choice != "5" and initial_choice != "6") {
            std::cout << "Invalid entry, please enter one of the listed options:" << std::endl;
            std::cin >> initial_choice;
        }
        //Handling for the different choices
        if (initial_choice == "1") {
            std::cout << "Enter the name of the song you want to add to the playlist:" << std::endl;
            song_choice = playlist.multi_line();
            std::cout << "Enter the genre for this song:" << std::endl;
            genre_choice = playlist.multi_line();
            //error checking for genre_choice ensures first character is a digit
            bool genre_check = true;
            for(int i = 0; i < genre_choice.length()-1; i++) {
                if(std::isdigit(genre_choice[i]) and genre_check) {
                    genre_check = false;
                }
                while(!genre_check){ //prompts user to enter valid genre
                    std::cout << "Please enter a valid genre:" << std::endl;
                    std::cin >> genre_check;
                    genre_check = true;
                }
            }
            std::cout << "Enter the artist of this song:" << std::endl;
           //no need to error check for artist because artist can be numbers, characters, or strings
            artist_choice = playlist.multi_line();
            std::cout << "Enter the popularity of this song (on a scale from 0-100)" << std::endl;
            std::cin >> popularity;
            //error checking for popularity to ensure it is a digit
            while(!std::isdigit(popularity[0]) or std::stoi(popularity) < 0 or std::stoi(popularity) > 100){
                std::cout << "Invalid popularity, please enter a popularity value 0-100:" << std::endl;
                std::cin >> popularity;
            }
            std::cout << "Enter the release year of this song:" << std::endl;
            std::cin >> release_year;
            //error checking for release year to ensure it is a digit
            while(!std::isdigit(release_year[0]) or std::stoi(release_year) > 2023){
                std::cout << "Invalid year, please enter a valid year:" << std::endl;
                std::cin >> release_year;
            }
            //displays the song the user chose
            std::cout << "You chose the following song: " << song_choice << ", " << genre_choice << ", "
                      << artist_choice << ", " << popularity << ", " << release_year << std::endl;
            //different criteria to sort by
            std::cout << "How would you like the playlist to be sorted by? Choose an option 1-5." << std::endl;
            std::cout << "1. Song Title" << std::endl;
            std::cout << "2. Genre" << std::endl;
            std::cout << "3. Artist" << std::endl;
            std::cout << "4. Popularity" << std::endl;
            std::cout << "5. Release Year" << std::endl;
            std::cin >> insertion_option;
            //error checking for insertion_option
            while (insertion_option != 1 and insertion_option != 2 and insertion_option != 3 and
                   insertion_option != 4 and insertion_option != 5) {
                std::cout << "Invalid entry, try again." << std::endl;
                std::cin >> insertion_option;
            }
            std::cout << std::endl << "Here is the new playlist with your song added: " << std::endl;
            //calls merge_sort which sorts by given criteria
            playlist.merge_sort(insertion_option);
            //calls insertion sort and takes in all options provided by the user
            playlist.insertion(insertion_option-1, song_choice, genre_choice, artist_choice, release_year, popularity);
            //prints the database with new song and criteria inserted
            playlist.print_database();
        }

        if (initial_choice == "2") {
            //by choosing a playlist, it will display the songs in that playlist.
            //user has the option to either confirm that playlist selection or go back and choose another playlist
            std::cout << "Choose 5 songs you like from one of the different genre playlists below." << std::endl;
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
            std::vector<int> used;
            std::string playlistGenre;
            //checks user genre input
            if (playlist_select == "1") {
                std::cout << "Here is the Country playlist:" << std::endl;
                //prints genre and indexs for user
                playlist.genre_print(1,2);
                playlistGenre = "Country";
            }
            if (playlist_select == "2") {
                std::cout << "Here is the Pop playlist:" << std::endl;
                //prints genre and indexs for user
                playlist.genre_print(2,2);
                playlistGenre = "Pop";
            }
            if (playlist_select == "3") {
                std::cout << "Here is the Rap playlist:" << std::endl;
                //prints genre and indexs for user
                playlist.genre_print(3,2);
                playlistGenre = "Rap";
            }
            if (playlist_select == "4") {
                std::cout << "Here is the 80s Rock playlist:" << std::endl;
                //prints genre and indexs for user
                playlist.genre_print(4,2);
                playlistGenre = "80s Rock";
            }
            if (playlist_select == "5") {
                std::cout << "Here is the Indie Rock playlist:" << std::endl;
                //prints genre and indexs for user
                playlist.genre_print(5,2);
                playlistGenre = "Indie Rock";
            }

            int amt = 0;
            while (amt < 5) {
                std::cout << "Choose a song from the playlist: (enter a number that corresponds to the song)" << std::endl;
                std::cin >> song_select;
                //error checking for song choice
                int temp = std::stoi(song_select);
                while (playlist.checkSong(std::stoi(song_select), playlistGenre) or std::count(used.begin(),used.end(), temp)){                        std::cout << "Invalid, please enter a valid song choice:";
                    std::cin >> song_select;
                }
                used.push_back(std::stoi(song_select));
                song_choice_vec[0].push_back(playlist.getTitle(std::stoi(song_select)));
                song_choice_vec[1].push_back(playlist.getYear(std::stoi(song_select)));
                amt++;
            }

            //calls heapsort on the category that the user chose
            playlist.heapSort(std::stoi(playlist_select));
            //gets the indexs of all songs in the specified genre
            std::vector<int> genreVec = playlist.getIndexs(playlistGenre, 2);
            //calls the member function in order to recommend the user 5 songs
            std::vector<std::vector<std::string>> recsonglist = playlist.getRecommend(genreVec, song_choice_vec);
            
            int checksize;
            if(recsonglist.size() < 5){
                checksize = 0;
            } else {
                checksize = recsonglist.size() - 5;
            } 
            //prints out top 5 songs 
            std::cout << "\nHere is your list of personalized song recommendations:\n";
            for(int j = checksize; j < recsonglist.size(); j++){
                for(int i = 0; i < recsonglist[j].size(); i++){
                    std::cout << recsonglist[j][i] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
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
            playlist.shuffle(x);
            playlist.print_database();
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
            std::string choice;
            std::cout << "Which sorting function would you like to time: (Enter the corresponding number)" << std::endl;
            std::cout << "1. Insertion Sort" << std::endl;
            std::cout << "2. Merge Sort" << std::endl;
            std::cout << "3. Quick Sort" << std::endl;
            std::cout << "4. Heap Sort" << std::endl;
            std::cin >> choice;
            while(choice != "1" and choice != "2" and choice != "3" and choice != "4"){
                std::cout << "Invalid, please enter an option 1-4\n";
                std::cin >> choice;
            }

            if(choice == "1"){
                auto start = std::chrono::high_resolution_clock::now();
                playlist.insertion(1, "test", "test", "test", "0", "2023");
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
                }

            if(choice == "2"){
                auto start = std::chrono::high_resolution_clock::now();
                playlist.merge_sort(1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
            }

            if(choice == "3"){
                auto start = std::chrono::high_resolution_clock::now();
                playlist.shuffle(1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
            }

            if(choice == "4"){
                auto start = std::chrono::high_resolution_clock::now();
                playlist.heapSort(1);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
            }
            std::cout << "\n\n";
        }

        if (initial_choice == "6") {
            keepGoing = false;
            continue;
        }

        initial_choice = "0";
    }
}

