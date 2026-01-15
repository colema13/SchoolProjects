#include <iostream>

double farenToCel(double farenheit)
{
    double celsius = (farenheit-32) * (5.0/9.0);

    return celsius;
}

double CelToFaren(double celsius)
{
    double farenheit = (celsius * (9.0/5.0)) + 32;

    return farenheit;
}
int main()
{
    double farenheit;
    double celsius;
    int answer;

    std::cout << "How would you like to convert?" << std::endl << "[1] Farenheit to Celsius\n[2] Celsius to Farenheit" << std::endl;
    std::cin >> answer;

    if(answer == 1)
    {
    std::cout << "Enter a value in Farenheit to covert to Celsius: ";
    std::cin >> farenheit;

    celsius = farenToCel(farenheit);
    std::cout <<farenheit << " Degrees Farenheit is " << celsius << " Degrees Celsius." << std::endl;
    }

    if(answer == 2)
    {
        std::cout << "Enter a value in Celsius to covert to Farenheit: ";
        std::cin >> celsius;

        farenheit = CelToFaren(celsius);
        std::cout <<celsius << " Degrees Celsius is " << farenheit << " Degrees Farenheit." << std::endl;

    }
    return 0;

}