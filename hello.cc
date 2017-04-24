#include <iostream>

class HelloWorld
{
public:
  HelloWorld()
  {
    std::cout << "Hello from dlopen()" << std::endl;
  }
};


static HelloWorld hello;
