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
 * @tparam UnaryPredicate p uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. * A assinatura da função
 * deve ser bool p( const Type &a).
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p A função retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 *
 * @return Um iterator apontando para o primeiro elemento do range que satisfaz p
 *
 */
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
  InputIt it1 = first;
  InputIt it2 = last;

    while(it1 != it2){
      if(p(*it1)){
        return it1;
      }
      it1++;
    }
    return last;
}
}
#endif
