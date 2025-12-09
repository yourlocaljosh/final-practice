/* 
 * zero_sum.cpp 
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 W19E2 Q25.
 * SUBMIT ONLY THIS FILE TO GRADESCOPE.
 */

// Common #includes for convience.
// No need to use them. 
// Remove any of them if you want.
#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
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

#include "zero_sum.h"

using namespace std;

//O(n) time and space
//15 line limit
bool zero_contiguous_sum(std::vector<int>& nums) {
  // TODID
  unordered_set<int> sums;
  //Compute the sums, add it to a set
  //If a sum is 0 or equal to a previous sum, we have a zero
  //Otherwise return false
  int sum = 0;
  sums.insert(sum);
  for(size_t i = 0; i < nums.size(); ++i){
    sum+=nums[i];
    if(sums.find(sum)!=sums.end()){
      return true;
    }
    sums.insert(sum);
  }
  return false;
}
