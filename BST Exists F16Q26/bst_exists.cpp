/* 
 * bst_exists.cpp 
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 F16E2 Q26.
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

#include "bst_exists.h"

using namespace std;

//O(log n) complexity with O(log n) space
//15 line limit
bool exists(Node *node, int val) {
  if(node==nullptr){
    return false;
  }else if(node->val == val){
    return true;
  }
  if(node->val > val){
    return exists(node->left,val);
  }else{
    return exists(node->right,val);
  }
}
