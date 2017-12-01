#ifndef MINIJAVA_VISITABLE
#define MINIJAVA_VISITABLE

class Visitor;

class Coordinates {
    public:
        int x;
        int y;

        Coordinates(int x_, int y_) : x(x_), y(y_) {};
};

class Visitable
{
public:
    virtual void accept(Visitor *v) = 0;
    virtual ~Visitable() {}
    Coordinates *coordinates;
};

#endif