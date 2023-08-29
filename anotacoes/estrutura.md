**Estrutura de um programa C**

- Pre-processor directives

São as importações presentes em seu código, as quais servem para trazer um código a um maior nível humano e assim tornar o processo mais rápido. A implementação do **header**/library em um executável ocorre antes mesmo da compilação, sendo reescritas (realizando uma cópia do arquivo cujo nome é fornecido) pelo seu real conteúdo no código fonte.

Um exemplo desse uso é o import do ```#include <stbio.h>``` que fornece funções para entrada e saída de dados em C (como printf e scanf - imprimir e ler dados, respectivamente); para C++ o import mais padrão é o ```#include <iostream>```.

- Header files

**Uso de <> ou de ""**: enquanto com <> a substituição de pre-processo será feita apenas com os arquivos inclusos no `diretório do include` (local do compilador - já é definido o endereço), com o uso das aspas a busca do arquivo é feita primeiramente no direitório atual (visto que o símbolo indica que este include está relacionado ao `arquivo atual`) - caso não encontre irá também buscar no nativo que seu compilador possui.

**Conteúdo de um header file**: ao criar seus próprios arquivos para implementação, o recomendado é que eles apresentem apeans a **declaração**, seja da função, estrutura, classe ou o que quer que seja.

Exemplo:

math.h
```
#pragma once

void math_increment(int &_ref) { _ref++; }; //Para declarações simples é comum vê-las no próprio arquivo header.

void math_pyramid_by_columns(int columns);
```

math.cpp
```
void math_pyramid_by_columns(int columns){
    //        0   1   2
    //    0        *                             - COLUNAS = 3; IMPRIME = 1 (ENTRE 3-**2** E 3-**2**)
    //    1   *    *    *                       - IMPRIME 0, 1, 2 (ENTRE 3-3 E 3-1)
    // ----- O **2** EM DESTAQUE É A QTD DE LINHAS

    //        0    1    2   3    4
    //    0               *                      - COLUNAS = 5; IMPRIME = 2 (ENTRE 5-**3** E 5-**3**)
    //    1         *     *    *                - IMPRIME = 1, 2, 3 (ENTRE 5-4 E 5-2)
    //    2  *      *     *    *    *          - IMPRIME = 0, 1, 2, 3, 4 (ENTRE 5-5 E 5-0)
    // ----- O **3** EM DESTAQUE É A QT DE LINHAS
    // A PARTIR DA QUANTIDADE DE LINHAS E OPERANDO COM O NUMERO DA LINHA ATUAL, OBTEM-SE AS COLUNAS DA LINHA EM QUESTÃO DEVEM SER PREENCHIDAS

    //(ENTRE 3-3 E 3-1) OU (ENTRE 3-(2+LINHA ATUAL) E 3-(2-LINHA ATUAL))
    //(ENTRE 5-4 E 5-2) OU (ENTRE 5-(3+LINHA ATUAL) E 5-(3-LINHA ATUAL))

    int rows_required;
    if (columns <= 0 || columns%2 == 0){
        //goto Quit; - Prática não recomendada por poder ser instável
    } else {
        rows_required = (columns+1)/2;
    }

    for (int i = 0; i < (columns+1)/2; i++){
        for (int j = 0; j < columns; j++){
            if(j >= columns-(rows_required+i) && j <= columns-(rows_required-i))
                std::cout<<"*";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }

    //Quit:
}
```

**#pragma once**: é um pré-processo (mais atual) o qual auxilia na não duplicação de header files, visto que os arquiovs .hpp podem incluir outros; sendo assim, caso você inclua esse outro ao seu programa (e em uma ocasião que não se utilize #pragma once) ocorrerá uma duplicação do quer que esteja dentro desses header files (algumas duplicações de declarações podem ocasionar em nada, enquanto alguns outros tipos (como struct, que não pode ser redeclarado) podem ocasionar erro na depuração).

Versões passadas
```
#ifndef

```

**STL**: biblioteca padrão que deixa o código mais limpo, visto que exclui a necessidade do prefixo ```std::```. Para a chamar se deve inserir ```using namespace std```.

Todavia, vale ressaltar que o uso contínuo de ```std::``` pode atrapalhar na leitura do códgio, visto que sempre que olhar para tal prefixo saberá que é uma funcionalidade da biblioteca padrão. O uso do ```using namespace std``` pode ser considerado uma má prática, podendo levar a **conflitos de nomes**. Por exemplo, se uma biblioteca externa definir sua própria **classe ou função** chamada **string**, isso entrará em conflito com a classe **std::string** (assim o compilador se encontrando em uma indecisão).

**Compilador**

- Primeira etapa: Lida com as importações (#includes, #define e outros pre-processor directives). Seu output é um arquivo CPP sem os pre-processor directives

- Segunda etapa: Compilação, transformando a saída da primeira etapa e produz um arquivo de objeto (?)

- Terceira etapa: Linking, aproveita a saída da segunda etapa e produz uma biblioteca ou um executável.