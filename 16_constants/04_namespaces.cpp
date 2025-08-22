#include <iostream>

// if no of parameter were different and names were same then there was no problem
// no of parameter and names of both functions are same so compiler throws error unless we use namespaces

// error
/* int fun()
{
    std::cout<<"First"<<std::endl;
};

int fun()
{
    std::cout<<"Second"<<std::endl;
}; */

namespace first
{
int fun()
{
    std::cout<<"First"<<std::endl;
    return 0;
};
}

namespace second
{
    int fun()
{
    std::cout<<"Second"<<std::endl;
    return 0;
};
};

// ypu can use using namespace {name} ==> to by default use fun of that namespace
namespace third
{
    int fun()
{
    std::cout<<"Third"<<std::endl;
    return 0;
};
};

using namespace third;

int main()
{
    first::fun();
    second::fun();
    fun();

    return 0;
};