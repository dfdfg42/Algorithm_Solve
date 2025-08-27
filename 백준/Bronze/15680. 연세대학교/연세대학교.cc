#include <iostream>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;


    std::cin >> N;

    if (N == 0) {
        std::cout << "YONSEI" << std::endl;
    } else { 
        std::cout << "Leading the Way to the Future" << std::endl;
    }

    return 0;
}