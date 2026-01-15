class Calculator {
public:
    // Methods change the internal state and return the updated total.
    double add(double value);
    double subtract(double value);
    double multiply(double value);
    double abs(); // Absolute value
    
    // Throws an exception on division by zero.
    double divide(double value);

    // Throws an exception when state is negative
    double sqrt();
    
    // Accessor method to retrieve the state.
    double getState() const;
    
    // Resets the internal state.
    void clear();

    double factorial();

private:
    double state = 0.0;
};