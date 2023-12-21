#include <iostream>
#include "Stack.hpp"

int main()
{
    int num;
    std::cout << "Pon cualquier numero: ";
    std::cin >> num;

    Stack<int> binaryStack(32);

    if (num == 0) {
        std::cout << "Binario: 0" << std::endl;
        return 0;
    }

    while (num != 0)
    {
        binaryStack.Push(num % 2);
        num /= 2;
    }

    std::cout << "Binario: ";
    // Vamos a pop todos los elementos del stack y imprimirlos
    while (!binaryStack.IsEmpty())
    {
        std::cout << binaryStack.Top();
        binaryStack.Pop();
        //el ultimo en entrar es el primero en salir.
    }
    std::cout << std::endl;

    return 0;
}