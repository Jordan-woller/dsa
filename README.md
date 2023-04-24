# Sorting Algorithms - Playlist Recommender

**Authors: Jordan Woller, Jake Dansereau, Cassidy Cooper, Addie Murphy**

## Compilation Instructions
There are two options to run the program: 

**Option 1** 

Access the root directory section of Github.  You can access the root directory by going to the Github link: https://github.com/Jordan-woller/dsa. Once on the main repository page, select the 'Code' button at the top right, and copy the link to Github. Alternatively, use this link: https://github.com/Jordan-woller/dsa.git. Open up Git with Clion, navigate to 'Version Control' at the bottom left hand side. In the console section, select 'Create Git Repository' and upload the link. You can also access the terminal by clicking the 'terminal' tab at the bottom of Clion. From there, you can type 'Git clone' followed by the link to the repo.  At this point, you have access to all of the files to run the program.  Note that when you compile the program, make sure you are in the root directory of the repository. Additionally, the user should add the text file/s that they want to use to the command line arguments. The text files provided in the repository include country.txt, pop.txt, indie.txt, rap.txt, rock.txt, and bigdata.txt. The user can also choose create their own text files, as the program will take in any number of text files.

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
