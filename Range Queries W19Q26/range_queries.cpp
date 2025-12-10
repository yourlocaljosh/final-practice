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
  for(size_t i = 0; i < data.size(); ++i){
    if(frequency[data[i]].empty()){
      frequency[data[i]].assign(data.size(),0);
    }
    for(auto &j: frequency){
      auto &vec = j.second;
      if(i==0){
        vec[i] = 0;
      }else{
        vec[i] = vec[i-1];
      }
    }
    frequency[data[i]][i]++;
  }
  for(const auto &q : queries){
    auto it = frequency.find(q.id);
    if(it == frequency.end()){
      cout << 0 << ' ';
    }else{
      const auto &vec = it->second;
        unsigned before = (q.start == 0 ? 0 : vec[q.start - 1]);
        unsigned cnt = vec[q.end] - before;
        cout << cnt << ' ';
      }
  }
}
