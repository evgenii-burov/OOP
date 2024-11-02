#include "functions.h"

int main() 
{
    auto t1 = std::chrono::high_resolution_clock::now();
    srand((unsigned)time(0));
    double nu, mu, lambda;
    double nu1, mu1, lambda1, nu2, mu2, lambda2, p;
    int N;
    if (ManageInput(nu, mu, lambda, nu1, mu1, lambda1, nu2, mu2, lambda2, p, N) == -1)
        return 0;
    int k = int(log2(N)) + 1;
    std::cout << "Parameters:\n";
    std::cout <<"nu: " << nu << "\tmu: " << mu << "\tlambda: " << lambda << "\tN: "\
        << N << "\tk: " << k<< "\tp: " << p <<"\n";
    std::cout << "nu1: " << nu1 << "\tmu1: " << mu1 << "\tlambda1: " << lambda1 << "\n";
    std::cout << "nu2: " << nu2 << "\tmu2: " << mu2 << "\tlambda2: " << lambda2 << "\n\n";
    double* standart_sample = new double[N];
    double* mixture_sample = new double[N];
    double* frequencies = new double[k];
    double* empiric_sample = new double[N];
    CosExpDistribution(nu, mu, lambda, standart_sample, N);
    OutputToFile("standart_sample.txt", standart_sample, N);
    CalculateEmpiricDensityFunction(standart_sample, frequencies, N);
    OutputToFile("frequencies.txt", frequencies, k);
    DistributionMixture(nu1, mu1, lambda1, nu2, mu2, lambda2, p, mixture_sample, N);
    OutputToFile("mixture_sample.txt", mixture_sample, N);
    EmpiricDistribution(frequencies, standart_sample, empiric_sample, N);
    OutputToFile("empiric_sample.txt", empiric_sample, N);
    std::cout << std::setprecision(3);
    std::cout << "Standart distribution:\n";
    CalculateEmpiricValue(standart_sample, N, '0');
    std::cout << "Theoretical values:\n";
    std::cout << "nu:" << '\t';
    for (double nu = 0.2; nu <= 1; nu += 0.1)
    {
        std::cout << nu << '\t';
    }
    const int ST_VALUES_LEN = 4;
    char ST_VALUES[ST_VALUES_LEN] = {'D', 'E', 'P', 'F'};
    for (int i = 0; i < ST_VALUES_LEN; i++)
    {
        std::cout << '\n' << ST_VALUES[i] << ":\t";
        for (double nu = 0.2; nu <= 1; nu += 0.1)
        {
            std::cout << CalculateTheoreticStValue(nu, mu, lambda, ST_VALUES[i]) << '\t';
        }
    }
    std::cout << "\n\nDistribution mixture:\n";
    CalculateEmpiricValue(mixture_sample, N, '0');
    std::cout << "Theoretical values: x\n";
    const int MIX_VALUES_LEN = 3;
    char VALUES[MIX_VALUES_LEN] = { 'D', 'E', 'F' };
    for (int i = 0; i < MIX_VALUES_LEN; i++)
    {
        std::cout << '\n' << VALUES[i] << ":\t";
        std::cout << CalculateTheoreticMixValue(nu1, mu1, lambda1, nu2, mu2, lambda2, p, VALUES[i]) << '\t';
    }

    std::cout << "\n\nEmpirical distribution:\n";
    CalculateEmpiricValue(empiric_sample, N, '0');
    delete[] standart_sample;
    delete[] mixture_sample;
    delete[] empiric_sample;
    delete[] frequencies;
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
    std::cout <<"Runtime (seconds): " << duration.count();
}
