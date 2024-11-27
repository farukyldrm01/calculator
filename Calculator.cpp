#include <iostream>
#include <limits>
using namespace std;

int main() {
  char op;
  float num1, num2;
  char choice;

  do {
    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    
    if (op != '+' && op != '-' && op != '*' && op != '/') {
      cout << "Error! Invalid operator.\n";
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
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        break;
      case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        break;
      case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        break;
      case '/':
        if (num2 == 0) {
          cout << "Error! Division by zero is not allowed.\n";
        } else {
          cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
        break;
      default:
        cout << "Unexpected error.\n";
    }

     
    cout << "Do you want to perform another calculation? (y/n): ";
    cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  cout << "Goodbye!\n";
  return 0;
}