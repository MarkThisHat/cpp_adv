/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:47:33 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/27 10:34:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"

int	main(void)
{
	Secretary sec("Secretary");
	Headmaster hm("Albus", sec);

	auto formFinA = sec.createForm(FormType::CourseFinished, "Defense Against the Dark Arts", "Harry Potter", 95, 2023);
	hm.receiveForm(std::move(formFinA));
	hm.signLastForm();

	auto formFinB = sec.createForm(FormType::CourseFinished, "Defense Against the Dark Arts", "Draco Malfoy", 99, 2023);
	hm.receiveForm(std::move(formFinB));

	auto formSubA = sec.createForm(FormType::SubscriptionToCourse, "Hermione Granger", "Quantum Charms", 0, 0);
	hm.receiveForm(std::move(formSubA));
	hm.signLastForm();

	auto formSubB = sec.createForm(FormType::SubscriptionToCourse, "Ronald Weasley", "Quantum Charms", 0, 0);
	hm.dispatchAllForms();


	return 0;
}
