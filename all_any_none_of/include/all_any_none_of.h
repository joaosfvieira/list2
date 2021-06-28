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
 * @tparam UnaryPredicate para a função do predicado.
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser bool p( const Type &a)
 *
 * @return Retorna verdadeiro se todos os elementos do range satisfazem p, falso caso contrário
 *
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    InputIt it1 = first;
    InputIt it2 = last-1;

    while(it1 != it2){
      if(p(*it1) == 0){
        return false;
      }
      it1++;
    }
    return true;
}

/*! 
 * @tparam InputIt iterator para o range.
 * @tparam UnaryPredicate para a função do predicado.
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser bool p( const Type &a)
 *
 * @return Retorna verdadeiro se ao menos um elemento do range satisfaz p, falso caso contrário
 *
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    InputIt it1 = first;
    InputIt it2 = last;

    while(it1 != it2){
      if(p(*it1)){
        return true;
      }
      it1++;
    }
    return false;
}

/*! 
 * @tparam InputIt iterator para o range.
 * @tparam UnaryPredicate para a função do predicado.
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser bool p( const Type &a)
 *
 * @return Retorna verdadeiro se todos os elementos do range __não__ satisfazem p, falso caso contrário
 *
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    InputIt it1 = first;
    InputIt it2 = last;

    while(it1 != it2){
      if(p(*it1)){
        return false;
      }
      it1++;
    }
    return true;
}

}
#endif
