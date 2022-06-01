#include <iostream>

void menu() {

	std::cout << "Health-o-Matic Options \n";
	std::cout << "-------------------------- \n";
	std::cout << "\n\n";
	std::cout << "1. Taking a Walk!\n";
	std::cout << "2. Your Medications\n";
	std::cout << "3. Nap Time!!\n";
	std::cout << "4. Caloric Intake\n";
	std::cout << "5. Quit\n\n";
}

// function to calculate steps. 
int step_calculation() {

	int leg = 0;

	std::cout << "Input legs: ";
	std::cin >> leg;

	while (leg < 0) {

		std::cout << "incorrect input try again: ";
		std::cin >> leg;
	}

	return leg;
}

// function to calculate the steps recursively.
int recursive_factorial(int legs) {

	if (legs > 1)
		return legs * recursive_factorial(legs - 1);
	else
		return 1;
}

void print_steps(int steps) {

	std::cout << steps << " steps\n";
}

// for the second case
int anx() {

	// will return value to a local variable.
	int a_level;
	// could use cin.ignore here to test out the input. 

	std::cout << "What is your anxiety level: ";
	std::cin >> a_level;


	if (!(a_level >= 0 && a_level <= 10)) {

		std::cout << "incorrect input\n";
		return 0;

	}
	else {

		return (a_level);
	}
}

void display_pills(int pills) {

	std::cout << pills << "\n";
}

int day_q()
{
	int day = 0;

	std::cout << "Input day: ";
	std::cin >> day;

	while (!(day >= 1 && day <= 7)) {

		std::cout << "incorrect input try again: ";
		std::cin >> day;
	}

	return day;	
}

int sub_a_p(int anx, int day) {

	int an = 0;

	an = anx - day;

	if (an < 0) return 0;

	return an;
}

void display_pill(int pills)
{
	std::cout << pills << " pills\n";
}

int hours_slept()
{
	int sleep = 0;
	std::cout << "How many hours have you slept: ";
	std::cin >> sleep;

	return sleep;
}

// will return to int minutes
int naptime(int nap, int steps, int pills) {

	int minutes = 0;

	//minutes = hrs slept + dist walked / number of pills(if 0, divide by 1)

	if (pills == 0)	pills = 1; // if pills is 0, then use 1. 

	minutes = (nap + steps) / (pills);

	return minutes;
}

// function to print how much nap there can 
void print_naptime(int naptime) {

	std::cout << naptime << " minutes of sleep\n";
}

// function for the fourth case
float calcs(int steps) {

	int calc, weight, height;
	float room_temp;

	std::cout << "enter weight: ";
	std::cin >> weight;
	std::cout << "enter height: ";
	std::cin >> height;
	std::cout << "enter room temperature: ";
	std::cin >> room_temp;

	calc = (6 * weight) + (2 * height) + ((1) / (room_temp)) + (steps);

	return calc;
}

void print_calc(float calc) {

	std::cout << calc << " caloric intake\n";
}

int main() {

	int input, leg = 0, anx_levels = 0, day = 0;
	int legs, steps = 0, pills = 0, nap = 0;
	float calculate;
	bool switch1 = false, switch2 = false; // checking that cases 1 and 2 have been completed

	menu();

	// put the switch statements down here. 
	while (true) {
		std::cin >> input;

		switch (input) {

		case 1:
			legs = step_calculation(); // use conditional stament to protect boolean. Program should not end.  
			steps = recursive_factorial(legs); // function to calculate steps.
			print_steps(steps);
			switch1 = true; // setting this boolean to true. 
			break;
		case 2:
			anx_levels = anx(); // function for anxiety
			day = day_q(); // function for day			
			pills = sub_a_p(anx_levels, day); ; // function that calculates amount of pills to take
			display_pill(pills); // function that display pill			
			switch2 = true;
			break;
		case 3:
			// put conditional here
			if ((switch1 == true) && (switch2 == true))
			{
				nap = hours_slept();
				int nap_calc = naptime(nap, steps, pills);
				print_naptime(nap_calc);
			}
			else {

				std::cout << "ERROR\n";
				break;

			}
			break;
		case 4:
			// need condition from first case. 
			if (switch1 == true) {
				calculate = calcs(steps);
				print_calc(calculate);
			}
			else {

				std::cout << "ERROR\n";
			}
			break;
		case 5:
			exit(1);
			break;
		default:
			std::cout << "The input is not correct - try options 1 through 5";
			break;
		}
	}
}
