#pragma once
#include <iostream>
#include <iomanip>

class Box
{
public:
	Box(double length, double width, double height) : m_Length{ length }, m_Width{ width }, m_Height{ height } {}
	Box() = default;

	// copy ctor
	Box(const Box& box) : m_Length{ box.m_Length }, m_Width{ box.m_Width }, m_Height{ box.m_Height } {}

	double volume() const { return m_Length*m_Width*m_Height; }

	int compare(const Box& box)
	{
		if (volume() < box.volume()) return -1;
		if (volume() == box.volume()) return 0;
		return 1;
	}

	void listBox()
	{
		std::cout << " Box(" << std::setw(2) << m_Length << ","
				<< std::setw(2) << m_Width << ","
				<< std::setw(2) << m_Height << ")";
	}

protected:
	double m_Length{1.0};
	double m_Width{1.0};
	double m_Height{1.0};
};
