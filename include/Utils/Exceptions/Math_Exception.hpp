/** 
 *  \file Exceptions.hpp
 *  
 *  \brief Header for Various Exceptions.
 *
 *  This supports various Exceptions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#ifndef MATH_EXCEPTION_HPP_
#define MATH_EXCEPTION_HPP_

#include <string>
#include <exception>

namespace Game 
{

namespace Math
{

namespace Exception
{

class DivisionByZero : public std::exception
{

public:
    DivisionByZero(const char* p_message) : message(p_message) {};
    
    const char* what() const noexcept override 
    {
        return message;
    }
    
    ~DivisionByZero()
    {
        delete message;
    }
    
private:
    const char* message;
};

class InvalidRoundFlag : public std::exception
{

public:
    InvalidRoundFlag(const char* p_message) : message(p_message) {};
    
    const char* what() const noexcept override
    {
        return message;
    }
    
    ~InvalidRoundFlag()
    {
        delete message;
    }
    
private:
    const char* message;
};

} // namespace Exception 

} // namespace Math

} // namespace Game

#endif // EXCEPTIONS_HPP_
