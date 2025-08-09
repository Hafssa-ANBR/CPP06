/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:51:30 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/09 14:14:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    *this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &affect)
{
    (void)affect;
    return(*this);
}

ScalarConverter::~ScalarConverter() {}

int pseudoliterals(std::string literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" 
        || literal == "-inf" || literal == "+inf" || literal == "nan")
        return (1);
    return (0);
}

void char_cast(double val)
{
    std::cout << "char cast :" << std::endl;
    if (val < 0 || val > 127)
        std::cout << "impossible :: invalid character" << std::endl;
    else if(!isprint(static_cast<char>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
}
void int_cast(double val)
{
    std::cout << "int cast :" << std::endl;
    if(val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))//why cast INT_MAX
        std::cout << "value out of int range" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
}
void float_cast(double val)
{
    std::cout << "float cast :" << std::endl;
    
}
void double_cast(double val)
{
    std::cout << "double cast :" << std::endl;
    
}
    
void ScalarConverter::convert(std::string literal)
{
    int i = 0;
    double val;
    char *endptr = NULL;
    if (pseudoliterals(literal))
    {
        std::cout << literal << std::endl;
        return;
    }
    else if (literal.length() == 1 && !isdigit(literal[0]))
        val = static_cast<double>(literal[0]);
    else
    {
        val = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0' && (*endptr != 'f' || *(endptr + 1) != '\0'))
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
        if (val > std::numeric_limits<double>::max() ||
            val < std::numeric_limits<double>::lowest())
        {
            std::cout << "value out of range" << std::endl;
            return;
        }
        char_cast(val);
        int_cast(val);
        float_cast(val);
        double_cast(val);
        
    }
}
