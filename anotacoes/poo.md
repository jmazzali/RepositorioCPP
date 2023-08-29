**CLASS**

São utilizadas para simplificar códigos que necessitem de objetos - os quais devem possuir seus atributos - a serem repetidos, mas diferente de um array terá uma distribuição não organizada/agrupada. A criação de uma classe pode ser entendida como a criação de um novo tipo de dado, por exemplo:

```
class Book{
    int number_pages;
    string author, editor;
};

int main(){
    Book book;
}
```

Sendo assim `book` é uma variável do 'tipo de dado' `Book`, que por sua vez é uma classe que tem os atributos `number_pages, author, editor`. A declaração ```Book book``` é dita como a instância (/declaração) de um objeto (book).

Vale ressaltar que uma classe não te dá nem uma força/poder a mais, visto que tudo que podemos fazer com elas é necessariamente possível fazer sem - sua utilização torna seu código mais limpo e de fácil leitura.

Por padrão, seus métodos e atributos são definidos como `private`.

- **Atributos 'static'**

Essa declaração faz com que tal variável não seja específica de um objeto e passe a se tornar **única** para **todos** que pertencem a determinada **class ou struct**. Exemplo: ghosts do jogo PAC-MAN podem possuir seu status de letal ou não em um atributo static, visto que uma vez consumido o orbe faz com que todos fiquem não letais; quando acabar um tempo x todos voltam a `letais = true`

Estes atributos, todavia, podem ser manipulados por:

- modificação através de um objeto qualquer ou

```
struct Entity{
    static int static_var;
    ...
};

int Entity::static_var;

int main(){
    Entity e;
    e.static_var = 23;

    return 0;
}
```

*A declaração `int Entity::static_var` serve para tornar possível o compilador linkar e tornar o acesso possível (informando ao compilador que a variável estática deve ser alocada na memória e preparada para uso). Isso é chamado de **definição da variável estática e deve ser feito uma vez no escopo global**.*

*A declaração não é necessário caso a variável (static dentro de struct ou class) seja **const***

Por ser uma variável (mesma lógica de funcionamento para métodos) da classe, pode-se declarar através do próprio nome da class/struct

```
int main(){
    //Entity e;                         //Não necessário
    Entity::static_var = 23;

    return 0;
}
```

- por métodos da própria class - também devem ser static.

```
struct Entity{
    static int static_var;

    /*
    void Print(){
        std::cout << static_var << std::endl;
    }
    */ --Não funciona, pois métodos não static não conseguem acessar atributos static
    static void Print(){
        std::cout << static_var << std::endl;
    }
};
```

- **ENCAPSULAMENTO**

**Construtores**

Por padrão algumas linguagens já realizam uma "limpeza" na inicialização das variáveis de classes e structs, no entanto, em C++, é necessário fazer por conta própria - esse construtor é conhecido por **a**.

Este tipo tem por intuito apenas inicializar as variáveis com valores prefixados (comumente 0). Sua sintaxe se dá pelo nome da própria class/struct sem nenhum parâmetro.

```
struct Person{
private:
    int x, y;

public:
    Person(){
        x = 0;
        y = 0;
    }
};
```

Existem também os construtores por parâmetro:

```
public:
    Person(int a, int b){
        x = a;
        y = b;
    }
```

E por fim os construtores de cópia

```
public:
    Person(Person p){
        x = p.x;
        y = p.y;
    }
```

**Getters e Setters**

São métodos construidos para acessar e inserir dados em variáveis com status privado, respectivamente.

Exemplo:
```
class Example{
    int id;

public:
    void get_id() { return id; }
    void set_id(int x) { id = x; }
};

int main(){

    Example teste;

    teste.get_id();         //Retornará o que estava previamente salvo no espaço de memória que foi selecionado
    teste.set_id(23);       //Objeto terá id definido como 23 agora
    teste.get_id();         //Retornará 23, mas não mostrará
    return 0;
}
```
