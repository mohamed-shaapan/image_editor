#include "state.h"

State::State(){}

State::State(int old_angel, int overall_angel, int slider_value)
{
    this->old_angel = old_angel;
    this->overall_angel = overall_angel;
    this->slider_value = slider_value;
}

void State::setState(State st){
    this->old_angel = st.old_angel;
    this->overall_angel = st.overall_angel;
    this->slider_value = st.slider_value;
}


