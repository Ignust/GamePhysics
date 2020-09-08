


#if !defined(_CONSOLEOUTPUT_H)
#define _CONSOLEOUTPUT_H


class ConsoleOutput {
public:
    static ConsoleOutput& initConsoleOutput();
    void print(uint8_t** array);
};

#endif  //_CONSOLEOUTPUT_H
