#include <iostream>

using namespace std;

template <typename Item_Type>
int linear_search_last(vector<Item_Type>& items, Item_Type& target, int pos_first) {
    // Base case
    if (pos_first == items.size())
        return -1;

    // Call to check the rest of the list
    int last_index = linear_search_last(items, target, pos_first + 1);

    // If found later in list, return index
    if (last_index != -1)
        return last_index;
    
    // Check current position and return
    if (items[pos_first] == target)
        return pos_first;

    return -1;
}


