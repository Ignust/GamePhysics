


#if !defined(_GAMEENGINE_H)
#define _GAMEENGINE_H


class GameEngine {
public:
    void starGameLoop();
    void addObcet(IObject* obj);
private:
    uint8_t** mField;
    std::list<IObject*> mObjectList;
    const uint8_t mFieldSizeY;
    const uint8_t mFieldSizeX;
    void renderField();
};

#endif  //_GAMEENGINE_H
