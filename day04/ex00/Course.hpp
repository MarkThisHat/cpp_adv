/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:02:20 by maalexan          #+#    #+#             */
/*   Updated: 2023/10/25 23:15:23 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COURSE_HPP
# define COURSE_HPP

class Course
{
	private:
		std::string				_name;
		Professor*				_responsable;
		std::vector<Student*>	_students;
		int 					_numberOfClassToGraduate;
		int						_maximumNumberOfStudent;

	public:
		Course(std::string p_name);
		void	assign(Professor* p_professor);
		void	subscribe(Student* p_student);
};

#endif