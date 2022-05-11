// AUTOR: Omar Suárez Doro
// FECHA: 02-05-2022
// EMAIL: alu0101483474@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  int number_of_pairs() const;
  int size_of_stack() const;
  int sum_of_elements() const;
  int max() const;



  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


// operaciones
/**
 * @brief This method push a data into a stack
 * @param dato : Data
 */
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

/**
 * @brief This method delete the top of a stack 
 */
template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

/**
 * @brief This method return the top of the stack
 * @return const T& 
 */
template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

/**
 * @brief This method check if a stack is empty or not. 
 * @return true 
 * @return false 
 */
template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S

/**
 * @brief This method allow user to print a stack on the screen 
 * @tparam T 
 * @param os 
 * @return std::ostream& 
 */
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

/*
Métodos a implementar - Práctica 5 AyED:
  -PILA-
    - Método que te diga el número de pares que tiene una pila
    - Método que te diga el número de impares que tiene una pila
    - Método que te diga el tamaño de una pila
    - Método que te sume todos los elementos de una pila
    - Método que te diga el valor más alto dentro de una pila
    - Método que te diga el valor más bajo dentro de una pila
    - Método que te separe en dos pilas distintas, los números mayores y menores dado un parámetro de entrada
  */
template <class T>
int stack_l_t<T>::number_of_pairs() const {
  stack_l_t<int>* aux_stack = new stack_l_t<int>;
  int counter_of_pairs{0};
  while (!empty()) {
    if (top() % 2 == 0) {counter_of_pairs++};
    aux_stack->push(top());
    pop();
  }
  while (!empty()) {
    push(aux_stack->top());
    aux_stack->pop();
  }
  return counter_of_pairs;
}

template <class T>
int stack_l_t<T>::size_of_stack() const {
  return l_.get_size();
}

template <class T>
int stack_l_t<T>::sum_of_elements() const {
  stack_l_t<int>* aux_stack = new stack_l_t<int>;
  int counter{0};
  while (!empty()) {
    counter += top();
    aux_stack->push(top());
    pop();
  }
  while (!empty()) {
    push(aux_stack->top());
    aux_stack->pop();
  }
  return counter;
}


template <class T>
int stack_l_t<T>::max() const {
  stack_l_t<int>* aux_stack = new stack_l_t<int>;
  int max = top();
  aux_stack = this*;
  while (!aux_stacl->empty()) {
    if (aux_stack->top() > max) {max = aux_stack->top();}
    aux_stack->pop();
  }
  return max;
}



#endif  // STACKL_H_
