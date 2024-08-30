/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:35 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &src);
  Ice &operator=(const Ice &rhs);
  virtual ~Ice();
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif
