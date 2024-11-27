#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

int main() {
  char op;
  float num1, num2, result = 0;
  char choice;

  do {
    cout << "Advanced Calculator\n";
    cout << "Available operations:\n";
    cout << " + : Addition\n";
    cout << " - : Subtraction\n";
    cout << " * : Multiplication\n";
    cout << " / : Division\n";
    cout << " % : Modulus (integers only)\n";
    cout << " ^ : Power\n";
    cout << " r : Square root (single operand)\n";
    cout << "Enter 'q' to quit.\n";

    cout << "Enter operator: ";
    cin >> op;

    if (op == 'q' || op == 'Q') {
      cout << "Goodbye!\n";
      break;
    }

    if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^' && op != 'r') {
      cout << "Error! Invalid operator.\n";
      continue;
    }

    if (op == 'r') {
      cout << "Enter a number: ";
      while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a numeric value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      if (num1 < 0) {
        cout << "Error! Cannot calculate square root of a negative number.\n";
      } else {
        result = sqrt(num1);
        cout << "sqrt(" << num1 << ") = " << result << endl;
      }
      continue;
    }

    cout << "Enter two operands: ";
    while (!(cin >> num1 >> num2)) {
      cout << "Invalid input. Please enter numeric values: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (op) {
      case '+':
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
        break;
      case '-':
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
        break;
      case '*':
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
        break;
      case '/':
        if (num2 == 0) {
          cout << "Error! Division by zero is not allowed.\n";
        } else {
          result = num1 / num2;
          cout << num1 << " / " << num2 << " = " << result << endl;
        }
        break;
      case '%':
        if (static_cast<int>(num2) == 0) {
          cout << "Error! Division by zero is not allowed.\n";
        } else {
          result = static_cast<int>(num1) % static_cast<int>(num2);
          cout << static_cast<int>(num1) << " % " << static_cast<int>(num2) << " = " << result << endl;
        }
        break;
      case '^':
        result = pow(num1, num2);
        cout << num1 << " ^ " << num2 << " = " << result << endl;
        break;
      default:
        cout << "Unexpected error.\n";
    }

    cout << "Do you want to perform another calculation? (y/n): ";
    cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  cout << "Görüşürüz!\n";
  return 0;
}
