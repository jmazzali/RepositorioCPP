#include <iostream>
#include <iomanip>
#include <string>

#define _break std::cout << std::endl

//EX 06
void max_of_four (int *num, int _size){
    int max = num[0];

    for (int i = 1; i < _size; i++){
        if(num[i] > max)
            max = num[i];
    }

    std::cout << "Max: " << max << std::endl;
}

//EX 07
void update(int *a,int *b) {
    int aux = *a;
    *a += *b;
    *b -= aux;

    if(*b < 0)
        *b *= -1;
}

//EX 10
struct Student{
    Student(){};
public:
    int age;
    char first_name[50], last_name[50];
    int standard;
};


int main()
{
    //01 - Hello, World!"
{
    std::cout << "Hello, World!" << std::endl;
}
    _break;
    //02 - std::cin
{
    std::cout << "Digite 3 numeros " << std::endl;
    int n[3];
    std::cin >> n[0] >> n[1] >> n[2];

    //for (int i = 0; i < 3; i++)
    //{
    //    std::cin >> n[i];
    //    if(n[i] < 1 || n[i] > 1000)
    //        i--;
    //}

    std::cout <<"Soma: " << n[0] + n[1] + n[2] << std::endl;
}
    _break;
    //03 - std::cout w/ correct up to decimal places
{
    int _int;
    long _long;
    char _char;
    float _float;
    double _double;
    std::cout << "Digite um int, long, char, float e double: " << std::endl;
    std::cin >> _int >> _long >> _char >> _float >> _double;
    std::cout << "Output: \n" << _int << "\n" << _long << "\n" << _char << "\n" << std::fixed << std::setprecision(3) << _float << "\n" << std::fixed << std::setprecision(9) << _double;
}
    _break;
    //04 - if / else / else if
{
    _break;
    std::cout << "Digite um numero " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Output" << std::endl;
    if(n > 9)
        std::cout << "Greater than 9" << std::endl;
    else if (n >= 1){
        char *vector[10] = {"one","two","three","four","five","six","seven","eight","nine"};
        std::cout << vector[n-1] << std::endl;
    }
}
    _break;
    //05 - for loop
{
    int start, _end;
    std::cout << "Digite 2 numeros " << std::endl;
    std::cin >> start >> _end;
    if(start > _end){
        int aux = _end;
        _end = start;
        start = aux;
    }
    std::cout << "Output" << std::endl;
    std::string vector[10] = {"one","two","three","four","five","six","seven","eight","nine"};
    for (int i = start; i <= _end; i++)
    {
        if(i >= 1 && i <= 9){
            std::cout << vector [i - 1] << std::endl;
        }else if(i > 9){
            if(i%2 == 1)
                std::cout << "odd" << std::endl;
            if(i%2 == 0)
                std::cout << "even" << std::endl;
        }
    }
}
    _break;
    //06 - Function max_of_four
{
    std::cout << "Digite 4 numeros " << std::endl;
    int numbers[4];
    std::cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];
    max_of_four(numbers, sizeof(numbers)/sizeof(numbers[0]));
}
    _break;
    //07 - Function recebendo ponteiro
{
    int a, b;
    int *pa = &a, *pb = &b;
    std::cout << "Digite 2 numeros " << std::endl;
    std::cin >> a >> b;
    update(pa, pb);
    std::cout << "Soma e dif absoluta \n" << a << "\n" << b << std::endl;
}
    _break;
    //08 - Array reverse order
{
    std::cout << "Tamanho do array" << std::endl;
    int array_size;
    std::cin >> array_size;

    std::cout << "Digite os numeros (" << array_size << ")" << std::endl;
    int vector[array_size];
    for (int i = 0; i < array_size; i ++){
        std::cin >> vector[i];
    }
    std::cout << "Ordem reversa" << std::endl;
    for (int i = (array_size-1); i >= 0; i--){
        std::cout << vector[i] << " ";
    }
}
    _break;
    //10 - struct student
{
    _break;
    Student st;
    std::cout << "age, first_name, last_name, standard" << std::endl;
    std::cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    std::cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard << std::endl;
}
    _break;
  return 0;
}
