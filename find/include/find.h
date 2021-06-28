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
 * @tparam T para o value a ser comparado
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param value O valor a ser comparado na função
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação deve ser bool eq( const Type &a, const Type &b)
 *
 * @return Um iterator(ou ponteiro) para o primeiro elemento que satisfaz a função eq
 *
 */
template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{
    InputIt it1 = first;
    InputIt it2 = last;

    while(it1 != it2){
      if(eq(*it1, value)){
        return it1;
      }
      it1++;
    }
    return last;
}
}
#endif
