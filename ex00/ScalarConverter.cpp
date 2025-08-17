/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:51:30 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/17 12:39:54 by hanebaro         ###   ########.fr       */
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
    std::cout << "char : ";
    if (std::to_string(val) == "nan" || val < 0 || val > 127)
        std::cout << "impossible" << std::endl;
    else if(!isprint(static_cast<char>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
}
void int_cast(double val)
{
    std::cout << "int : ";
    if(std::to_string(val) == "nan" || val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))//why cast INT_MAX
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
}
void float_cast(double val)
{
    std::cout << "float : ";
    if ((val > std::numeric_limits<double>::max() || val < -std::numeric_limits<double>::max())
         && (val != -std::numeric_limits<double>::infinity() && val != std::numeric_limits<double>::infinity())) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if(val == static_cast<int>(val))
        std::cout << static_cast<float>(val) << ".0f" << std::endl;
    else
        std::cout << static_cast<float>(val) << "f" << std::endl;
}
void double_cast(double val)
{
    std::cout << "double : ";
    if(val == static_cast<int>(val))
        std::cout << val << ".0" << std::endl;
    else
        std::cout << val << std::endl;
}
    
void ScalarConverter::convert(std::string literal)
{
    double val = 1;
    char *endptr = NULL;
    if (pseudoliterals(literal))
    {
        if (literal == "-inff" || literal == "-inf")
            val = -std::numeric_limits<double>::infinity();
        else if (literal == "+inff" || literal == "+inf")
            val = std::numeric_limits<double>::infinity();
        else
            val = std::numeric_limits<double>::quiet_NaN();
    }
    else if (literal.length() == 1 && !isdigit(literal[0]))
        val = static_cast<double>(literal[0]);
    else
    {
        if (literal == "-nan" || literal == "-nanf")
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
        val = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0' && (*endptr != 'f' || *(endptr + 1) != '\0'))
        {
            std::cout << "Invalid literal" << std::endl;
            return;
        }
        else if (val > std::numeric_limits<double>::max() ||
            val < std::numeric_limits<double>::lowest())
        {
            std::cout << "value out of range" << std::endl;
            return;
        }
    }
    char_cast(val);
    int_cast(val);
    float_cast(val);
    double_cast(val); 
}
