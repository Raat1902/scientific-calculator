#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double readDouble(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        double x{};
        std::cin >> x;

        if (!std::cin.fail()) {
            clearInput();
            return x;
        }

        std::cout << "Invalid input. Please enter a number.\n";
        clearInput();
    }
}

int readInt(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        int x{};
        std::cin >> x;

        if (!std::cin.fail()) {
            clearInput();
            return x;
        }

        std::cout << "Invalid input. Please enter a whole number.\n";
        clearInput();
    }
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) result *= static_cast<unsigned long long>(i);
    return result;
}

void printMenu() {
    std::cout << "=== Scientific Calculator (C++) ===\n";
    std::cout << "1.  Addition (+)\n";
    std::cout << "2.  Subtraction (-)\n";
    std::cout << "3.  Multiplication (*)\n";
    std::cout << "4.  Division (/)\n";
    std::cout << "5.  Power (x^y)\n";
    std::cout << "6.  Square Root (sqrt)\n";
    std::cout << "7.  Sine (sin)   [radians]\n";
    std::cout << "8.  Cosine (cos) [radians]\n";
    std::cout << "9.  Tangent (tan)[radians]\n";
    std::cout << "10. Log base 10 (log10)\n";
    std::cout << "11. Natural log (ln)\n";
    std::cout << "12. Factorial (n!)\n";
    std::cout << "13. Exit\n";
}
}  // namespace

int main() {
    std::cout << std::fixed << std::setprecision(10);

    while (true) {
        std::cout << "\n";
        printMenu();

        int choice = readInt("Enter choice (1-13): ");
        std::cout << "\n";

        if (choice == 13) {
            std::cout << "Exiting calculator.\n";
            return 0;
        }

        switch (choice) {
            case 1: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a + b) << "\n";
                break;
            }
            case 2: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a - b) << "\n";
                break;
            }
            case 3: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a * b) << "\n";
                break;
            }
            case 4: {
                double a = readDouble("Enter numerator: ");
                double b = readDouble("Enter denominator: ");
                if (b == 0.0) {
                    std::cout << "Error: Division by zero!\n";
                } else {
                    std::cout << "Result: " << (a / b) << "\n";
                }
                break;
            }
            case 5: {
                double base = readDouble("Enter base: ");
                double exp = readDouble("Enter exponent: ");
                std::cout << "Result: " << std::pow(base, exp) << "\n";
                break;
            }
            case 6: {
                double x = readDouble("Enter number: ");
                if (x < 0.0) {
                    std::cout << "Error: Cannot take square root of a negative number!\n";
                } else {
                    std::cout << "Result: " << std::sqrt(x) << "\n";
                }
                break;
            }
            case 7: {
                double r = readDouble("Enter angle in radians: ");
                std::cout << "Result: " << std::sin(r) << "\n";
                break;
            }
            case 8: {
                double r = readDouble("Enter angle in radians: ");
                std::cout << "Result: " << std::cos(r) << "\n";
                break;
            }
            case 9: {
                double r = readDouble("Enter angle in radians: ");
                std::cout << "Result: " << std::tan(r) << "\n";
                break;
            }
            case 10: {
                double x = readDouble("Enter number (> 0): ");
                if (x <= 0.0) {
                    std::cout << "Error: log10 is undefined for non-positive numbers!\n";
                } else {
                    std::cout << "Result: " << std::log10(x) << "\n";
                }
                break;
            }
            case 11: {
                double x = readDouble("Enter number (> 0): ");
                if (x <= 0.0) {
                    std::cout << "Error: ln is undefined for non-positive numbers!\n";
                } else {
                    std::cout << "Result: " << std::log(x) << "\n";
                }
                break;
            }
            case 12: {
                int n = readInt("Enter n (0 to 20): ");
                if (n < 0) {
                    std::cout << "Error: Factorial is not defined for negative numbers!\n";
                } else if (n > 20) {
                    std::cout << "Error: Too large for 64-bit factorial. Use 0..20.\n";
                } else {
                    std::cout << "Result: " << factorial(n) << "\n";
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}