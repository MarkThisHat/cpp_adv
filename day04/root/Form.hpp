/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:06:17 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 22:01:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

enum class	FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class	CourseFinished;
class	NeedMoreClassRoom;
class	NeedCourseCreation;
class	SubscriptionToCourse;

class	Form
{
	private:
		bool		_isSigned;
		FormType	_formType;

	public:
		Form(FormType p_formType) : _isSigned(false), _formType(p_formType) {}

		virtual void	execute() = 0;

		bool		isSigned() { return _isSigned; }
		FormType	getType() const { return _formType; }
};

#endif
