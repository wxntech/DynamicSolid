// Fill out your copyright notice in the Description page of Project Settings.

// #include "CoreMinimal.h"

#pragma once

#include<Eigen/Dense>
#include<Eigen/Sparse>
// #include<fbxsdk.h>

#include<cmath>

#ifdef HIGH_PRECISION
using real = double;
#else
using real = float;
#endif

using real_hps = double;

namespace utility
{
	namespace math
	{
#ifdef HIGH_PRECISION
		constexpr double eps = 1e-9;
		constexpr double pi = 3.141592653589793238462643383279502884;
#else
		constexpr float pi = 3.141592653589;
		constexpr float eps = 1e-6;
#endif
	}
}

template<typename T>
using Vector9 = Eigen::Matrix<T, 9, 1>;

template<typename T>
using Vector12 = Eigen::Matrix<T, 12, 1>;

template<typename T>
using Vector4 = Eigen::Matrix<T, 4, 1>;

template<typename T>
using Vector3 = Eigen::Matrix<T, 3, 1>;

template<typename T>
using Vector2 = Eigen::Matrix<T, 2, 1>;

template<typename T>
using SpMat = Eigen::SparseMatrix<T>;

template<typename T>
using Quaternion = Eigen::Quaternion<T>;

template<typename T>
using Map = Eigen::Map<T>;

using Vector4f = Vector4<float>;
using Vector4d = Vector4<double>;

using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

using Vector9f = Vector9<float>;
using Vector9d = Vector9<double>;

using Vector12f = Vector12<float>;
using Vector12d = Vector12<double>;

template<typename T, int N, int M>
using Matrix = Eigen::Matrix<T, N, M>;

template<typename T>
using MatrixX = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

template<typename T>
using VectorX = Eigen::Matrix<T, Eigen::Dynamic, 1>;

template<typename T>
using Matrix3x3 = Matrix<T, 3, 3>;

template<typename T>
using Matrix4x4 = Matrix<T, 4, 4>;

using Matrix3f = Matrix3x3<float>;

using MatrixXf = MatrixX<float>;

using VectorXf = VectorX<float>;

//for SVD result
using UVSGroup = TTuple<Matrix3x3<real>, Matrix3x3<real>, Vector3<real>>;

namespace utility
{
	namespace math
	{
		Matrix<real, 3, 3> CrossMatrix(const Vector3<real>& f);
		// void MatrixScale(FbxAMatrix& pMatrix, double pValue);
		//
		// void MatrixAddToDiagonal(FbxAMatrix& pMatrix, double pValue);
		//
		// void MatrixAdd(FbxAMatrix& pDstMatrix, const FbxAMatrix& pSrcMatrix);
		//
		// FbxVector4 MatrixVec4Mul(const FbxAMatrix& m, const FbxVector4& v);
		//
		// FbxVector4 VectorMat4Mul(const FbxVector4& v, const FbxAMatrix& m);
		//
		// FbxAMatrix MatrixMatrixMul(const FbxAMatrix& m0, const FbxAMatrix& m1);
	}
}


namespace utility
{
	namespace math
	{
		template<typename T>
		T ACos(T value) {
			if (value < -1.f) value = -1.f;
			if (value > 1.f) value = 1.f;
			return std::acos(value);
		}

		template<typename T>
		T ScalarTripleProduct(const Vector3<T>& a, const Vector3<T>& b, const Vector3<T>& c) {
			return a.cross(b).dot(c);
		}

		template<typename T>
		bool AlmostEqual(T a, T b = T(0.), T custom_eps = eps) {
			return std::abs(a - b) < custom_eps;
		}

		template<typename T>
		bool Leq(T a, T b = T(0.)) {
			return (a < b || (AlmostEqual(a, b)));
		}

		template<typename T>
		bool Geq(T a, T b = T(0.)) {
			return (a > b || (AlmostEqual(a, b)));
		}
	}
}
