#include <iostream>
#include "stack.h"

// Invalid version provided by the author of the exercise
// What goes wrong? Double free.
/*
template<typename T>
void external (Stack<T> stack, T item) {
    stack.push(item);
}
*/

// Simple fix
template<typename T>
void external (Stack<T>* stack, T item) {
    stack->push(item);
}

template<typename T>
Stack<T> elide_constructor () {
    Stack<T> stack;
    return stack;
}

int main () {
    Stack<int> stack;
    stack.push(0);

    // Again invalid code provided by author
    /*
    external(stack, 1);
    external(stack, 2);
    */

    // And simple fix
    external(&stack, 1);
    external(&stack, 2);

    while (!stack.empty()) {
        // Like for real?? Why the heck in the source one hasn't used std:: ?
        // And why newline between piping and a piped item???
        // Not to mention that normally Stack#pop() should return popped element
        std::cout << stack.top();
        stack.pop();
    }

    std::cout << "\n";

    // The only thing I could see when adding -fno-elide-constructors is a double free...
    // A lot of invalid frees to be honest
    std::cout << "Elide constructors test:\n";
    auto stack1 = elide_constructor<int>();
    stack1.push(1);
    std::cout << stack1.pop() << "\n";


}
