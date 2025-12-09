/*
 * range_queries.cpp
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 W19E2 Q26.
 * SUBMIT ONLY THIS FILE TO GRADESCOPE.
 */

// Common #includes for convience.
// No need to use them.
// Remove any of them if you want.
#include "range_queries.h"

#include <math.h>

#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

//O(N^2 + Q) average case and O(N^2) space
//25 line limit
void range_queries(const std::vector<unsigned int>& data,
                   const std::vector<Query>& queries) {
  // TODID
  //End goal:
  //O(1) access to how many times an element appears
  //between a range

  //Store how many times an element appears up to an ith range
  //Unordered_map:
  //First = integer
  //Second = vector of size data, where each element in data is how many times
  //the number appeared up to that index
  //5,4,3,5,3,3,2,1,3
  unordered_map<unsigned int, vector<unsigned int>> frequency;
  size_t index = 0;
  for(size_t i = 0; i < data.size(); ++i){
    if(frequency[data[i]].empty()){
      frequency[data[i]].resize(data.size());
    }
    index = data[i];
    for(auto &j: frequency){
      if(index==0){
        j.second[index] = 0;
      }else{
        j.second[index] = j.second[index-1];
      }
    }
    frequency[data[i]][index]++;
    index++;
  }
  for(size_t i = 0; i < queries.size(); ++i){
    cout << frequency[queries[i].id][queries[i].start - queries[i].end] << " ";
  }
}
