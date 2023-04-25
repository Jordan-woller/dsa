# Sorting Algorithms - Playlist Recommender

**Authors: Jordan Woller, Jake Dansereau, Cassidy Cooper, Addie Murphy**

## Compilation Instructions
There are two options to run the program: 

**Option 1** 

Access the root directory section of Github.  You can access the root directory by going to the Github link: https://github.com/Jordan-woller/dsa. Once on the main repository page, select the 'Code' button at the top right, and copy the link to Github. Alternatively, use this link: https://github.com/Jordan-woller/dsa.git. Open up Git with Clion, navigate to 'terminal' at the bottom navigation of CLion. From there, you can type 'Git clone' followed by the link to the repo.  At this point, you have access to all of the files to run the program.  Note that when you compile the program, make sure you are in the root directory of the repository. Additionally, the user should add the text files that they want to use to the command line arguments. The text files provided in the repository include country.txt, pop.txt, indie.txt, rap.txt, rock.txt, and bigdata.txt. The user can also choose create their own text files, as the program will take in any number of text files. Note that bigdata.txt is only used for benchmarking. 

**Option 2** 

If option 1 does not work, you can also download the zip by accessing the 'Code' button in the repository, and clicking
'Download Zip'.  You can then open up these files on your computer with Clion and run the program with the program
arguments stated above.  

**If trouble running with Clion:** 

If you are not able to compile and run the program with the above options,  download dsa.cpp, dsa.h, main.cpp, 
indie.txt, rock.txt, country.txt, pop.txt, and rap.txt.  Once in CLion, open the terminal and type in the 
following command:

```
g++ -std=c++11 dsa.cpp main.cpp -o <executable name> && ./<executable name> <text file(s) name(s)> 
``` 

**Note about setting up the files:**

When setting up the program on CLion, ensure all .txt files are inside of the cmake-build-debug folder. 
When you pull from the Github pleasure ensure to refactor these .txt files into this folder if not 
done so already. **If these files are not in the cmake-build-debug folder, the program will NOT run**

## Runtime Instructions
Upon compiling and running our code, you will be presented with a menu of options in terms of how you would like to manipulate the data. You must enter a number 1-6, based on which option you would like to choose.

To enter a song of your choosing into the playlist, you must enter the number "1". You will then be prompted to enter the song title, valid genre, artist, popularity (which must be a integer 1-100) and release year. You must then choose which criteria you would like the playlist with the additional song to be shuffled by. To shuffle by song titles choose 1, to shuffle by genre choose 2, for artist choose 3, for popularity choose 4, and for release year choose 5. Once these steps are completed you should see your playlist with your added song, shuffled by your chosen criteria printed in the terminal. 


To get a suggested playlist of songs based on the music you like enter the number "2". You will then be prompted to choose which genre you would like to pick your favorite songs from. For Country type "1", for Pop type "2", for Rap type "3", for 80s Rock type "4", and for Indie Rock type "5". On the terminal you should see all of the songs within that genre each with a corresponding number. To select your favorite songs, type the number corresponding to your desired song. Once you typed 5 valid song numbers into your terminal, you should recieve your personalized suggested playlist. 


To shuffle the playlist by your preferred criteria, enter the number "3". You will then be prompted to choose whcih criteria you would like to see the playlist shuffled by. To shuffle based on song title, type "1", to shuffle based on genre, type "2", to shuffle based on artist, type "3", to shuffle based on popularity, type "4", and to shuffle based on release year, type "5". Once you have provided your preferred shuffle criteria, you should see the shuffled playlist printed in the terminal. 


To printout songs of a certain criteria, type the number "4". You will then be prompted to choose what criteria you would like to see printed out. To print songs of a certain genre, type "1", and to print songs that are above a certain popularity, type "2". You should then see the appropriate songs print out in your terminal. 


To time each sorting function, type the number "5". You will then be prompted to choose which sorting alogorithm you would like to see the timing of. To see the timing Insertion Sort, type "1", to see Merge Sort, type "2", to see Quick Sort timing, type "3", and to see Heap sort timing, type "4". Once you have chosen your desired sort, you should see how long it took the alogorithm to run in microseconds in your terminal. 

Finally, to quit the program, type the number "6".

