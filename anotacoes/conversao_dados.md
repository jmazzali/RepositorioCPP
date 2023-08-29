**Conversão de tipos de dados**

Ocorre de forma automática desde que o estado inicial seja menor que o final (exemplo: int -> float). Conversões no caminho oposto possuem casting, exemplo: 

```
double bal = 90.50;
int intBal;
intBal = (int)bal; // C-style casting

double valorDouble = 3.14;
int valorInt = static_cast<int>(valorDouble); // static_cast
```

Operações matemáticas podem ser trabalhas ao nível de bit para performarem mais rápido. (**BITWISE OPERATORS**)

Variáveis podem ser dependentes desde sua criação, sem depender de uma condição (como if, while, etc.). Isso ocorre através do uso dos **operadores miscellaneous**, que são operadores **condicionais** - sua sintaxe ocorre através do ```?```, caso verdadeiro a variável recebe o primeiro valor senão o segundo.

```
int a = 10,b=2;
int b = a > 10?a:b;

int c = a > 10 ? a : b;

OUTPUT:
a = 10
b = 2
c = 2
```