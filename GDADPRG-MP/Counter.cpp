#include "Counter.h"

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

