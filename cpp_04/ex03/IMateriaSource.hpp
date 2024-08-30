/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:40 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource {
public:
  virtual ~IMateriaSource(){};
  virtual void learnMateria(AMateria *m) = 0;
  virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif
