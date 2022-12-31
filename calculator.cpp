#include <iostream>
int main(){
  int num1, num2;
  char op;
  std::cout << "enter a number then an operation then a number : " << endl;
  cin >> num1 >> op >> num2;
  if(op == '+')
    std::cout << num1 + num2;
  else if(op == '-')
    std::cout << num1 - num2;
  else if(op == '*')
    std::cout << num1 * num2;
  else if(op == '/')
  {
    if(num2)
      std::cout << num1 / num2;
    else
      std::cout << "num2 can not be 0";
  }
  else
    std::cout << "unknown operation";
  
  return 0;  
}
