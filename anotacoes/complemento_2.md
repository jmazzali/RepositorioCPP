**Complemento de 2**

A representação de um decimal negativo pode ocorrer com o uso desta *técnica*, a qual consiste em obter primeiramente o complemento de 1 (invertendo os estados lógicos dos bits de representação; 0 vira 1 e 1 vira 0) e por fim fazer a soma binária com + 1;

Exemplo:

```
-14(10)

Base binária (unsigned) -> 1110(2)

Complemento de 1:
0001(2)
+1

Complemento de 2:
0010(2) -> -14(10)
```

Então um tipo de dado de até 3 bits: **signed** permite os valores de 0 até 7 (2^3 - 1); **unsigned** permite os valores de -4 (2^(n-1)) até 3 (2^(n-1) - 1). Essa qualificação só é passada quando realizada alguma operação, visto que seu armazanamento (em forma binária) assume os mesmos valores, no entanto uma faixa deles é reservadas para os negativos (**???**).

```
-4(10) -> (2)

100 (unsigned)

011 (inverso)
+1
*100* (complemento de 2)

---

-3(10) -> (2)

011

100(inverso)
+1
*101* (complemento de 2)

---

-2(10) -> (2)
010
101
*110*

---

-1(10) -> (2)
001
110
*111*

---

0(10) -> (2)
000

---

1(10) -> (2)
001

---

2(10) -> (2)
010

---

3(10) -> (2)
011

---
```

Quanto aos **limites** de cada data-type, pode-se compreender que seu valor (de um dado) é em relação ao módulo de seu limite de possibilidades. Por exemplo, em um dado com range de 3 bits (unsigned) o número 1 é ```1 mod 2^3 = 1```; caso extrapole o limite do tipo de dado (no caso 3 bits) o valor que será armazenado será ```x mod 2^3 <= 7``` - x sendo maior que 7.

```
0 mod 8 = 0
1 mod 8 = 1
2 mod 8 = 2
3 mod 8 = 3
4 mod 8 = 4
5 mod 8 = 5
6 mod 8 = 6
7 mod 8 = 7
8 mod 8 = 0
9 mod 8 = 1
... ciclo ...
```

Para dados com range de valores negativos o comportamento é parecido, no entanto o acréscimo de 1 ao valor máximo faz com que seja armazenado o valor mínimo e o decréscimo do valor mínimo retorna para o valor máximo. Este padrão segue para a adaptação do complemento 2.

Até o limite máximo o correspondente binário segue a ordem normal, a sequência do binário segue a ordem limite mínimo até o zero. Assim, faz-se compreensível a determinação dita no parágrafo anterior.

Então ao inserir um caractere que extrapole o limite (por exemplo: caso o padrão adotado seja ASCII e o correspondente do caractere seja maior que 127 ou menor que -128) o que acontecerá é que existirá um correspondente.

```
128 (fora do limite SIGNED) equivale -128 (dentro do limite SIGNED)

-128(10) -> (2)

1000000
(inverso)0111111
(+1)1000000

135 (fora) equivale -121 (dentro)

135(10) -> (2)
-121(10) -> (2)

10000111 (135)

-121 -> 01111001
(inverso) 10000110
(+1) 10000111 (-121 c/ complemento de 2)
```