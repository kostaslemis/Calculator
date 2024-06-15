#pragma once

#include <iostream>


class Function {
    private:
        /* data */
    public:
         Function(/* args */);
        ~Function();
        Function &operator=(const Function &Function);

        friend std::ostream &operator<<(std::ostream &os, const Function &function);
};
