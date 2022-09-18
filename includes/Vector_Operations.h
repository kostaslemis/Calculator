#pragma once

#include <cmath>

#include "Vector.h"


bool equal_size(const Vector &v, const Vector &u);

Vector operator+(const Vector &v, const Vector &u);

Vector operator-(const Vector &v, const Vector &u);

Vector operator*(double k, const Vector &v);

bool operator==(const Vector &v, const Vector &u);

bool operator!=(const Vector &v, const Vector &u);

double dot_product(const Vector &v, const Vector &u);

Vector cross_product(const Vector &u, const Vector &v);

Vector tensor_product(const Vector &v, const Vector &u);

double vector_length(const Vector &vector);
