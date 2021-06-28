#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * TODO: documentação no estilo doxygen
 */
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
  ForwardIt it1 = first, it2 = last;

  while(it1 != it2){
    if(!cmp(*it1, *it2)){
      std::iter_swap(it1, it2);
    }
    it1++;
  }
    
}

}
#endif
