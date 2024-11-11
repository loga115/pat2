#include <iostream>
#include <string>

bool isCyclicRotation(const std::string& T, const std::string& T_prime) {
    if (T.length() != T_prime.length()) {
        return false;
    }
    std::string concatenated = T + T;
    return concatenated.find(T_prime) != std::string::npos;
}

int main() {
    std::string T = "car";
    std::string T_prime = "arc";

    if (isCyclicRotation(T, T_prime)) {
        std::cout << T_prime << " is a cyclic rotation of " << T << std::endl;
    } else {
        std::cout << T_prime << " is not a cyclic rotation of " << T << std::endl;
    }

    return 0;
}