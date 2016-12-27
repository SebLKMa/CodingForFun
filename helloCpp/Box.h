#pragma once

class Box
{
public:
	Box(double length, double width, double height) : m_Length{ length }, m_Width{ width }, m_Height{ height } {}
	Box() = default;

	double volume() const { return m_Length*m_Width*m_Height; }

protected:
	double m_Length{1.0};
	double m_Width{1.0};
	double m_Height{1.0};
};
