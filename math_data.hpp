#ifndef MATH_DATA
#define MATH_DATA

#include <cassert>
#include <cmath>

#include "typedefs.hpp"

const float PI = 3.141592f, DEGREES = 180.f;

#define DEGREES(Radians) (Radians * (180.f / PI));
#define RADIANS(Degrees) (Degrees * (PI / 180.f))

union v2;
union v3;
union v4;

union v2s;
union v3s;
union v4s;

union v2u;
union v3u;
union v4u;

union v2
{
    struct
    {
        float x, y;
    };

    float E[2];
};

union v2u
{
    struct
    {
        u32 x, y;
    };

    u32 E[2];
};

union v2s
{
    struct
    {
        s32 x, y;
    };

    struct
    {
        s32 w, h;
    };

    s32 E[2];
};

union v3
{
    struct
    {
        float x, y, z;
    };

    struct
    {
        float r, g, b;
    };

    float E[3];
};

union v4
{
    struct
    {
        float x, y, z, w;
    };

    struct
    {
        float r, g, b, a;
    };

    float E[4];
};

union v4u
{
    struct
    {
        u8 x, y, z, w;
    };

    struct
    {
        u8 r, g, b, a;
    };

    u8 E[4];
};

// v2[s|u] operators
v2 operator+ (v2 a, v2 b)
{
    v2 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

v2 operator- (v2 a, v2 b)
{
    v2 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

v2 operator* (v2 a, v2 b)
{
    v2 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;

    return result;
}

v2 operator/ (v2 a, v2 b)
{
    v2 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;

    return result;
}

v2 operator+ (v2 a, float v)
{
    v2 result;

    result.x = a.x + v;
    result.y = a.y + v;

    return result;
}

v2 operator- (v2 a, float v)
{
    v2 result;

    result.x = a.x - v;
    result.y = a.y - v;

    return result;
}

v2 operator* (v2 a, float v)
{
    v2 result;

    result.x = a.x * v;
    result.y = a.y * v;

    return result;
}

v2 operator/ (v2 a, float v)
{
    v2 result;

    result.x = a.x / v;
    result.y = a.y / v;

    return result;
}

float length (v2 v)
{
    return sqrt ((v.x * v.x) + (v.y * v.y));
}

v2 normalize (v2 v)
{
    return v / length (v);
}

v2s operator+ (v2s a, v2s b)
{
    v2s result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

v2s operator- (v2s a, v2s b)
{
    v2s result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

v2s operator* (v2s a, v2s b)
{
    v2s result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;

    return result;
}

v2s operator/ (v2s a, v2s b)
{
    v2s result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;

    return result;
}

v2s operator+ (v2s a, float v)
{
    v2s result;

    result.x = a.x + v;
    result.y = a.y + v;

    return result;
}

v2s operator- (v2s a, float v)
{
    v2s result;

    result.x = a.x - v;
    result.y = a.y - v;

    return result;
}

v2s operator* (v2s a, float v)
{
    v2s result;

    result.x = a.x * v;
    result.y = a.y * v;

    return result;
}

v2s operator/ (v2s a, float v)
{
    v2s result;

    result.x = a.x / v;
    result.y = a.y / v;

    return result;
}

bool operator== (v2s a, v2s b)
{
    return (a.x == b.x && a.y == b.y) ? true : false;
}

// v3[s|u] operators
v3 operator+ (v3 a, v3 b)
{
    v3 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

v3 operator- (v3 a, v3 b)
{
    v3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

v3 operator* (v3 a, v3 b)
{
    v3 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;

    return result;
}

v3 operator/ (v3 a, v3 b)
{
    v3 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;

    return result;
}

v3 operator+ (v3 a, float v)
{
    v3 result;

    result.x = a.x + v;
    result.y = a.y + v;
    result.z = a.z + v;

    return result;
}

v3 operator- (v3 a, float v)
{
    v3 result;

    result.x = a.x - v;
    result.y = a.y - v;
    result.z = a.z - v;

    return result;
}

v3 operator* (v3 a, float v)
{
    v3 result;

    result.x = a.x * v;
    result.y = a.y * v;
    result.z = a.z * v;

    return result;
}

v3 operator/ (v3 a, float v)
{
    v3 result;

    result.x = a.x / v;
    result.y = a.y / v;
    result.z = a.z / v;

    return result;
}

float length (v3 v)
{
    return sqrt ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

v3 normalize (v3 v)
{
    return v / length (v);
}

// v4[s|u] operators
v4 operator+ (v4 a, v4 b)
{
    v4 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;

    return result;
}

v4 operator- (v4 a, v4 b)
{
    v4 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;

    return result;
}

v4 operator* (v4 a, v4 b)
{
    v4 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    result.w = a.w * b.w;

    return result;
}

v4 operator/ (v4 a, v4 b)
{
    v4 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    result.w = a.w / b.w;

    return result;
}

// v4[s|u] operators
v4u operator+ (v4u a, v4u b)
{
    v4u result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;

    return result;
}

v4u operator- (v4u a, v4u b)
{
    v4u result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;

    return result;
}

v4u operator* (v4u a, v4u b)
{
    v4u result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    result.w = a.w * b.w;

    return result;
}

v4u operator/ (v4u a, v4u b)
{
    v4u result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    result.w = a.w / b.w;

    return result;
}

inline v2 operator- (v2 a, v3 b)
{
    return v2 { a.x - b.x, a.y - b.y };
}

struct mat4
{
    float rows[4][4];

    float *operator[] (int i)
    {
        return rows[i];
    }
};

mat4 identity ()
{
    return {
        {
            { 1, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 1 },
        },
    };
}

mat4 zeroMat4 ()
{
    return {
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
        },
    };
}

void identity (mat4 *mat)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat->rows[i][j] = (i == j) ? 1 : 0;
}

void copy (float in[4][4], float out[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            out[i][j] = in[i][j];
}

mat4 operator* (mat4 m1, mat4 m2)
{
    mat4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float val = 0;

            for (int k = 0; k < 4; k++)
            {
                val += (m1[i][k] * m2[k][j]);
            }

            result[i][j] = val;
        }
    }

    return result;
}

void translate (mat4 &matrix, v2 pos)
{
    mat4 trans_matrix = identity ();

    // {1, 0, 0, pos.x}
    // {0, 1, 0, pos.y}
    // {0, 0, 1, 0    }
    // {0, 0, 0, 1    }

    trans_matrix[0][3] = pos.x;
    trans_matrix[1][3] = pos.y;

    matrix = matrix * trans_matrix;
}

void scale (mat4 &matrix, v2 size)
{
    mat4 scale_matrix = identity ();

    // {size.x, 0,      0, 0}
    // {0,      size.y, 0, 0}
    // {0,      0,      1, 0}
    // {0,      0,      0, 1}

    scale_matrix[0][0] = size.x;
    scale_matrix[1][1] = size.y;

    matrix = matrix * scale_matrix;
}

void rotateZ (mat4 &matrix, float angle)
{
    // {size.x, 0,      0, 0}
    // {0,      size.y, 0, 0}
    // {0,      0,      1, 0}
    // {0,      0,      0, 1}

    angle = angle * (3.14159f / 180.f);

    mat4 rotationMatrix = identity ();

    rotationMatrix[0][0] = cos (angle);
    rotationMatrix[0][1] = -sin (angle);

    rotationMatrix[1][0] = sin (angle);
    rotationMatrix[1][1] = cos (angle);

    matrix = matrix * rotationMatrix;
}

void rotateY (mat4 &matrix, float angle)
{
    // {size.x, 0,      0, 0}
    // {0,      size.y, 0, 0}
    // {0,      0,      1, 0}
    // {0,      0,      0, 1}

    angle = angle * (3.14159f / 180.f);

    mat4 rotationMatrix = identity ();

    rotationMatrix[0][0] = cos (angle);
    rotationMatrix[0][2] = -sin (angle);

    rotationMatrix[2][0] = -sin (angle);
    rotationMatrix[2][2] = cos (angle);

    matrix = matrix * rotationMatrix;
}

void rotateX (mat4 &matrix, float angle)
{
    // {size.x, 0,      0, 0}
    // {0,      size.y, 0, 0}
    // {0,      0,      1, 0}
    // {0,      0,      0, 1}

    angle = angle * (3.14159f / 180.f);

    mat4 rotationMatrix = identity ();

    rotationMatrix[1][1] = cos (angle);
    rotationMatrix[1][2] = -sin (angle);

    rotationMatrix[2][1] = sin (angle);
    rotationMatrix[2][2] = cos (angle);

    matrix = matrix * rotationMatrix;
}

void translate (mat4 &matrix, v3 pos)
{
    mat4 transMatrix = identity ();

    // {1, 0, 0, pos.x}
    // {0, 1, 0, pos.y}
    // {0, 0, 1, pos.z}
    // {0, 0, 0, 1    }

    transMatrix[0][3] = pos.x;
    transMatrix[1][3] = pos.y;
    transMatrix[2][3] = pos.z;

    matrix = matrix * transMatrix;
}

void scale (mat4 &matrix, v3 size)
{
    mat4 scaleMatrix = identity ();

    // {size.x, 0,      0,      0}
    // {0,      size.y, 0,      0}
    // {0,      0,      size.z, 0}
    // {0,      0,      0,      1}

    scaleMatrix[0][0] = size.x;
    scaleMatrix[1][1] = size.y;
    scaleMatrix[2][2] = size.z;

    matrix = matrix * scaleMatrix;
}

inline mat4 ortho (float W, float H)
{
    float r = W, t = 0;
    float l = 0, b = H;
    float f = 1.0f, n = -1.0f;

    mat4 matrix = identity ();

    matrix[0][0] = 2.f / (r - l);
    matrix[0][3] = -((r + l) / (r - l));

    matrix[1][1] = 2.f / (t - b);
    matrix[1][3] = -((t + b) / (t - b));

    matrix[2][2] = -2.f / (f - n);
    matrix[2][3] = -((f + n) / (f - n));

    return matrix;
}

// compute screen coordinates first -- gotta re-read about this
void gluPerspective (const float &angleOfView, const float &imageAspectRatio,
                     const float &n, const float &f, float &b, float &t,
                     float &l, float &r)
{
    float scale = tan (angleOfView * 0.5 * M_PI / 180) * n;
    r = imageAspectRatio * scale, l = -r;
    t = scale, b = -t;
}

inline mat4 perspective (float W, float H)
{
    float r, t, l, b;

    float zFar = 1000.f, zNear = 0.1f;
    float aspect = W / H;

    mat4 result = zeroMat4 ();

    gluPerspective (45, aspect, zNear, zFar, b, t, l, r);

    result[0][0] = (2 * zNear) / (r - l);
    result[0][2] = (r + l) / (r - l);

    result[1][1] = -(2 * zNear) / (t - b);
    result[1][2] = -(t + b) / (t - b);

    result[2][2] = -(zFar + zNear) / (zFar - zNear);
    result[2][3] = -(2 * zFar * zNear) / (zFar - zNear);

    result[3][2] = -1;

    return result;
}

// the glm way.. its flipped for stupid math reasons
inline mat4 perspective (float fovy, float aspect, float zNear, float zFar)
{
    fovy = RADIANS (fovy);

    const float rad         = fovy;
    const float tanHalfFovy = tan (rad / 2.f);

    mat4 Result = zeroMat4 ();

    Result[0][0] = 1.f / (aspect * tanHalfFovy);
    Result[1][1] = 1.f / (tanHalfFovy);
    Result[2][2] = -(zFar + zNear) / (zFar - zNear);
    Result[3][2] = -1.f;
    Result[2][3] = -(2.f * zFar * zNear) / (zFar - zNear);

    return Result;
}

inline mat4 getModel (v2 pos, v2 size, float angle = 0, bool center = true)
{
    mat4 matrix = identity ();

    translate (matrix, pos);
    translate (matrix, size * (0.5f));

    rotateZ (matrix, angle);

    if (center)
        translate (matrix, size * (-0.5f));

    scale (matrix, size);

    return matrix;
}

inline mat4 getModel (v3 pos, v3 size, v3 angle)
{
    mat4 matrix = identity ();

    translate (matrix, pos);
    translate (matrix, size * (0.5f));

    rotateX (matrix, angle.x);
    rotateY (matrix, angle.y);
    rotateZ (matrix, angle.z);

    scale (matrix, size);

    return matrix;
}

#endif
