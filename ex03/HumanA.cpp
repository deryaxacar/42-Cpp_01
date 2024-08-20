/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:12:59 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/20 17:13:01 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string newName, Weapon &newWeapon) : weapon(newWeapon)
{
    name = newName;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his: " << weapon.getType() << std::endl;
}