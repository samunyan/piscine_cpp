/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:29 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:30 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
#define INPUT_HPP

#include "colors.hpp"
#include <iostream>
#include <string>

enum field_type { alpha, numeric };

bool getInput(const std::string &question, int field_type, std::string &input);

#endif