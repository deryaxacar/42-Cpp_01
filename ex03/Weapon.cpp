/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:32 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/20 17:13:33 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string Type)
{
    type = Type;
}

void Weapon::setType(std::string Type)
{
    type = Type;
}

const std::string &Weapon::getType() const
{
    return (type);
}
