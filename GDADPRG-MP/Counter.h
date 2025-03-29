#pragma once

class Counter
{
public:
    Counter(int initialCounter = 0); 

    void increment();
    void reset();
    int getCounter(); 

private:
    int counter;
};

