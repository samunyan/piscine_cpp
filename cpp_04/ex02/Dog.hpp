/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:20:23 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:20:24 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {
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
