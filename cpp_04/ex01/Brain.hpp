/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:29 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:30 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>
#include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &src);
  Brain &operator=(const Brain &rhs);
  virtual ~Brain();
  const std::string *getIdeas() const;

private:
  std::string *_ideas;
};

std::ostream &operator<<(std::ostream &o, const Brain &rhs);

#endif
