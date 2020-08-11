#include <iostream>
#include <windows.h>

#include <ConsoleOutput.hpp>

//------------------------------------------------------------------------------------------
ConsoleOutput::ConsoleOutput()
    : mXSize(0),
      mYSize(0),
      mArray(nullptr)
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
ConsoleOutput::~ConsoleOutput()
//------------------------------------------------------------------------------------------
{
    deleteArray();
}

//------------------------------------------------------------------------------------------
ConsoleOutput& ConsoleOutput::init()
//------------------------------------------------------------------------------------------
{
    static ConsoleOutput consoleOutput;
    return consoleOutput;
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::print(uint8_t** array, const uint8_t xSize, const uint8_t ySize)
//------------------------------------------------------------------------------------------
{
    if (array == nullptr){
        throw 123;
        return;
    }

    if (mXSize != xSize || mYSize != ySize) {
        newArray(array,xSize,ySize);
    } else {
        checkArrayChanges(array,xSize,ySize);
    }
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::initArray(uint8_t **array, const uint8_t xSize, const uint8_t ySize)
//------------------------------------------------------------------------------------------
{
    mArray = new uint8_t*[ySize];
    for(uint8_t a = 0; a < ySize; ++a){
        mArray[a] = new uint8_t[xSize];
    }

    for(uint8_t y = 0; y < ySize; ++y){
        for(uint8_t x = 0; x < xSize; ++x){
            mArray[y][x] = array[y][x];
        }
    }

    system("cls");
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::newArray(uint8_t **array, const uint8_t xSize, const uint8_t ySize)
//------------------------------------------------------------------------------------------
{
    if (mArray == nullptr) {
        initArray(array,xSize,ySize);
    } else {
        deleteArray();
        initArray(array,xSize,ySize);
    }

    if (array == nullptr){
        return;
    }

    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            std::cout << array[y][x];
        }
        std::cout << std::endl;
    }
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::checkArrayChanges(uint8_t **array, const uint8_t xSize, const uint8_t ySize)
//------------------------------------------------------------------------------------------
{
    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            if (array[y][x] != mArray[y][x]) {
                mArray[y][x] = array[y][x];
                updateConsole(x, y, mArray[y][x]);
            }
        }
    }
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::updateConsole(const uint8_t x, const uint8_t y, const uint8_t c)
//------------------------------------------------------------------------------------------
{
    TCHAR tempC = static_cast<TCHAR>(c);
    static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    static DWORD dw;
    COORD chCoord;
    chCoord.X = static_cast<SHORT>(x);
    chCoord.Y = static_cast<SHORT>(y);
    WriteConsoleOutputCharacter(hStdOut, &tempC, 1, chCoord, &dw);
}

//------------------------------------------------------------------------------------------
void ConsoleOutput::deleteArray()
//------------------------------------------------------------------------------------------
{
    for(int a = 0; a < mYSize; ++a){
        delete [] mArray[a];
    }
    delete [] mArray;
}
