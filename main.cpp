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

    return 0;
}

