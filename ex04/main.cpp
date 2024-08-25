/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:13:45 by deryacar          #+#    #+#             */
/*   Updated: 2024/08/23 18:13:27 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "*** You must enter 4 arguments." << std::endl ;
        return 0;
    }
    
    std::ifstream inputFile(av[1]);
    if(!inputFile)
    {
        std::cout << "*** Entered file cannot open." << std::endl;
        return 0;
    }
    
    std::string s1 = av[2];
    std::string s2 = av[3];
    if(s1 == s2)
    {
        std::cout << "*** Are u kidding me? Please enter different word or letter." << std::endl;
        return 0;
    }
    if(inputFile.is_open())
    {
        std::string line;
        std::string r_file = av[1];
        r_file += ".replace";
        std::ofstream replace_file(r_file);
        if (!replace_file)
        {
            std::cout << "*** Cannot create replace file." << std::endl;
            return 0;
        }
        while(std::getline(inputFile, line))
        {
            size_t found = line.find(s1);
            while(found != std::string::npos)
            {
                line.erase(found, s1.length());
                line.insert(found, s2);
                found = line.find(s1);
            }
            replace_file << line << std::endl;
        }
        replace_file.close();
        inputFile.close();
    }
    return 0;
}
