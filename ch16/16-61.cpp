#include <iostream>
#include <memory>
#include <string>

namespace custom //to differ from std::make_shared
{
    template <typename T, typename ... Args>
     std::shared_ptr<T> make_shared(Args&&... args) 
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

struct someStruct
{
    someStruct(std::string s) : mem_string(s){ }
    std::string mem_string;
};

int main()
{
    auto num = custom::make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = custom::make_shared<std::string>(10, 'c');
    std::cout << *str << std::endl;

    auto struct_mem = custom::make_shared<someStruct>("test");
    std::cout << struct_mem->mem_string << std::endl;
    
    return 0;
}