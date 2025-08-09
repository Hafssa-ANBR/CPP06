#include <iostream>
int main()
{
    std::string literal = "-1.7976931348623157e+309";
    double val;
    char *endptr = NULL;
    val = std::strtod(literal.c_str(), &endptr);
    std::cout << "haaa : " << val << std::endl;
    if (*endptr != '\0' && (*endptr != 'f' || *(endptr + 1) != '\0'))
    {
        std::cout << "Invalid literal" << std::endl;
        return(1);
    }
    if (
        val < std::numeric_limits<double>::lowest())
    {
        std::cout << "value out of range" << std::endl;
        return(1);
    }




    std::cout << -std::numeric_limits<double>::infinity() << std::endl;
    std::cout << std::numeric_limits<double>::infinity() << std::endl;
    std::cout << std::numeric_limits<double>::lowest() << std::endl;

}