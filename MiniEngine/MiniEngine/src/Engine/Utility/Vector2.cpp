#include "Vector2.h"

#include <cmath>

namespace MiniEngine
{
    Vector2::Vector2() : X(0), Y(0) 
    {
    }
    
    Vector2::Vector2(float x, float y) : X(x), Y(y) 
    {
    }
    
    Vector2::~Vector2()
    {
    }

    void Vector2::Set(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Vector2::Normalize()
    {
        if(Length() > 0)
        {
            float len = Length();
            X /= len; Y /= len;
        }
    }

    Vector2 Vector2::GetNormalized() const 
    {
        Vector2 a = *this;
        a.Normalize();
        
        return a;
    }

    float Vector2::Length() const
    {
        return sqrt(X * X + Y * Y);
    }

    float Vector2::SquaredLength() const
    {
        return (X * X + Y * Y);
    }

    float Vector2::Distance(const Vector2& a, const Vector2& b)
    {
        Vector2 c = a - b;
        return c.Length();
    }

    float Vector2::DistanceSquared(const Vector2& a, const Vector2& b)
    {
        Vector2 c = a - b;
        return c.SquaredLength();
    }

    float Vector2::Dot(const Vector2& a, const Vector2& b)
    {
        return a.X * b.X + a.Y * b.Y;
    }
}
