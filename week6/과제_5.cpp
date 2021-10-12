#include <iostream>

bool funcA() {
    int c;
    std::cin >> c;
    if (c < 10) //Let's assume this is exception
        return false;

    return true;
}
int main() {
    try {
        if (!funcA()) throw std::out_of_range("Invalid input!!"); //c<
    }
    catch(std::out_of_range& e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }
   

    return 0;
}
