/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:50 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:51 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &src);
  MateriaSource &operator=(const MateriaSource &rhs);
  virtual ~MateriaSource();
  virtual void learnMateria(AMateria *m);
  virtual AMateria *createMateria(const std::string &type);

private:
  AMateria *_slots[4];
};

#endif
