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
 * @tparam BidirIt iterator para o range.
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 *
 * @return void
 *
 */
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
  BidirIt it1 = first;
  BidirIt it2 = last;

  while ((it1 != it2) && (it1 != --it2)){
    std::iter_swap(it1,it2);
    ++it1;
  }
}
}
#endif
