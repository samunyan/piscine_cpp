/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:57 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

public:
  Weapon(const std::string &type);
  ~Weapon();
  const std::string &getType() const;
  void setType(const std::string &type);

private:
  std::string _type;
};

#endif
