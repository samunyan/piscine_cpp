/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:23 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:24 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
public:
  Character();
  Character(const std::string &name);
  Character(const Character &src);
  Character &operator=(const Character &rhs);
  virtual ~Character();
  const std::string &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
  const AMateria *getMateriaAt(int idx) const;

private:
  AMateria *_slots[4];
  AMateria *_unequipped[20];
  std::string _name;
};

#endif