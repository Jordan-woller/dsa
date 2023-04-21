#include <vector>
#include <string>
#include <iostream>

class Sorting{
private:
    std::vector<std::string> *database;

    Sorting(){
        this->database = new std::vector<std::string>;
        *database = {"chair", "table", "lamp", "computer", "book", "pen", "pencil", "desk", "door", "window", "carpet", "painting", "clock", "mirror", "phone", "television", "remote", "keyboard", "mouse", "speaker", "monitor", "printer", "scanner", "router", "modem", "tablet", "smartphone", "camera", "microwave", "oven", "dishwasher", "refrigerator", "freezer", "blender", "toaster", "coffee maker", "juicer", "vacuum cleaner", "washing machine", "dryer", "iron", "hair dryer", "shampoo", "soap", "toothbrush", "toothpaste", "towel", "pillow", "blanket", "sheet", "mattress", "nightstand", "dresser", "wardrobe", "hanger", "coat rack", "umbrella", "backpack", "suitcase", "wallet", "keychain", "sunglasses", "watch", "bracelet", "earrings", "necklace", "ring", "perfume", "deodorant", "lipstick", "foundation", "mascara", "nail polish", "razor", "shaving cream", "tissue", "paper towel", "trash can", "broom", "dustpan", "mop", "bucket", "garden hose", "lawn mower", "grill", "barbecue", "hammock", "tent", "sleeping bag", "flashlight", "bicycle", "skateboard", "rollerblades", "basketball", "football", "soccer ball", "baseball", "tennis racket", "golf club", "dartboard"
        };
    }

public:

    void print_database() {

        for (int i = 0 ; i < (*database).size() ; i++){
            std::cout << (*database)[i] << ", ";
        }
        std::cout << std::endl;
    }

    bool comparestr(std::string str1, std::string str2){
        unsigned int length = (str1.length() > str2.length()) ? str1.length() : str2.length();

        for (int i = 0 ; i < length ; i++){
            if (str1[i] <= str2[i]) {
                return true;
            } else if (str1[i] > str2[i]) {
                return false;
            }
        }
        return true;
    }

    void merge_sort(int criteria){
        auto aux = *database;
        r_merge(0, aux.size() - 1, criteria);
    }

//private function to recursively separate vector
    void r_merge(int lo, int hi, int criteria) {
        std::vector<std::string> temp = *database;
        //basecase(single element or empty list)
        if (lo >= hi) {return;}

        //divide
        int mid = lo + (hi - lo) / 2;

        //recursively sort halves
        r_merge(lo, mid, criteria);
        r_merge(mid + 1, hi, criteria);

        //merge
        merge(lo, mid, hi, criteria);

        for (int x = lo ; x <= hi ; x++){
            (*database)[x] = temp[x];
        }

    }

//private function to merge each vector together
    void merge(int lo, int mid, int hi, int criteria) {
        int i = lo, j = mid + 1, k = 0;

        std::vector<std::string> temp (hi - lo + 1);

        while (i <= mid && j <= hi){
            if (comparestr((*database)[i], (*database)[j])){
                temp[k] = (*database)[i];
                i++;
            }
            else{
                temp[k] = (*database)[j];
                j++;
            }
            k++;
        }

        while (i <= mid){
            temp[k] = (*database)[i];
            k++;
            i++;
        }

        while (j <= hi){
            temp[k] = (*database)[j];
            k++;
            j++;
        }

        for (int x = lo ; x <= hi ; x++){
            (*database)[x] = temp[x - lo];
        }

        for (auto x : temp){
            std::cout << x << ", ";
        }
        std::cout << std::endl;

    }
};
