#include <chrono>
#include <thread>
#include <iostream>

int main() {

    long unsigned int arr_size = 8UL * (1 << 30);
    int step = 1 << 10;
    char* array = new char[arr_size];

    long unsigned int index = 0;
    char char_for_read = 0;
    while (index < arr_size) {
        char_for_read = array[index];

        index += step;

        if (index / step % (1 << 10) == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
    
    delete[] array;

    return 0;
}
