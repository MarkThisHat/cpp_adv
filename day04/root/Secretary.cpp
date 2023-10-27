/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:09:04 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 19:37:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Secretary.hpp"

std::unique_ptr<Form>	Secretary::createForm(FormType p_formType)
{
	switch(p_formType)
	{
		case FormType::CourseFinished:
			return std::make_unique CourseFinishedForm();
		case FormType::NeedMoreClassRoom:
			return std::make_unique NeedMoreClassRoomForm();
		case FormType::NeedCourseCreation:
			return std::make_unique NeedCourseCreationForm();
		case FormType::SubscriptionToCourse:
			return std::make_unique SubscriptionToCourseForm();
		default:
			return nullptr;
	}
}
