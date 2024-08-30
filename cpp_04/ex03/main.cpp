/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:33:55 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:43 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  {
    std::cout << "INIT WITH ALLOC:\n";
    AMateria *iceObj(new Ice());
    AMateria *cureObj(new Cure());
    std::cout << "iceObj has type " + iceObj->getType() << std::endl;
    std::cout << "cureObj has type " + cureObj->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "CLONE:\n";
    AMateria *iceClone = iceObj->clone();
    AMateria *cureClone = cureObj->clone();
    std::cout << "iceClone has type " + iceClone->getType() << std::endl;
    std::cout << "cureClone has type " + cureClone->getType() << std::endl;
    std::cout << std::endl;

    delete iceObj;
    delete cureObj;
    delete iceClone;
    delete cureClone;
  }
  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // me->equip(tmp);

    AMateria *ice(new Ice());
    src->learnMateria(ice);
    src->learnMateria(ice);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(0, *bob);
    // me->unequip(0);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
  }
  return 0;
}
