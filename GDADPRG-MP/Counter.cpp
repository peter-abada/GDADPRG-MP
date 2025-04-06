#include "Counter.h"


/*

this class is used for spawning the platforms and enemies with differnet counts
it has a function to increment the counter and reset back to 0 and return the current count

*/


Counter::Counter(int initialCounter) : counter(initialCounter) {
}

void Counter::increment() {
    counter++;
}

void Counter::reset() {
    counter = 0;
}

int Counter::getCounter() {
    return counter;
}

