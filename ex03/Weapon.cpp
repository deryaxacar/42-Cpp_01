/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:32 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/23 18:17:25 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

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
