/*
 * This file is part of the Shiboken Python Binding Generator project.
 *
 * Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation. Please
 * review the following information to ensure the GNU Lesser General
 * Public License version 2.1 requirements will be met:
 * http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *
 * As a special exception to the GNU Lesser General Public License
 * version 2.1, the object code form of a "work that uses the Library"
 * may incorporate material from a header file that is part of the
 * Library.  You may distribute such object code under terms of your
 * choice, provided that the incorporated material (i) does not exceed
 * more than 5% of the total size of the Library; and (ii) is limited to
 * numerical parameters, data structure layouts, accessors, macros,
 * inline functions and templates.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef SIZE_H
#define SIZE_H

#include "libsamplemacros.h"

class LIBSAMPLE_API Size
{
public:
    Size(double width = 0.0, double height = 0.0) : m_width(width), m_height(height) {}
    ~Size() {}

    inline double width() { return m_width; }
    inline void setWidth(double width) { m_width = width; }
    inline double height() { return m_height; }
    inline void setHeight(double height) { m_height = height; }

    inline double calculateArea() const { return m_width * m_height; }

    // Comparison Operators
    inline bool operator==(const Size& other)
    {
        return m_width == other.m_width && m_height == other.m_height;
    }

    inline bool operator<(const Size& other)
    {
        return calculateArea() < other.calculateArea();
    }

    inline bool operator>(const Size& other)
    {
        // On some x86 hardware and compiler combinations, floating point
        // comparisons may fail due to a hardware bug. One workaround is to
        // simplify comparison expressions by putting partial results in
        // variables. See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=323#c109
        // for details.
        double a = calculateArea();
        double b = other.calculateArea();
        return a > b;
    }

    inline bool operator<=(const Size& other)
    {
        // See comments for operator>()
        double a = calculateArea();
        double b = other.calculateArea();
        return a <= b;
    }

    inline bool operator>=(const Size& other)
    {
        return calculateArea() >= other.calculateArea();
    }

    inline bool operator<(double area) { return calculateArea() < area; }
    inline bool operator>(double area) { return calculateArea() > area; }
    inline bool operator<=(double area) { return calculateArea() <= area; }
    inline bool operator>=(double area) { return calculateArea() >= area; }

    // Arithmetic Operators
    inline Size& operator+=(const Size& s)
    {
        m_width += s.m_width;
        m_height += s.m_height;
        return *this;
    }

    inline Size& operator-=(const Size& s)
    {
        m_width -= s.m_width;
        m_height -= s.m_height;
        return *this;
    }

    inline Size& operator*=(double mult)
    {
        m_width *= mult;
        m_height *= mult;
        return *this;
    }

    inline Size& operator/=(double div)
    {
        m_width /= div;
        m_height /= div;
        return *this;
    }

    // TODO: add ++size, size++, --size, size--

    // External operators
    friend inline bool operator!=(const Size&, const Size&);
    friend inline const Size operator+(const Size&, const Size&);
    friend inline const Size operator-(const Size&, const Size&);
    friend inline const Size operator*(const Size&, double);
    friend inline const Size operator*(double, const Size&);
    friend inline const Size operator/(const Size&, double);

    friend inline bool operator<(double, const Size&);
    friend inline bool operator>(double, const Size&);
    friend inline bool operator<=(double, const Size&);
    friend inline bool operator>=(double, const Size&);

    void show() const;

private:
    double m_width;
    double m_height;
};

// Comparison Operators
inline bool operator!=(const Size& s1, const Size& s2)
{
    return s1.m_width != s2.m_width || s1.m_height != s2.m_height;
}

inline bool operator<(double area, const Size& s)
{
    return area < s.calculateArea();
}

inline bool operator>(double area, const Size& s)
{
    return area > s.calculateArea();
}

inline bool operator<=(double area, const Size& s)
{
    return area <= s.calculateArea();
}

inline bool operator>=(double area, const Size& s)
{
    return area >= s.calculateArea();
}

// Arithmetic Operators
inline const Size operator+(const Size& s1, const Size& s2)
{
    return Size(s1.m_width + s2.m_width, s1.m_height + s2.m_height);
}

inline const Size operator-(const Size& s1, const Size& s2)
{
    return Size(s1.m_width - s2.m_width, s1.m_height - s2.m_height);
}

inline const Size operator*(const Size& s, double mult)
{
    return Size(s.m_width * mult, s.m_height * mult);
}

inline const Size operator*(double mult, const Size& s)
{
    return Size(s.m_width * mult, s.m_height * mult);
}

inline const Size operator/(const Size& s, double div)
{
    return Size(s.m_width / div, s.m_height / div);
}

#endif // SIZE_H

