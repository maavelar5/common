#ifndef MATH_DATA
#define MATH_DATA

#include <cassert>
#include <cmath>

#include "typedefs.hpp"

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

struct mat4
{
    float rows[4][4];

    float *operator[] (int i)
    {
        return rows[i];
    }
};

// v2[s|u] operators
v2 operator+ (v2 a, v2 b);

v2 operator- (v2 a, v2 b);
v2 operator* (v2 a, v2 b);
v2 operator/ (v2 a, v2 b);
v2 operator+ (v2 a, float v);
v2 operator- (v2 a, float v);
v2 operator* (v2 a, float v);
v2 operator/ (v2 a, float v);

float length (v2 v);

v2 normalize (v2 v);

v2s operator+ (v2s a, v2s b);
v2s operator- (v2s a, v2s b);
v2s operator* (v2s a, v2s b);
v2s operator/ (v2s a, v2s b);
v2s operator+ (v2s a, float v);
v2s operator- (v2s a, float v);
v2s operator* (v2s a, float v);
v2s operator/ (v2s a, float v);

bool operator== (v2s a, v2s b);

// v3[s|u] operators
v3 operator+ (v3 a, v3 b);
v3 operator- (v3 a, v3 b);

v3    operator* (v3 a, v3 b);
v3    operator/ (v3 a, v3 b);
v3    operator+ (v3 a, float v);
v3    operator- (v3 a, float v);
v3    operator* (v3 a, float v);
v3    operator/ (v3 a, float v);
float length (v3 v);

v3 normalize (v3 v);

// v4[s|u] operators
v4 operator+ (v4 a, v4 b);
v4 operator- (v4 a, v4 b);
v4 operator* (v4 a, v4 b);
v4 operator/ (v4 a, v4 b);
// v4[s|u] operators
v4u operator+ (v4u a, v4u b);
v4u operator- (v4u a, v4u b);
v4u operator* (v4u a, v4u b);
v4u operator/ (v4u a, v4u b);
v2  operator- (v2 a, v3 b);

mat4 identity ();

mat4 zeroMat4 ();
void identity (mat4 *mat);
void copy (float in[4][4], float out[4][4]);
mat4 operator* (mat4 m1, mat4 m2);
void translate (mat4 &matrix, v2 pos);
void scale (mat4 &matrix, v2 size);
void rotateZ (mat4 &matrix, float angle);
void rotateY (mat4 &matrix, float angle);

void        rotateX (mat4 &matrix, float angle);
void        translate (mat4 &matrix, v3 pos);
void        scale (mat4 &matrix, v3 size);
inline mat4 ortho (float W, float H);

// compute screen coordinates first -- gotta re-read about this
void gluPerspective (const float &angleOfView, const float &imageAspectRatio,
                     const float &n, const float &f, float &b, float &t,
                     float &l, float &r);

mat4 perspective (float W, float H);

// the glm way.. its flipped for stupid math reasons
mat4 perspective (float fovy, float aspect, float zNear, float zFar);

mat4 getModel (v2 pos, v2 size, float angle = 0, bool center = true);
mat4 getModel (v3 pos, v3 size, v3 angle);

#endif
