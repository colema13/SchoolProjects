#include "Calculator.hpp"
#include <stdexcept>
#include <cmath>

double Calculator::add(double value){
    state += value;

    return state;
}

double Calculator::subtract(double value){
    state -= value;

    return state;
}

double Calculator::multiply(double value){
    state *= value;

    return state;
}

double Calculator::abs(){
    if(state < 0){
        state = -state;
    }

    return state;
}

double Calculator::divide(double value){
    if(value == 0){
        throw std::invalid_argument("Cannot divide by 0");
    }
    else{
        state /= value;
    }

    return state;
}

double Calculator::sqrt(){
    if (state < 0){
        throw std::invalid_argument("Cannot take sqrt of a negative number");
    }
    double guess = 1.0;
    double old_guess = 0.0;
    double diff;

    do {
        old_guess = guess;

        guess -= (guess*guess - state) / (2 * guess);

        diff = guess - old_guess;
        if(diff < 0){
            diff = -diff;
        }
    } while(diff > 0.0001);

    state = guess;

    return guess;
}

// Accessor method to retrieve the state.
double Calculator::getState() const {
    return state;
}

// Resets the internal state.
void Calculator::clear(){
    state = 0.0;
}

double Calculator::factorial(){
    if (std::floor(state) != state){
        throw std::invalid_argument("Number must be an integer");
    }
    if (state < 0.0){
        throw std::invalid_argument("Cannot take factorial of a negative number");
    }

    if (state == 0.0){
        state = 1.0;
        return state;
    }
     
    double temp_state = state;
    double total = 1;

    while(temp_state != 0){
        total = temp_state * total;
        temp_state-=1;
    }
    state = total;

    return state;
}