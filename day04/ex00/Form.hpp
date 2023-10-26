/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:06:17 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 23:19:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

enum class	FormType
{
	CourseFinished
	NeedMoreClassRoom
	NeedCourseCreation
	SubscriptionToCourse
};

class	Form
{
	private:
		FormType	_formType;

	public:
		~Form();
		Form(FormType p_formType)
		{

		}

	virtual void	execute() = 0;
};

#endif
