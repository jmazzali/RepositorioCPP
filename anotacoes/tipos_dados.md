**DATA TYPE**

- Size of int: ao declarar esse tipo estamos tornando a variável dependente do hardware em uso. Para máquinas de 16-bits o size of int representa 2 bytes, enquanto para 32-bits representa 4 bytes

1 byte = 8 bits

8 bits representa até 2^8 

*Podemos utilizar sizeof para auxiliar a definir, por exemplo, o tamanho de um array. Para isso basta dividir o tamanho (sizeof) do array pelo tamanho unitário; exemplo: caso um array de x inteiros ocupe 32 bytes e sabendo que cada inteiro (unidade) ocupa 4 bytes então temos 7 números inteiros (32/4).

- Basic or predefined (**BUILT IN**)

|Data|Meaning|Size(byte)|
|:---:|:---:|:---:|
|int|Integer|Depende da máquina|
|float|Floating point|4|
|double|Double floating point|8|
|char|character|1| - de acordo com a decodificação (conjuntos de 0's e 1's significam diferentes caracteres - tabela ASCII ?)
|wchar_t|wide character|2|
|bool|boolean|1| - não seria 1 bit? 1 ou 0; True or False.
|void|empty|0|

---

- Tipos de dados variados (**DERIVED**) dos primários são os arrays, functions e pointers. Ponteiros derivam do tipo básico visto que são auxiliares para armazenar o endereço de memória que a variável externa a ela possui.

---

- Tipo de dados definidos pelo usuário (**USER-DEFINED**), como classes que possuem seus próprios membros de dados e funções (exemplo: classe de carro possui ano [int] cor [array de char] e ligar motor[como uma função]);

- **enumareted data type**: usado para criar um conjunto de **constantes nomeadas**, onde cada constante é associada a um valor inteiro único (exemplo: ```enum DiaDaSemana {DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO};```) 

- **structures**: como um enumareted data só que com variação de tipos de dados de seus membros (com cada **membro** podendo ser **acessado individuamente**, diferentemente de **unions** - onde os membros compartilham o mesmo espaço de memória, ou seja, apesar de possuir diferentes tipos de dados só é alocada um membro. caso escreva sobre diferentes membros o que será salvo na memória será o último)

Exemplo de union:

```
union Dados {
    int numero;
    float valor;
    char caractere;
};


int main() {
    Dados dados;

    dados.numero = 42;
    std::cout << "Valor do número: " << dados.numero << std::endl;

    dados.valor = 3.14;
    std::cout << "Valor do float: " << dados.valor << std::endl;

    dados.caractere = 'A';
    std::cout << "Caractere: " << dados.caractere << std::endl;

    // Devido ao compartilhamento de memória, o valor do número é sobrescrito
    std::cout << "Novo valor do número: " << dados.numero << std::endl;

    return 0;
}
```


```
Valor do número: 42
Valor do float: 3.14
Caractere: A
Novo valor do número: 65
```

O número será interpretado como o caractere 'A', pois quando atribuímos o valor 'A' ao membro "caractere" da união, ele compartilha o mesmo espaço de memória com o membro "numero". Como a representação do caractere 'A' em ASCII é 65, esse valor será interpretado como o valor do número.


**Qualificar dados/tipos (qualifiers)**

Quanto ao *tamanho* (short or long), *tipo*(volatile or constant) e *sign*(signed or unsigned).

A qualificação de uma variável pode influenciar no desempenho, ocupando menos espaço na memória. A declaração, por exemplo, de um valor inteiro (isto é permitido apenas para int e char; para char, pesquisar: **tabela ASCII e MSB bit**) unsigned determina que aquele valor não pode ser negativo - assim seu espaço de operação sai de -2^(n-1) -> 2^(n-1)-1 para apenas 0 -> 2^(n)-1. "n" sendo o número de bits que o hardware trabalha (**2's complement range**).

Fazendo o decremento do expoente o que estamos fazendo basicamente é dividir o range máximo em 2, assim reservando, quase de maneira igual, espaço para os números inteiros negativos.

# complemento_2.md

# conversao

**Escopos**

Variáveis (de mesmo nome) em diferentes **escopos** . Para diferenciar o uso de uma variável local e utilizar o valor salvo na variável de mesmo nome só que de maneira global, deve-se usar ```::variavel_global```, sem o ```::``` será utilizado o valor local.

Sobre os escopos também é importante saber que o acesso às variáveis depende da construção do código. Escopos filhos conseguem acessar variáveis do escopo pai (assim como um interno consegue acessar variável global), mas o caminho inverso é incorreto; já quando não há nenhuma relação as variáveis ficam reestritas ao seus respectivos.

A busca pelo conteúdo de uma variável ocorre no sentido LOCAL -> GLOBAL; caso não encontre no escopo global ocorrerá a busca da variável global com aquele nome.

```
int function();
int var = 10;

int main(){
    int var = 3;
    std::cout<<var<<std::endl;
    function();
    return 0;
}

int function(){
    std::cout<<var<<std::endl;
}
```

OUTPUT:

```
3
10
```