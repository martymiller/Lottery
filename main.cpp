#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <iomanip>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int ticket[6];
	int numberCount = 0;
	int maxNumber = 47;
	int maxMegaNumber = 27;
	int numbersToMatch = 0;
	
	while(numberCount <= 5) {
		int displayCount = numberCount + 1;
		cout << displayCount << ". ";
		if (displayCount < 6) {
		cout << "Enter lottery number # (1-47): ";			
		}
		else {
			cout << "Enter MEGA number (1-27): ";
		}			
		cin >> ticket[numberCount];
		numberCount++;
	}
	cout << "How many numbers have to match? ";
	cin >> numbersToMatch;
	
	int winningTicket[6];
	bool winner = false;
	int attempts = 0;
	
	srand (time(NULL));
	
	while(winner != true) {
		attempts = attempts + 1;
		winningTicket[0] = 1 + rand()%maxNumber;
		winningTicket[1] = 1 + rand()%maxNumber;
		winningTicket[2] = 1 + rand()%maxNumber;
		winningTicket[3] = 1 + rand()%maxNumber;
		winningTicket[4] = 1 + rand()%maxNumber;
		winningTicket[5] = 1 + rand()%maxMegaNumber;
	
		cout << "Ticket #" << attempts << "  ";
		cout << setw(2) << winningTicket[0] << "  ";
		cout << setw(2) << winningTicket[1] << "  ";
		cout << setw(2) << winningTicket[2] << "  ";
		cout << setw(2) << winningTicket[3] << "  ";
		cout << setw(2) << winningTicket[4] << "  ";
		cout << setw(2) << winningTicket[5] << "  ";
		
		int tempTicket[6];
		int tempWinningTicket[6];
		for(int i = 0; i < 6; i++) {
			tempTicket[i] = ticket[i];
			tempWinningTicket[i] = winningTicket[i];
		}
		int numbersMatched = 0;
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if( tempTicket[i] == tempWinningTicket[j]) {
					numbersMatched++;
					tempWinningTicket[j] = -1;					
					break;
				}
			}
		}
		
		//MEGA
		if(tempTicket[5] == tempWinningTicket[5]) {
			numbersMatched++;
		}
		
		if(numbersMatched >= numbersToMatch) {
			winner = true;
			break;
		}
		else {
			cout << " \tLOSE\n";
			winner = false;
		}
		//sleep(1.5);
	}
	cout << "WINNER!!! after " << attempts << " attempts\n";
	return 0;
}
