#include <iostream>
#include <string>
#include "Stack.hpp"

int main() {
    Stack<int> stack;

    std::cout << "Pila vacia: " << (stack.isEmpty() ? "verdadero" : "falso") << "\n";

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Se agrego el numero: " << i << (stack.push(i) ? " verdadero" : " falso") << "\n";
    }

    std::cout << "\nPila vacia: " << (stack.isEmpty() ? "verdadero" : "falso") << "\n\n";

    while (!stack.isEmpty()) {
        std::cout << "Eliminando elemento: " << std::to_string(stack.pop()) << "\n";
    }
    
    return 0;
}
