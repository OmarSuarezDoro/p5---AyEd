// AUTOR: Omar Suárez Doro
// FECHA: 02-05-2022
// EMAIL: alu0101483474@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 6
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
/**
 * @brief This method evaluate a data value in the polynomial
 * @param q : Data 
 * @return const int 
 */
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;
    if (isdigit(c)) {
      int i = c - '0';
      std::cout << " (es un dígito)\n" << "   Lo metemos en la pila..." << std::endl;
      this->stack_.push(i);
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return this->stack_.top();
}

/**
 * @brief This mehod operate with sign 
 * @param c : Signs
 */
template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'c' || c == 'l');
 
  int op1 = this->stack_.top();
  this->stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << op1 << std::endl;
  int op2;
  if (c != 'l' || c != 'c' || c != 'r') {
    op2 = this->stack_.top(); 
    this->stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << op2 << std::endl;
  } 
    
  
  int result;
  switch (c) {
    case '+': 
      result = op2 + op1;
    break;
    
    case '-': 
      result = op2 - op1;
    break;

    case '*':
      result = op2 * op1;
    break;

    case '/': 
      result = op2 / op1;
    break;

    case '^':
      result = pow(op2, op1);
    break;

    case 'r':
      result = sqrt(op1);
    break;

    case 'l':
      result = log2(op1);
    break;

    case 'c':
      result = op1 * op1;
    break;
  }

  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
  this->stack_.push(result);
}

 
#endif  // RPNT_H_
