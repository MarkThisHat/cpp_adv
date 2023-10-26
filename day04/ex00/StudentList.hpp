/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StudentList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:09:34 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 11:50:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENTLIST_HPP
# define STUDENTLIST_HPP

#include "Singleton.hpp"

class	StudentList : public Singleton<StudentList, Student*>
{
    friend class Singleton<StudentList, Student*>;
};

#endif
