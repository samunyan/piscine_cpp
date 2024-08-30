/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:20:18 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:20:19 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal {
public:
  Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &rhs);
  virtual ~Cat();
  virtual void makeSound() const;
  const Brain *getBrain() const;

private:
  Brain *_myBrain;
};

#endif
