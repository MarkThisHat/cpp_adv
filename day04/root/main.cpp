/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:47:33 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/26 23:48:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"

int main() {
    Secretary sec("Secretary");
    Headmaster hm("Albus", sec);

    // Create a CourseFinished form
    auto form = sec.createForm(FormType::CourseFinished, "Math101", "John Doe", 95, 2023);

    // Headmaster receives the form


hm.receiveForm(std::move(form));
hm.signLastForm();
hm.dispatchLastForm();


    return 0;
}
