#include "System.h"

#include <iostream>

PrintStream::PrintStream() {
}

PrintStream::~PrintStream() {
}

void PrintStream::print(bool b)
{
    std::cout << (b ? "true" : "false");
}

void PrintStream::print(char c)
{
    std::cout << c;
}

void PrintStream::print(char* s)
{
    std::cout << s;
}

void PrintStream::print(double d)
{
    std::cout << d;
}

void PrintStream::print(float f)
{
    std::cout << f;
}

void PrintStream::print(int i)
{
    std::cout << i;
}

void PrintStream::print(long l)
{
    std::cout << l;
}

void PrintStream::print(String *s)
{
    std::cout << s->toString();
}

void PrintStream::println()
{
    std::cout << std::endl;
}

void PrintStream::println(bool b)
{
    std::cout << (b ? "true" : "false") << std::endl;
}

void PrintStream::println(char c)
{
    std::cout << c << std::endl;
}

void PrintStream::println(char* s)
{
    std::cout << s << std::endl;
}

void PrintStream::println(double d)
{
    std::cout << d << std::endl;
}

void PrintStream::println(float f)
{
    std::cout << f << std::endl;
}

void PrintStream::println(int i)
{
    std::cout << i << std::endl;
}

void PrintStream::println(long l)
{
    std::cout << l << std::endl;
}

void PrintStream::println(String *s)
{
    std::cout << s->toString() << std::endl;
}

void *System::in = nullptr;

PrintStream *System::out = new PrintStream();

System::System() {}

System::~System() {}

void delete_out()
{
    delete System::out;
}

const int result = std::atexit(delete_out);
