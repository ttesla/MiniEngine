#ifndef VECTOR2_H
#define VECTOR2_H

namespace MiniEngine
{
    /// <summary>
    /// A Basic Vector2 class
    /// </summary>
    class Vector2
    {
    public:
        float X;
        float Y;

        Vector2();
        Vector2(float x, float y);
        ~Vector2();

        void Set(float x, float y);
        void Normalize();              // Normalize this vector
        Vector2 GetNormalized() const; // Get a normalized copy of this vector
        float Length() const;
        float SquaredLength() const;

        // Operator overloads
        inline const Vector2 operator - () const { return Vector2(-X, -Y); }
        inline const Vector2 operator - (const Vector2& vec) const { return Vector2(X - vec.X, Y - vec.Y); }
        inline const Vector2 operator + (const Vector2& vec) const { return Vector2(X + vec.X, Y + vec.Y); }
        inline const Vector2 operator * (float fact) const { return Vector2(X * fact, Y * fact); }
        inline const Vector2 operator / (float fact) const { float xfact = 1.0f / fact; return Vector2(X * xfact, Y * xfact); }
        inline Vector2& operator += (const Vector2& vec) { X += vec.X; Y += vec.Y; return *this; }
        inline Vector2& operator -= (const Vector2& vec) { X -= vec.X; Y -= vec.Y; return *this; }
        inline Vector2& operator *= (float fact) { X *= fact; Y *= fact; return *this; }

        // Other static helper functions
        static float Distance(const Vector2& a, const Vector2& b);
        static float DistanceSquared(const Vector2& a, const Vector2& b);
        static float Dot(const Vector2& a, const Vector2& b);

    private:

    };

}


#endif // VECTOR2_H

