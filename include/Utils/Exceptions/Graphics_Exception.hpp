/** 
 *  \file Graphics_Exception.hpp
 *  
 *  \brief Header for Various Exceptions.
 *
 *  This supports various Exceptions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#ifndef GRAPHICS_EXCEPTION_HPP_
#define GRAPHICS_EXCEPTION_HPP_

#include <string>
#include <exception>

namespace Game 
{

namespace Graphics
{

namespace Exception
{

class WindowCreationFailed : public std::exception
{

public:
    WindowCreationFailed(const char* p_message) : message(p_message) {};
    
    const char* what() const noexcept override 
    {
        return message;
    }
    
    ~WindowCreationFailed()
    {
        delete message;
    }
    
private:
    const char* message;
};

class QueryingDisplayModeFailed : public std::exception
{

public:
    QueryingDisplayModeFailed(const char* p_message) : message(p_message) {};
    
    const char* what() const noexcept override 
    {
        return message;
    }
    
    ~QueryingDisplayModeFailed()
    {
        delete message;
    }
    
private:
    const char* message;
};

} // namespace Exception 

} // namespace Graphics

} // namespace Game

#endif // GRAPHICS_EXCEPTION_HPP_
