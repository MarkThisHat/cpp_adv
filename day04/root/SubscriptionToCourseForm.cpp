/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:09:44 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 22:22:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::CourseSubscription(\
const std::string& cName, const std::string& sName) :
Form(FormType::CourseSubscription),
courseName(cName),
studentName(sName),
{}

void	SubscriptionToCourseForm::execute()
{
	std::cout << "Course Subscription Form for " << studentName;
	std::cout << " in course " << courseName;
	if (!isSigned())
	{
		std::cout << " is void." << std::endl;
			return ;
	}
	std::cout << " is approved."  << std::endl;
}
