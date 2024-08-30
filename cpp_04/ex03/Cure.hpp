/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:27 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &src);
  Cure &operator=(const Cure &rhs);
  virtual ~Cure();
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif
