#include<iostream>
#include <string>
class Counter{
    int counter; int init_counter;
public:
    Counter (int counter){
        counter = counter;
        init_counter = counter;

    }

    int add(int number){
        counter += number;
    };

    int add(){
        counter += 1;
    }

    int get()
    {
        return counter;
    }
    void reset()
    {
        counter = init_counter;
    }
};



int main() {

    return 0;
}
