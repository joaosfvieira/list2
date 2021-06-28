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
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
  InputIt it1 = first, it2 = last;



    while(it1 != it1){
      InputIt aux = first;
        if(eq(*it1, *aux)){
          *it1 = *aux;
          
        }
        ++it1;
    }
    return true;

  


    return last;
}

}
#endif
