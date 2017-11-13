#ifndef MINIJAVA_VISITABLE
#define MINIJAVA_VISITABLE

class Visitor;

class Visitable
{
public:
    // Visitable();
    virtual void accept(Visitor *v) = 0;
    virtual ~Visitable() {}
};

#endif