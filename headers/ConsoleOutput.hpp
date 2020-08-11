#ifndef CONSOLE_OUTPUT_HPP
#define CONSOLE_OUTPUT_HPP

#include <stdint.h>

class ConsoleOutput {
    public:
        ConsoleOutput(ConsoleOutput&) = delete;
        ~ConsoleOutput();
        static ConsoleOutput& init();
        void print(uint8_t** array, const uint8_t xSize, const uint8_t ySize);

    private:
        ConsoleOutput();
        void initArray(uint8_t** array, const uint8_t xSize, const uint8_t ySize);
        void newArray(uint8_t** array, const uint8_t xSize, const uint8_t ySize);
        void checkArrayChanges(uint8_t** array, const uint8_t xSize, const uint8_t ySize);
        void updateConsole(const uint8_t x, const uint8_t y, const uint8_t c);
        void deleteArray();

        uint8_t mXSize;
        uint8_t mYSize;
        uint8_t** mArray;

};

#endif // CONSOLE_OUTPUT_HPP
