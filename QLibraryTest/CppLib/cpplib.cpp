#include "cpplib.h"

CppLib::~CppLib()
{

}

TestLib::~TestLib()
{

}

int TestLib::add(int a, int b)
{
    return a+b;
}

int MyAdd(int a, int b)
{
    return a+b;
}

void *createCppLib()
{
    return new TestLib;
}
