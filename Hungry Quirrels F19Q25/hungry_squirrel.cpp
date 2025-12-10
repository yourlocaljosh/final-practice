/* 
 * hungry_squirrel.cpp 
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 F19E2 Q25.
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

#include "hungry_squirrel.h"

using namespace std;

//O(mn) time and space
//30 line limit
int get_max_nuts(std::vector<std::vector<int>>& diag, int nrow, int ncol) {
  // TODID
  vector<vector<int>> dp(nrow);
  for(auto & i : dp){
    i.resize(ncol);
  }
  //Initialize the leftmost column with the initial values
  for(size_t i = 0; i < dp.size(); ++i){
    dp[i][0] = diag[i][0];
  }
}
