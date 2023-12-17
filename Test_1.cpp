#include <iostream>
#include<bits/stdc++.h>
#include <string>


using namespace std;
int main(){
	string str = "1,123,1234,12345,123456";
	int j = 0;
	string chucai = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] != ',' && j != 4){
			chucai += str[i];
		}
		else if(j == 4){
			for(int k = i; k<str.length(); k++){
				chucai += str[k];
			}
			return 0;
		}
		else{
			chucai = "";
		}
		cout << chucai << endl;
	}
	
	return 0;
}
