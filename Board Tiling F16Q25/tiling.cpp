/* 
 * tiling.cpp 
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 F16E2 Q25 Written.
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

#include "tiling.h"

using namespace std;

//O(n) time with O(n) auxiliary space
//12 lines of code limit
int number_of_tilings(int n) {
  vector<int> dp(n+1,0);
  if(n>1){
    dp[1] = 1;
  }
  if(n>2){
    dp[2] = 3;
  }
  for(size_t i = 3; i < dp.size(); ++i){
    //Dynampic Programming
    dp[i] = dp[i-1] + (2*dp[i-2]);
  }
  return dp[dp.size()-1];
}
