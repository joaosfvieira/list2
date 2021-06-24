# Trabalho 02: Programação usando o Padrão Iterator

Nestes exercícios iremos desenvolver uma série de Funções que representam algoritmos típicos para manipulação de vetores, assim
todas as funções receberão um _range_ que deve ser operado como argumento.

O principal objetivo deste exercício é praticar programação usando estruturas de abstração de alto nível, onde seu código não precisa
saber qual o tipo de dados ele está operando. Para fazer isso o nosso código precisa usar funções __template__ associadas com ponteiros.
Os __templates__ dão suporte à criação de funções genéricas, enquanto os ponteiros nos ajudam a definir o _range_ onde as operações serão
executadas.

O objetivo secundário é adquirir exeperiencia de programação na construção de bibliotecas de operações típicas em vetores, chamaremos essa
biblioteca de graal(Generic Array Algorithm Library). Através da experiencia de construir essa bibiliteca, iremos experimentar a importância da abstração
de dados e reusabilidade de código no desenvolvimento de aplicações.
<!--
In this exercise you should develop a series of functions that represent typical algorithms for
array manipulation. Because we are still following an imperative programming paradigm, all
functions should receive the range we wish to operate on as an argument.

The primary goal of this exercise is to practice a higher level of abstract programming,
where our code does not need to know in advance which type of data we are operating on. To
do that our code requires the use of function template in association with function pointers.
The former supports the passage of generic arguments to functions, whereas the latter helps
us to defer some decisions to the client by allowing them to provide the code to operate on
data.

The secondary objective is to acquire programming experience by building a library of
typical algorithms on arrays, called graal —GeneRic Array Algorithms Library. By building
this generic library we want to demonstrate the importance of programming abstraction and
code reuse while developing an application in the next exercise.
-->

## O padrão de programação orientado à Iteradores (Iterator Programmint Pattern)

Um _Iterator_ é usualmente representado por um objeto(uma instancia de uma Classe do paradígma de Programação Orientado à Objetos)
que pode iterar sobre um container(que usualmente, também é um Objeto) sem saber como o container é implementado ou funciona internamente.
Na STL, os iteradores são o método mais usado para acessar os elmentos em listas e outros containers.

Por exemplo, se quisermos itear sobre todos os elementos em um `std::vector` de inteiros para imprimir todos os elementos o código seria desta forma:

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> vect;               // Declara um vetor de inteiros.
    for (auto i(0) ; i < 6 ; ++i)
        vect.push_back(i);          // Insere elementos no vetor
    vector<int>::const_iterator it; // Declara um iterator
    it = vect.begin();              // Atribui ao iterator o inicio do vetor
    while (it != vect.end()) {      // Enquanto não chegou no fim
        cout << *it << " ";         // imprime o valor do elemento "apontado" pelo iterato
        ++it;                       // move para o próximo elemento
    }
    cout << endl;
}
```
Veja que o uso dos Iterators é muito similar aos __ponteiros__. De fato, informalmente, um Iterator pode ser uma representação
de um ponteiro encapsulada em uma representação mais abstrata(e com mais possibilidades).

Quando virmos mais à frente alguns containers da STL, vocé constatará que todas essas classes tem quatro métodos básicos que são projetados
para ajudar ao usuário interar sobre os elementos:
- begin() retorna um _iterator_ que aponta para o primeiro elemento de um container
- end() retorna um _iterator_ que aponta para o final de um container. O final é representado por uma posição que está logo após o último elemento.
- cbegin() retorna um _iterator_ (read-only) que aponta para o primeiro elemento de um container
- cend() retorna um _iterator_ (read-only) que aponta para o final de um container. O final é representado por uma posição que está logo após o último elemento.

Um fato importante é que os _iterators_ retornados por __cend()__ e __end()__ apontam sempre para uma posição _após_ o ultimo elemento do container, como mostrado abaixo. Dessa forma, se deseramos definir um _range_ de elementos em qualquer container sempre nos referimos a um intervalo \[__begin()__, __end()__) -ou seja, sempre definimos um intevalo
fechado-aberto!

```
       begin()                              end()
          ↓                                   ↓
Índice |  0|  1| 2| 3|  4|  5| 6| 7|  8| 10|  X|
``` 

## Exercícios

Nos exercícios que seguem iremos treinar o uso e implementações com iteradores implementando funções __template__ que podem receber tanto _iterators_ da STL quanto ponteiros
convencionais em suas chamadas, em ambos os casos, definidos sobre uma espaço sequencial de memória (um stati array ou um container da STL).  Dessa forma, cada vez que 
uma das funções é chamada, precisamos informar o _range_ onde a função vai operar. 

Por exemplo, se o usuário da função deseja __inverter__ os elementos de um array (usando a função _reverse_), a função deve receber dois ponteiros: um apontando para a posição
inicial do _range_ e outro apontando para a posição logo após o final do _range_, definindo assim os elementos que devem ser considerados na operação.

De forma similar se o usuário quiser __inverter__ os elementos de um ``std::vector`` inteiro, ele poderá usar a mesma função _reverse_, porém passando dois _iterators_, correspondentes ao __begin()__ e __end()__ daquele vetor. Em termos de programação, não faz diferença já que estamos usando __templates__, lembre que essa funcionalidade do c++
permite a geração de código "sob demanda" durante a compilação.

Pelo ponto de vista de quem usa a função __reverse__, a chamada é ``reverse(std::being(A), std::end(A))``, onde as funções ``std::begin()`` e ``std::end()`` são definidas na
biblioteca ``<iteartor>`` e retornam ponteiros para o início e "fim"(lembre que não é o último elemento, mas sim a posição logo após o último) de um array estático ou os 
iterators apontando para as posições respectivas de _begin()_ e _end()_ de um container. É possível, usando esse mesmo formato, reverter apenas 4 elementos de um array fazendo
``reverse(std::being(A), std::begin(A)+4)``, atente que o array precisa ter ao menos 4 elementos para que a chamada funcione.

Assim os exercícios que faremos são os seguintes:

1. [minmax](./minmax)
2. [reverse](./reverse)
3. [copy](./copy)
4. [find_if](./find_if)
5. [find](./find)
6. [all/any/none_of](./all_any_none_of)
7. [equal](./equal)
8. [unique](./unique)
9. [partition](./partition)
10. [sort](./sort)
11. [rotate](./rotate)


