#ifndef STATE_H
#define STATE_H


class State
{
private:
    int old_angel = 0 , overall_angel = 0  , slider_value ;
public:
    State();
    State(int old_angel ,int overall_angel ,int slider_value);
    void setState(State st);
};

#endif // STATE_H
