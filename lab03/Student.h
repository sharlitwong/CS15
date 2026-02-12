/*
 * Student.h
 * CS15 —— Lab 03: make, diff
 *
 * This file contains a representation of a Student object. Each Student has a
 * name and a grade.
 *
 */

#ifndef STUDENT
#define STUDENT

#include <string>

struct Student {
    std::string name;
    int         grade;
};

#endif
