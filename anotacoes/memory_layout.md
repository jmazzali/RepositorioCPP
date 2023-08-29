**Memory Layout**

Divididos em 2 partes: Text/code segment; Data segment.

1 - Text/code segment: Contém o código de máquina (assembly) gerado pelo compilador.

2 - Data segment:

a - Variáveis não inicializadas (bss - Block started by Symbol)

*Exemplo: ```static int i```, `i` terá um espaço reservado na memória, todavia com valor zerado.*

b - Variáveis inicializadas

*Exemplo: ```static int i = 0```, `i` apesar de ser inicializado como zero, quando esta declaração é feita por nós a variável passa a agrupar esse conjunto de memória do programa. Detalhe: uma vez inicializada a variável permanece entre as variáveis inicilizadas; a não ser que não seja uma variável com o modifier `static` e que o seu escopo ou função se encerre*

c - Stack

Método de alocar memória mais rápido, visto que são armazenados de maneira sequencial; no entanto tais são as variáveis que são excluídas após encerrar a função ou o escopo. *Realizado com apenas 1 instrução*

d - Heap

Espaço destinado para alocar de maneira dinâmica/durante execução. Variáveis não possuem endereços adjacentes mas seu lifetime é diferente das variáveis armazenadas em stack. Para sua função é mantido uma espécie de free-list que são os espaços que o programa (por um track) pode utilizar. *Realizado através de um conjunto de instruções*

**Neste método cache misses são mais prováveis.*