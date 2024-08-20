/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:08 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/20 17:13:09 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string Name)
{
    name = Name;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with his: " << weapon->getType() << std::endl;
}