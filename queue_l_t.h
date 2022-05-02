// AUTOR: Omar Suárez Doro
// FECHA: 02-05-2022
// EMAIL: alu0101483474@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 6
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}
/**
 * @brief This method return the size of the queque
 * @return The size
 */
template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

/**
 * @brief This method return the size of the queque
 * @param dato : Is the data that will be pushed
 */
template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

/**
 * @brief This method delete an element from the queue
 */
template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

/**
 * @brief This method return the last element of the list
 * @return const T& 
 */
template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

/**
 * @brief This method return the first element of the list
 * @return const T& 
 */
template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 /**
  * @brief This methods allow user to print queue on the screen
  * @param os output stream
  * @return std::ostream& 
  */
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}


#endif  // QUEUE_H_
