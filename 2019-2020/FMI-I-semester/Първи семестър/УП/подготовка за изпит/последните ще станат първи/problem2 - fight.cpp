#include <iostream>
#include <string>
#include <time.h>
using namespace std;

const int NUMBER = 0;
const int POWER = 1;
const int AGILITY = 2;
const int SPEED = 3;
const int KNOWLEDGE = 4;
const int HP = 5;

double getAttackPower(int animals[][6], int attacker, int defender) {
	double chance = (1 + (animals[attacker][KNOWLEDGE]/100.0)) * (max(10, animals[attacker][AGILITY] - animals[defender][AGILITY]));
	double force = 0.0;
	int random = rand() % 101;
	if (random < chance) {
		force = (1 + ( max(10, animals[attacker][SPEED] - animals[defender][SPEED]) / 100.0)) * (max(10, animals[attacker][POWER] - animals[defender][POWER]) / 100.0);
	}
	return force;
}

int fight(int animals[][6], int fighter1Index, int fighter2Index) {
	double hp1 = animals[fighter1Index][HP];
	double hp2 = animals[fighter2Index][HP];

	while (hp1 > 0.0001 && hp2 > 0.0001) {
		double force1attacking2 = getAttackPower(animals, fighter1Index, fighter2Index);
		hp2 -= force1attacking2;
		if (hp2 > 0.0001) {
			double force2attacking1 = getAttackPower(animals, fighter2Index, fighter1Index);
			hp1 -= force2attacking1;
		}
	}

	return (hp1 > 0) ? fighter1Index : fighter2Index;
}

void addToWinners(int winners[][6], int& winnersSize, int animals[][6], int winnerIndex) {
	for (int i = 0; i < 6; i++)
		winners[winnersSize][i] = animals[winnerIndex][i];
	winnersSize++;
}

void moveWinnersToAnimals(int animals[][6], int winners[][6], int winnersSize) {
	for (int i = 0; i < winnersSize; i++)
		for (int j = 0; j < 6; j++) 
			animals[i][j] = winners[i][j];
}

int main ()
{
	srand(time(NULL));
	int aliveAnimalsSize, aliveAnimals[32][6], winnersSize = 0, winners[16][6];
	cin>>aliveAnimalsSize;

	for (int i = 0; i < aliveAnimalsSize; i++) {
		cin>>aliveAnimals[i][NUMBER];
		cin>>aliveAnimals[i][POWER];
		cin>>aliveAnimals[i][AGILITY];
		cin>>aliveAnimals[i][SPEED];
		cin>>aliveAnimals[i][KNOWLEDGE];
		cin>>aliveAnimals[i][HP];
	}

	while (aliveAnimalsSize > 1) {
		for (int i = 0; i < aliveAnimalsSize; i+=2) {
			int winnerIndex = fight(aliveAnimals, i, i+1);
			addToWinners(winners, winnersSize, aliveAnimals, winnerIndex);
		}
		moveWinnersToAnimals(aliveAnimals, winners, winnersSize);
		winnersSize = 0;
		aliveAnimalsSize /= 2;
	}

	cout<<"WINNER: #"<<aliveAnimals[0][NUMBER]<<endl;
}