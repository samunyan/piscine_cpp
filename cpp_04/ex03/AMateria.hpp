/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:17 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:18 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria {
public:
  AMateria();
  AMateria(const AMateria &src);
  AMateria(const std::string &type);
  AMateria &operator=(const AMateria &rhs);
  virtual ~AMateria();
  const std::string &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string _type;
};

#endif
