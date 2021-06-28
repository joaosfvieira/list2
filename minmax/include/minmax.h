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
 * @tparam Itr iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b)
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo
 *
 * @return Um std::make_pair contendo o menor e maior elemento, nesta ordem
 *
 */

template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{   
    Itr it1 = first;
    Itr it2 = first;
 
    if(first == last){
      return std::make_pair(it1, it2);
    }
    if(cmp(*first, *it1)){
      it1 = first;
    }
    else{
      it2 = first;
    }
 
    while(++first != last){
        Itr i = first;

        if(++first == last){
            if(cmp(*i, *it1)){
              it1 = i;
            }
            else if(cmp(*i, *it2) == 0){
              it2 = i;
            }
            break;
        }
        else{
            if(cmp(*first, *i)){
              if(cmp(*first, *it1)){
                it1 = first;
              }
              if(cmp(*i, *it2) == 0){
                it2 = i;
              }
            } 
            else{
              if(cmp(*i, *it1)){
                it1 = i;
              }
              if(cmp(*first, *it2) == 0){
                it2 = first;
              }
            }
        }
    }

  return std::make_pair(it1, it2);
}
}
#endif
