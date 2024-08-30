/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:52:05 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/12 18:52:06 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &src);
  Animal &operator=(const Animal &rhs);
  virtual ~Animal();
  virtual void makeSound() const;
  std::string getType() const;

protected:
  std::string _type;
};

std::ostream &operator<<(std::ostream &o, const Animal &rhs);

#endif
