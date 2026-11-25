#include <iostream>
#include <cmath>
using namespace std;

int destination() {
	int choice,cost;
	cost = 0;
	cout << "Choose a destination\n" <<
		"1. Murree\n" <<
		"2. Hunza\n" <<
		"3. Swat\n"
		<<"4. Naran\nChoose a number\n";
	cin >> choice;
	while (choice > 4 || choice < 1) {
		cout << "ERROR! choose a destination again!\n";
		cout<<"1. Murree\n" <<
			"2. Hunza\n" <<
			"3. Swat\n"
			<< "4. Naran\nChoose a number\n";
		cin >> choice;
	}
	switch (choice) {
	case 1: cost = 7000;break;
	case 2: cost = 18000;break;
	case 3: cost = 8000;break;
	case 4: cost = 10500;
	}
	return cost;
}

void menu() {
	cout << "\n------MENU------\n";
	cout << "1. Select destination\n"
		<< "2. Enter number of travellers\n"
		<< "3. Enter duration of trip\n" <<
		"4. Choose activities\n"
		<< "5. Enter budget\n"
		<< "6. View cost breakdown.\n"
		<< "7. Exit\n";
}

//traveller and duration
int travellers() {
	int number;
	cout << "Enter the number of travellers.(1-10)\n";
	cin >> number;
	while (number < 1 || number>10) {
		cout << "ERROR! enter the number of travellers again. (1-10)\n";
		cin >> number;
	}
	return number;
}

int duration() {
	int number;
	cout << "Enter number of days for trip duration(1-30).\n";
	cin >> number;
	while (number > 30 || number < 1) {
		cout << "ERROR! Enter number of days for trip duration again.(1-30).\n";
		cin >> number;

	}
	return number;
}

int  activities() {
	int cost,choice,count,a=0,b=0,c=0,d=0,e=0;
	cout << "We offer five activities.\n 1. Sightseeing Rs.600 \n 2. Hiking Rs. 1,200. \n 3. Boating Rs. 1,100.\n 4. Museum Rs. 350.\n 5. Adventure Rs. 1,800\n Note: The cost mentioned is per person.\n";
	cout << "Would you like to select from these activities? If yes, type the activity's number. If no, type 0.\n";
	cin >> choice;
	cost = 0;
	count = 0;
	while (choice < 0 || choice>5) {
		cout << "ERROR!\nWe offer five activities.\n 1. Sightseeing Rs.600 \n 2. Hiking Rs. 1,200. \n 3. Boating Rs. 1,100.\n 4. Museum Rs. 350.\n 5. Adventure Rs. 1,800\n Note: The cost mentioned is per person.\n";
		cout << "Would you like to select from these activities? If yes, type the activity's number. If no, type 0.\n";
		cout << "Choose again!\n";
		cin >> choice;
	}
	while (choice !=0 && count < 5) {
		switch (choice) {
		case 1:
			if (a == 0) {
				cost += 600;
				a = 1;
			}
			else {
				cout << "You can only choose a specific activity once\n";
			}
			break;
		case 2:
			if (b == 0) {
				cost += 1200;
				b = 1;
			}
			else {
				cout << "You can only choose a specific activity once\n";
			}
			break;
		case 3:
			if (c == 0) {
				cost += 1100;
				c = 1;
			}
			else
				cout << "You can only choose a specific activity once\n";
			break;
		case 4:
			if (d == 0) {
				cost += 350;
				d = 1;
			}
			else
				cout << "You can only choose a specific activity once\n";
			break;
		case 5:
			if (e == 0) {
				cost += 1800;
				e = 1;
			}
			else
				cout << "You can only choose a specific activity once\n";
			break;
		}
			cout << "We offer five activities.\n1. Sightseeing Rs.600 \n 2. Hiking Rs. 1,200. \n 3. Boating Rs. 1,100.\n 4. Museum Rs. 350.\n 5. Adventure Rs. 1,800\n Note: The cost mentioned is per person.\n";
			cout << "Would you like to select another one of these activities? If yes, type the activity's number. If no, type zero.\n";
			cin >> choice;
			count++;
		
	}
	return cost;
}

int budget() {
	int b;
	cout << "What is your budget for the trip?\n";
	cin >> b;
	while (b < 0){
		cout << "Error! enter budget again.";
		cin >> b;
	}
	return b;
}
int main() {
	int total,choice,food,transport,accommodation,dest,tr,dur,bud,act,rooms,nights;
	double perRoom;
	tr = 1;
	bud = -1;
	food = 0;
	transport = 0;
	accommodation = 0;
	act = 0;
	menu();
	cin >> choice;
	while (choice < 1 || choice>7) {
		cout << "ERROR!\n";
		menu();
		cout << "Choose again\n";
		cin >> choice;
	}
	while (choice != 7) {
		switch (choice) {
		case 1: dest = destination();
			if (dest == 7000) {
				food = 3000;
				transport = 4000;
			}
			else if(dest == 18000){
				food = 3000;
				transport = 15000;
			}
			else if (dest == 8000) {
				food = 2000;
				transport = 6000;
			}
			else if (dest == 10500) {
				food = 2500;
				transport = 8000;
			}
			break;
		case 2: tr = travellers();
			food *= tr;
			transport *= tr;
			rooms = round(tr/2.0);
		
			break;
		case 3: dur = duration();
			food *= dur;
			nights = dur - 1;
			if (dest == 7000) {
				accommodation = 9000 * nights * rooms;
			}
			else if (dest == 18000) {
				accommodation = 12000 * nights * rooms;
			}
			else if (dest == 8000) {
				accommodation = 8000 * nights * rooms;
			}
			else if (dest == 10500) {
				accommodation = 10000 * nights * rooms;
			}
			total = food + accommodation + transport;
			break;

		case 4: act = activities();
			act *= tr;
			total += act;
			break;
		case 5: bud = budget();
			if (bud != -1) {
				if (bud >= total)
					cout << "WITHIN BUDGET - remaining PKR" << bud - total<< endl;
				else
					cout << "OVER BUDGET - exceeded by PKR " <<total-bud << endl;
			}
			break;
		case 6: 
			cout << "Cost of food: " << food << endl;
			cout << "Cost of transport: " << transport << endl;
			cout << "Cost of accommodation: " << accommodation << endl;
			cout << "Cost of activities: " << act<<endl;
			cout << "Total cost of the trip: " << act+accommodation+transport+food;break;

		}
		menu();
		cin >> choice;
	}
	cout << "Goodbye! Your program has ended.\n";
	return 0;
}
