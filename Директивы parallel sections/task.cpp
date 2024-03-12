#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    #pragma omp parallel


#pragma omp single
{
#pragma omp task
 {
			for (int n = 0; n<25'000'000; ++n)
			{
				sin(3.14 * n / (2 * 100'000'000));
			}
		}
#pragma omp task
 {
			for (int n = 25'000'000; n<50'000'000; ++n)
			{
				sin(3.14 * n / (2 * 100'000'000));
			}
		}
#pragma omp task
 {
			for (int n = 50'000'000; n<75'000'000; ++n)
			{
				sin(3.14 * n / (2 * 100'000'000));
			}
		}
#pragma omp task
 {
			for (int n = 75'000'000; n<100'000'000; ++n)
			{
				sin(3.14 * n / (2 * 100'000'000));
			}
		}
}
return EXIT_SUCCESS;
}

------------
#include <iostream> 
#include <omp.h> 
using namespace std;
#include <cmath>
bool prime(int n)
{
if (n == 1) return false;
if (n % 2 == 0 && n != 2) // отдельно проверим делимость на 2
return false;
for (int i = 3; i * i <= n; i += 2)
if (n % i == 0)
return false;
// выход из функции, как только нашли делитель
return true; // цикл закончился, делителей не нашлось
}
int main(int argc, char* argv[])
{
    int sum1, sum2;
#pragma omp parallel
 {
#pragma omp single
{
#pragma omp task
for(int i = 3; i < n; i+=4)
{
    sum1 += prime(i);
}
#pragma omp task
for(int i = 5; i < n; i+=4)
{
    sum2 += prime(i);
}
}
}
std::cout << sum1+sum2<<std::endl;
return EXIT_SUCCESS;
}


------
#include <iostream>
#include <cmath>
const int n = 1'000'000;
double f(double x)
{
return 1 / (1 + x * x);
}
double integr(double (*f)(double), double A, double B)
{
double sum = 0;
double h = (B-A)/10.0;
for (int i = 0; i <= 9; ++i)
sum += f(A +i*h);
sum += (f(A) +f(B))/2.0;
sum *= h;
return sum;
}
double integral(double (*f)(double), double A, double B)
{
    double sum1 = integr(f,  A,  B);
    double C = (B+A)/2.0;
    double sum2 = integr(f,  A,  C);
    double sum3 = integr(f,  C,  B);
    if(sum1 - (sum2 + sum3) <= pow(2.71828, -10))
    {
        return sum1;
    }
    return sum1 + sum2;
    
}
int main(int argc, char* argv[])
{
   std::cout << integral(f, 0, 1);
return EXIT_SUCCESS;
}