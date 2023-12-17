#include <iostream>
#include <math.h>
int shh(int n){
	int sum = 0;
	for(int i=1; i<=n/2;i++){
		if(n % i ==0) sum+=i;
	}
	if(sum == n) return 0;
	return 1;
}

int main(){
	int n;
	std::cout << "Nhap so nguyen duong <n>: "; std::cin >> n;
	std::cout << "So hoan hao khong qua " << n << " la:\n"; 
	for(int i = 1; i <= n; i++){
		if(shh(i) == 0){
			std::cout << i << " ";
		}
	}
}
