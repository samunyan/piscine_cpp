/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:15 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:16 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  virtual ~WrongAnimal();
  void makeSound() const;
  std::string getType() const;

protected:
  std::string _type;
};

std::ostream &operator<<(std::ostream &o, const WrongAnimal &rhs);

#endif
