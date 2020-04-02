//
// Created by waff on 3/27/20.
//
// Improved by FreeDOOM on 4/02/20
//

#ifndef UNTITLED4_STACK_H
#define UNTITLED4_STACK_H
#include <iostream>


template <typename T> class Stack {
private:
    T* array = NULL;
    size_t current_index = 0;
    size_t max_size = 32;

public:
    Stack (const Stack& original){
		array = original.array;
		current_index = original.current_index;
		max_size = original.max_size;
		std::cout << "\033[36m[DEBUG]\033[37m Duplication constructor called (" << std::addressof(array) << ")\033[0m\n";
	}
    Stack (size_t n) {
        // The what? Cannot we just use a debugger?
        std::cout << "\033[36m[DEBUG]\033[37m Variable length constructor called (" << std::addressof(array) << ")\033[0m\n";
        array = new T[max_size = n];
    }

    Stack () {
        // Like, for real... Printing stuff to console for debugging is the biggest sin a programmer can commit!
        std::cout << "\033[36m[DEBUG]\033[37m Default constructor called (" << std::addressof(array) << ")\033[0m\n";
        array = new T[max_size];
    }

    ~Stack () {
        // Still haven't changed my mind. At least nobody forces me to use stdout so I can use std::cerr for that...
        // I was wrong... std::cerr is not in sync with std::cout so it randomly places messages either befor or after stdout...
        // Fortunately I can still use ANSI...
        std::cout << "\033[36m[DEBUG]\033[37m Destructor called (" << std::addressof(array) << ")\033[0m\n";
        delete[] array;
    }

    size_t push (T item) {
        if (current_index == max_size) {
            throw std::overflow_error("https://stackoverflow.com/questions/1110138/what-is-a-stack-overflow");
        }

        array[current_index++] = item;
        return current_index;
    }

    T top () {
        if (current_index == 0) {
            throw std::out_of_range("There is nothing in there :<");
        }

        return array[current_index - 1];
    }

    T pop () {
        if (current_index == 0) {
            throw std::out_of_range("You stole everything!");
        }

        return array[--current_index];
    }

    bool empty () {
        return current_index == 0;
    }
};



#endif //UNTITLED4_STACK_H
