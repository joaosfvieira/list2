# Minmax

Implemente uma função chamada minmax que encontra e retorna a primeira ocorrencia do menor e maior elmentos em um _range_ \[first,last).
assuma que o range de entrada é válido. A assinatura da função deve ser como especificado:
```c++
template< typename Itr, typename Compare >
std::pair<Itr,Itr> minmax( Itr first, Itr last, Compare cmp );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- cmp - uma função que retorna true se o elemento é menor do que o segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool cmp( const Type &a, const Type &b)``.

Na furnção cmp o tipo `Type` deve ser o mesmo tipo de Itr, de forma que a função de comparação possa ser usada como `cmp(*it1,*it2)`. Use essa função para
comparar os valores ao invés dos operadores usuais, por exemplo se você quer saber se o elemento apontado por \*it1 é menor do que o elemento apontado por \*it2
ao invés de fazer ``*it < *it2`` voce usaria ``cmp(*it1,*it2)``.

De forma mais concreta, se sua função ``minmax`` vai comparar elementos de um ``std::vector<string>``, sua função cmp deve ser:
```c++
bool cmp(const string &a,  const string &b)
```
Desta forma, quando a função ``minmax`` for comparar os elementos ela não precisa se preocupar se são strings.

## Retorno
A função minmax deve retornar um par com dois itetors, onde o primeiro aponta para o menor elemento e o segundo apenta para o maior elemento.
Caso o intervalo devinido por \[first, last\) seja vazio, retorne ``std::make_pair(first,fist)``. Se houverem vários elementos com o mesmo
valor que o menor ou que o maior elemento, sua função deve retornar iteradores que apontam para a primeira ocorrência dos valores no vetor.