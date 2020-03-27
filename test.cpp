//
// Created by waff on 3/27/20.
//

#include "stack.h"
#include <cassert>

int main () {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(1);
    stack.push(2);

    assert(stack.pop() == 2);
    assert(stack.pop() == 1);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);

    auto stack1 = new Stack<int>(0);

    // Really no idea how to check this any other way since there is no assert_throws or something like it
    unsigned thrown = 0b00;
    try {
        stack1->pop();
    } catch (std::exception& err) {
        thrown |= (unsigned) 0b01;
    }

    assert(((void)"No out of range", thrown & (unsigned) 0b01));

    try {
        stack1->push(1);
    } catch (std::exception& err) {
        thrown |= (unsigned) 0b10;
    }

    assert(((void)"No stack overflow", thrown & (unsigned) 0b10));

    std::cout << "All tests passed.\n";
}
