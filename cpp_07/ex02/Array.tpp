/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:47 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:48 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _length(0), _array(new T[this->_length]()) {
  std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n), _array(new T[this->_length]()) {
  std::cout << "Parametrized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &src)
    : _length(src._length), _array(new T[src._length]()) {
  std::cout << "Copy constructor called" << std::endl;
  for (unsigned int i(0); i < this->_length; ++i) {
    this->_array[i] = src._array[i];
  }
}

template <typename T> Array<T>::~Array() {
  std::cout << "Destructor called" << std::endl;
  delete[] this->_array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs) {
  std::cout << "Assignment operator called" << std::endl;
  if (this == &rhs)
    return *this;
  if (this->_length != rhs._length) {
    delete[] this->_array;
    this->_length = rhs._length;
    this->_array = new T[this->_length];
  }
  for (unsigned int i(0); i < this->_length; ++i) {
    this->_array[i] = rhs._array[i];
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= this->_length)
    throw std::out_of_range("Index out of bounds");
  return (this->_array[index]);
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= this->_length)
    throw std::out_of_range("Index out of bounds");
  return (this->_array[index]);
}

template <typename T> unsigned int Array<T>::size() const {
  return this->_length;
}

template <> void fillArray(Array<int> &arr) {
  int n(0);
  for (unsigned int i(0); i < arr.size(); ++i) {
    arr[i] = ++n;
  }
}

template <> void fillArray(Array<std::string> &arr) {
  int n(0);
  for (unsigned int i(0); i < arr.size(); ++i) {
    std::stringstream ss;
    std::string str;
    ss << ++n;
    ss >> str;
    arr[i] = "string_" + str;
  }
}

#endif