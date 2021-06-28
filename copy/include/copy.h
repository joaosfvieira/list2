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
 * @tparam InputIt iterator para o range.
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param d_first Ponteiro para o primeiro elemento do novo range
 *
 * @return Um ponteiro apontado para a posição logo após o último elemento do novo range
 *
 */
template<class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first)
{
    InputIt it1 = first;
    InputIt it2 = last;

    while(it1 != it2){
      *d_first = *it1;
      it1++;
      d_first++;
    }
    return d_first;
}

}
#endif
