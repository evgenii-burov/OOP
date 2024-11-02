#pragma once
#include <iostream>
#include <locale.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <chrono>

const double PI = M_PI;

void CalculateEmpiricDensityFunction(double*& sample, double*& function, const int& N);

double CalculateEmpiricValue(double*& sample, const int& N, const char& value_desired);

double CalculateTheoreticStValue(const double& nu, const double& mu, const double& lambda,\
	const char& value_desired, double x = 0);

double CalculateTheoreticMixValue(const double& nu1, const double& mu1, const double& lambda1, \
	const double& nu2, const double& mu2, const double& lambda2, const double& p, \
	const char& value_desired, double x=0);

void UniformDistribution(double*& sample, const int& N);

void CosExpDistribution(const double& nu, const double& mu, const double& lambda, double*& sample, const int& N);

void DistributionMixture(const double& nu1, const double& mu1, const double& lambda1, \
	const double& nu2, const double& mu2, const double& lambda2, const double& p, double*& sample, const int& N);

void EmpiricDistribution(double* frequencies, double* start_sample, double*& target_sample, const int& N);

void OutputToFile(const char* file_name, const double* sample, const int& N);

int ManageInput(double& nu, double& mu, double& lambda, double& nu1, double& mu1, \
	double& lambda1, double& nu2, double& mu2, double& lambda2, double& p, int& N);