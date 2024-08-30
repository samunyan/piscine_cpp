/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:52:05 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/12 18:52:06 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
public:
  AAnimal();
  AAnimal(const std::string &type);
  AAnimal(const AAnimal &src);
  AAnimal &operator=(const AAnimal &rhs);
  virtual ~AAnimal();
  virtual void makeSound() const = 0;
  std::string getType() const;

protected:
  std::string _type;
};

std::ostream &operator<<(std::ostream &o, const AAnimal &rhs);

#endif
