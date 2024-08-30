/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:59 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:20:00 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &rhs);
  virtual ~Dog();
  virtual void makeSound() const;
  const Brain *getBrain() const;

private:
  Brain *_myBrain;
};

#endif
