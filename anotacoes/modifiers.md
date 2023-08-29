**Modifiers**

Por padrão as variáveis já são definidas como `auto`, isso significa que será excluída após fechar seu escopo - permitindo que o espaço utilizado para a alocar seja acessado por outro (em C, tratando-se de uma redundância; Em CPP o termo `auto` passa a responsabilidade ao compilador definir o tipo da variável).

Por outro lado, o modifier `static` define que aquela variável não será excluída após o término de uma função, por exemplo. Sendo assim é possível chamar a função múltiplas vezes sem a máquina tenha que ficar excluindo e reservando espaço a cada ciclo/loop, visto que será declarado e definido apenas uma vez - mas ainda podendo ter seu valor alterado (não definido).

*static =/ const*

*Definir é apenas quando há um set de dados (**=**); Alterar é quando há manipulação do dado (**+=**, **%2**, **--**, etc.)*

O método static também define que aquela variável será visível apenas para o arquivo atual; portanto, caso uma variável/função/class que seja definida em um header file e esse .hpp seja incluido em mais de um arquivo cada arquivo terá uma instância única daquele tipo static. Além disso, em escopos internos é inicializado com zero (como em variáveis globais - citação abaixo).

Variáveis globais se iniciam com o valor zerado (para casos de apenas declaração / sem definição), enquanto variáveis que não foram definidas em escopos filhos iniciam com `garbage` - isso é um conteúdo aleatório do espaço alocado (que já estava lá) para esta variável.

`Apenas declaração`: o modifier de `extern` faz apenas uma declaração da variável, a qual deve estar presente em um outro arquivo mas que será utilizada pelo arquivo atual; assim sendo necessário apenas acessá-la e não alocar mais espaço.

**Constant**

Podem ser definidas com #define (**MACRO NAME**), fazendo com que o pré-processo substitui o primeiro conteúdo pelo o que vem a seguir:

```
#define PI 3.14
```

Assim todo o conteúdo que encontre PI será trocado por 3.14 antes de compilar.

**NEW**

A utilização de `new` indica uma alocação de memória de maneira dinâmica, isso é, para que o programa tenha autonomia de alocar memória durante sua execução e não apenas de maneira estática - a qual ocorre no processo de compilar (variáveis auto ou static).

Quando você usa o operador new em C++, está alocando memória dinamicamente para um objeto. Para rastrear e acessar esse objeto, você precisa de um **ponteiro** que aponte para a posição de memória alocada. Portanto, ao usar o operador new, você deve definir a variável como um ponteiro.

Vale lembrar que para disponibilizar seu espaço de memória após o uso (caso antes do fim do programa) se deve excluir manualmente. A sintaxe segue a ordem: `delete name_of_variable`, sendo necessário em alguns tipos passar o tipo de dado; exemplo: caso necessite deletar um array a sintaxe deve iniciar com `delete[]`.
