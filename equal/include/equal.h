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
 * @tparam InputIt1 iterator para o range.
 * @tparam InputIt2 iterator para o segundo range.
 * @tparam Equal para a função eq.
 *
 * @param first1 Ponteiro para o primeiro elemento do range
 * @param last1 Ponteiro para a posição logo após o último elemento do range
 * @param first2 Ponteiro para o primeiro elemento do segundo range
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação deve ser bool eq( const Type &a, const Type &b)
 *
 * @return Retorna verdadeiro se os ranges são iguais, falso caso contrário
 *
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
  InputIt1 itf1 = first1, itl1 = last1;
  InputIt2 itf2 = first2;

  while(itf1 != itl1){
    if(eq(*itf1, *itf2)==0){
      return false;
    }
    ++itf1;
    ++itf2;
  }
  return true;
}

/*! 
 * @tparam InputIt1 iterator para o range.
 * @tparam InputIt2 iterator para o segundo range.
 * @tparam Equal para a função eq.
 *
 * @param first1 Ponteiro para o primeiro elemento do range
 * @param last1 Ponteiro para a posição logo após o último elemento do range
 * @param first2 Ponteiro para o primeiro elemento do segundo range
 * @param last2 Ponteiro para a posição logo após o último elemento do segundo range
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação deve ser bool eq( const Type &a, const Type &b)
 *
 * @return Retorna verdadeiro se os ranges são iguais, falso caso contrário
 *
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
  InputIt1 itf1 = first1, itl1 = last1;
  InputIt2 itf2 = first2;

  while(itf1 != itl1){
    if(eq(*itf1, *itf2)==0){
      return false;
    }
    ++itf1;
    ++itf2;
  }
  return true;
}
}
#endif
