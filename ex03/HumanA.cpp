/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:12:59 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/23 18:16:58 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon) : weapon(newWeapon)
{
    name = newName;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his: " << weapon.getType() << std::endl;
}