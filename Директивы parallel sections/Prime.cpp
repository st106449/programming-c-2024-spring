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
int main()
{
    double t = omp_get_wtime();
int s = 0;
#pragma omp parallel sections
#pragma omp section private (s)
{
	
	for (int n = 3; n < 1'000'000; n+=4)
	{
		s+=prime(n);

	}
}
#pragma omp section private (s)
{

	for (int n = 5; n < 1'000'000; n+=4)
	{
		s+=prime(n);

	}
}
	std::cout << s << std::endl;
    std::cout << "Time: " << (omp_get_wtime() - t)*1000 << std::endl;
	
	return EXIT_SUCCESS;
}
