// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc
// Make your code short: at most 10 lines of code (LOC)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

// now defiine ECMergeContainers ...
using namespace std;
template <typename inputContainer, typename outputContainer>
void ECMergeContainers(const inputContainer &inputs, outputContainer &outputs) // make it generic
{
    for (const auto &input : inputs) // passing the elements by reference, avoiding copying it unnecessarily and avoid modifying the inputs unnecessarily
    {
        outputs.insert(outputs.end(), input.begin(), input.end());
    }
    sort(outputs.begin(), outputs.end());
}