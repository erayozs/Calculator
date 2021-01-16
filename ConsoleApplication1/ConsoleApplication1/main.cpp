
#include <iostream>
#include <string> 
#include <sstream>

// Dünyanýn en spaghetti code'unu görmeye hazýrlanýn

/* Uyarý: Bu kod aralarda oldukça çýldýrma ve devam etmeye üþenme ile yazýlmýþtýr, variable isimlerinin, fonksiyon isimlerinin vs. vs.
çok da okunabilir olmasýný beklemeyiniz.
*/

int counter = 0;

double Calculate(double Num[], std::string Oper[]);
void Convert(std::string str);
void Deescalate(int d);

std::string op = "";
std::string strng[7] = { "", "", "", "", "", "", "" };
double Num[4] = { -31, -31, -31, -31 };
int Base[4] = { 0, 0, 0, 0 };
std::string oper[3] = { "bos", "bos", "bos" };
int a = 0;
double res = 0;


int main()
{
	double result = 0.0;
	bool open = 1;
	while (true) {
		counter = 0;
		std::cout << "Console Calculator" << std::endl << std::endl
			<< "Please enter the operation." << std::endl;
		getline(std::cin, op);
		Convert(op);
		result  = Calculate(Num, oper);
		std::cout << "Result is: " << result << std::endl;
		

   }
}

// Ýnputu sayý ve operatörlere çeviren fonksiyon

void Convert(std::string str)
{

	std::istringstream ss(str);
	std::string word; 

	while (ss >> word)
	{
		strng[a] = word;
		if (a % 2 == 0) {
			std::stringstream copy(strng[a]);
			copy >> Num[a / 2];
		}
		else if (a % 2 == 1) {
			oper[a / 2] = strng[a];
			counter++;
		}
		a++;
		
	}
	a = 0;
}

// Ýþlemleri yapan fonksiyon

double Calculate(double Num[], std::string Oper[]) {
	res = 0;
	for (int d = 0; d < counter + 1; d++) {
		if (oper[d] != "") {
			if (oper[d] == "^") {
				Num[d + 1] = pow(Num[d], Num[d + 1]);
				res = Num[d + 1];
				Deescalate(d);
					
			}
		}
	}
		
		
	for (int d = 0; d < counter + 1; d++) {
		for (int d = 0; d < counter + 1; d++) {
			if (oper[d] != "") {
				if (oper[d] == "*") {
					res = Num[d] * Num[d + 1];
					Deescalate(d);
				}

				else if (oper[d] == "/") {

					res = Num[d] / Num[d + 1];
					Deescalate(d);

				}


			}
		}
	}
		
	for (int d = 0; d < counter + 1; d++) {
		for (int d = 0; d < counter + 1; d++) {
			if (oper[d] != "") {
				if (oper[d] == "+") {
					res = Num[d] + Num[d + 1];
					Deescalate(d);
				}

				if (oper[d] == "-") {
					res = Num[d] - Num[d + 1];
					Deescalate(d);

				}
			}
		}
	}
		
	if (oper[counter - 1] == "mod") {
		int num1 = Num[counter - 1];
		int num2 = Num[counter];
		int reso = 0;
		reso = num1 % num2;
		res = reso;
	}
		
	if (oper[counter - 1] == "base") {
		int num1 = Num[counter - 1];
		int num2 = Num[counter];
		int baso = 0;
		res = 0;
		int i = 0;
		for (i; num1 > 0; i++){
			Base[i] = num1 % num2;
			num1 = num1 / num2;
		}
		int f = i - 1;
		for (f; f > -1; f--) {
			res += pow(10, f) * Base[f];
			
		}


	}
	Num[0] = 0;
	Num[1] = 0;
	Num[2] = 0;
	Num[3] = 0;
	return res;
	
}

 //Ýþlem sonrasýnda sayýlarý ve operatörleri sonraki iþlemlere hazýrlayan fonksiyon

void Deescalate(int d) {
	Num[d] = res;
	for (int i = d; i < counter; i++) {
		Num[i + 1] = Num[i + 2];
		Num[i + 2] = -1087;
	}

	for (int i = d; i < counter; i++) {
		oper[i] = oper[i + 1];
		oper[i + 1] = "";
	}
	counter--;
}
