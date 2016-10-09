// Created by: Oscar Cairoli
// Soda Machine
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;
int main () 
{
	// Declarations //
	int State = 1;
	int choice;
	int Coors = 2;
	int Budlight = 2;
	double total = 0.0;
	
		
	while (true) // Main Loop //
	{
						
		switch (State)
		{
			case 1: // Start of soda machine //
				cout << " Enter '75' cents for a cold pop ('0' to return your money). " << endl << endl;
				int x;
				cin >> x;
				
				total += x;
				
				if ( x == 0 )
				{
					State = 4;
					break;
				}
				if ( total == 75 ) 
				{
					State = 2;
					break;
				}
				if ( total > 75 )
				{
					State = 4;
					break;
				}
				if ( total < 75 )
				{
					State = 1;
					break;
				}
								
			case 2: // Wait for Selection //
				cout << " Press '1' for Coke, '2' for Sprite or '3' to return your money. " << endl << endl;
				cin >> choice;
					
			
				if ( choice == 1 )
				{
					State = 3;						
					break;							
				}
				if ( choice == 2 )
				{ 
					State = 3;
					break;
				}
				if ( choice == 3 )
				{
					State = 4;
					break;
				}
				
			case 3: // Check Inventory //
				
				if ( choice == 1 ) 
				{
					if ( Coors == 0 )
					{
						cout << " We're all sold out of Coke. Try another selection. " << endl << endl;
						choice = 4;
						break;
					}
					if ( Coors > 0 )
					{
						cout << " Enjoy your cold Coke! " << endl << endl;
						State = 1;
						Coors--;
						break;
					}
					
				}
				if ( choice == 2 )
				{
					if ( Budlight == 0 )
					{
						cout << " We're all sold out of Sprite. Try another selection. " << endl << endl;
						choice = 4;
						break;
					}
					if ( Budlight > 0 )
					{
						cout << " Enjoy your cold Sprite " << endl << endl;
						State = 1;
						Budlight--;
						break;
					}
				}
				if ( choice == 4 )
				{
					if ( Budlight == 0 && Coors == 0 )
					{
						cout << " The machine is all sold out. Sorry. " << endl << endl;
						choice = 3;
						State = 4;
						break;
					}
					
					State = 2;
					break;
				}
						
				
			case 4: // Return Total //
				
				int change1 = (total - 75);
				int change2 = 75;
				
				if ( x == 0 )
				{
					if ( total > 75 )
					{
						cout << " Your change is " << change1 << endl << endl;
						State = 2;
						break;
					}
					
					cout << " Your change is " << total << " cents. " << endl << endl;
					State = 1;
					total = 0;
					break;
				}

				if ( choice == 3 )
				{
					cout << " Your change is 75 cents. " << endl << endl;
					State = 1;
					break;
				}
				if ( total == 75 )
				{
					cout << " Your change is " << change2 << " cents. " << endl << endl;
					State = 1;
					break;
				}
				if ( total > 75 )
				{
					cout << " Your change is " << change1 << " cents. " << endl << endl;
					State = 2;
					total = 0;
					break;
				}
							
				
		}
	}

		
	
	return 0;
}






