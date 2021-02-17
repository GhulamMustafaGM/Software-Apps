// Function Best Practices
/* 

When creating functions there is a precaution that is often considered a 'best practice'. 

When passing variables that are not going to be modified in the function, define the variable as a 'const' so that it cannot be changed by the function. 

For example:
In this function, we are passing an integer variable called input. We want the function to use it and not modify it. So we will give it a variable type that is a const int. 

Function Delcaration

int doubleInput(const int input)
Function Definition

int doubleInput(const int input)
{
    int h = input *2;
    return h;
}
This code will not compile:
I have modified the variable input. In the declaration and definition I said this value would not be modified.

int doubleInput(const int input)
{
    input++;
    int h = input *2;
    return h;
}

*/

// Debug Program

/* input.txt
Happy Gilmore
(408)665-4321
432B Main St, Mountain View, CA. 95120
Living room
3
24
18
8

*/
// main.hpp

/*The header file for main.cpp
 **This file has functions called from main.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//Cost of materials for the remodel
const float PAINTCOST = .50;      //per square foot
const float WALLPAPERCOST = 2.00; //per square foot
const float CARPETCOST = 4.00;    //per square foot
const float TILECOST = 5.50;      //per square foot
const float WOODCOST = 6.00;      //per square foot

using namespace std;

void getUserInformation(string &name, string &number, string &address);
string getRoomChoice();
int getTaskAssignment();
void printTask(int task);
void getRoomInformation(int task, float &roomWidth, float &roomDepth, float &roomHeight);
void printJobInformation(string userName, string phoneNumber, string userAddress, string remodelRoom, int task);
float calcWallSurfaceArea(float roomWidth, float roomDepth, float roomHeight);
float calcPaintCost(float wallSurfaceArea);
float calcWallPaperCost(float wallSurfaceArea);
void printWallCostComparisons(float paintCost, float wallpaperCost);
float calcFloorArea(float roomWidth, float roomDepth);
float calcCarpetCost(float floorArea);
float calcTileCost(float floorArea);
float calcWoodFloor(float floorArea);
void printFloorCostComparisons(float carpetCost, float tileCost, float woodFloorCost);

void getUserInformation(string &userName, string &phoneNumber, string &userAddress)
{
    cout << "Customer Name: \n";
    getline(std::cin, userName);

    cout << "Customer Phone Number: \n";
    getline(std::cin, phoneNumber);

    cout << "Customer Address: \n";
    getline(std::cin, userAddress);
}

string getRoomChoice()
{ //We don't do anything with this information in the program
    string room;
    cout << "What room are we remodeling?: \n";
    getline(std::cin, room);
    return room;
}

int getTaskAssignment()
{ //the possible task list
    int task;
    std::cout << "What job needs to be done?\n";
    std::cout << "0: Paint\n";
    std::cout << "1: Wallpaper\n";
    std::cout << "2: Carpet\n";
    std::cout << "3: Tile\n";
    std::cout << "4: Wood Floor\n";
    cin >> task;
    //std::cout<<"Task = "<<task;
    return task;
}

void printTask(int task)
{ //depending on which task was selected, print the corresponding string
    switch (task)
    {
    case 0:
        std::cout << " paint ";
        break;
    case 1:
        std::cout << " wallpaper ";
        break;
    case 2:
        std::cout << " carpet ";
        break;
    case 3:
        std::cout << " tile ";
        break;
    case 4:
        std::cout << " wood floor ";
        break;
    default:
        std::cout << " Ivalid task ";
    }
}

void getRoomInformation(int task, float &roomWidth, float &roomDepth, float &roomHeight)
{   //all the tasks require the width and depth.
    //wall treatments require the height also
    std::cout << "What is the room width? \n";
    std::cin >> roomWidth;
    std::cout << "What is the room depth? \n";
    std::cin >> roomDepth;
    if (task == 0 or task == 1)
    {
        std::cout << "What is the room height? \n";
        std::cin >> roomHeight;
    }
}

void printJobInformation(string userName, string phoneNumber, string userAddress, string remodelRoom, int task)
{   //print user information. This is the only place the
    //remodel room string is used
    cout << "\n\nPreparing order for:\n\n"
         << userName << "\n";
    cout << "\t" << phoneNumber << "\n";
    cout << "\t" << userAddress << "\n";
    cout << "\t"
         << "Remodeling the " << remodelRoom << " with";
    printTask(task);
}

float calcWallSurfaceArea(float roomWidth, float roomDepth, float roomHeight)
{                                                //Calculate the wall surface area. Assume the room is rectangluar
                                                 //Assume the two walls opposite each other are the same
    float wallWide = roomWidth * roomHeight * 2; //two walls
    float wallDeep = roomDepth * roomHeight * 2; //two walls
    return wallWide + wallDeep;
}

float calcPaintCost(float wallSurfaceArea)
{ //cost estimates are simply surface area times material per sq. foot
    return PAINTCOST * wallSurfaceArea;
}

float calcWallPaperCost(float wallSurfaceArea)
{ //cost estimates are simply surface area times material per sq. foot
    return WALLPAPERCOST * wallSurfaceArea;
}

void printWallCostComparisons(float paintCost, float wallpaperCost)
{ //print the estimates for the wall coverings
    std::cout << "\nPaint Estimate: " << paintCost << "\n\n";
    std::cout << "Wallpaper Estimate: " << wallpaperCost << "\n\n";
}

float calcFloorArea(float roomWidth, float roomDepth)
{
    return roomWidth * roomDepth;
}
float calcCarpetCost(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    return CARPETCOST * floorArea;
}

float calcTileCost(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    return TILECOST * floorArea;
}

float calcWoodFloor(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    return WOODCOST * floorArea;
}

void printFloorCostComparisons(float carpetCost, float tileCost, float woodFloorCost)
{ //print the estimates for the floor coverings
    cout << "\n\t\tCarpet Estimate: " << carpetCost;
    cout << "\n\t\tTile Estimate: " << tileCost;
    cout << "\n\t\tWood Estimate: " << woodFloorCost;
}

// main.cpp

/*Debug the program so that it executes correctly.
 **This program calculates floor or wall surface areas
 **For the purpose of remodeling estimates. 
 **It asks a user to enter their name, phone, address
 **Then enter the room they wish to remodel
 **The user is asked to select a task
 **then a material. 
 **The program will generate an estimate of 
 **the cost of the project. 
 **
 **The user inputs are in the input.txt file.*/

#include "main.hpp"

int main()
{
    //user information
    string userName = " ";
    string phoneNumber = " ";
    string userAddress = " ";
    string remodelRoom = " ";
    float roomWidth = 0;
    float roomDepth = 0;
    float roomHeight = 0;
    float wallSurfaceArea = 0;
    float floorArea = 0;
    int task = 0;

    //estimate variables
    float paintCost = 0;
    float wallpaperCost = 0;
    float carpetCost = 0;
    float tileCost = 0;
    float woodFloorCost = 0;

    //the possible task list
    enum task
    {
        paint,
        wallpaper,
        carpet,
        tile,
        woodFloor
    };

    getUserInformation(userName, phoneNumber, userAddress);
    remodelRoom = getRoomChoice();
    task = getTaskAssignment();

    getRoomInformation(task, roomWidth, roomDepth, roomHeight);

    //print the information of the user and room
    printJobInformation(userName, phoneNumber, userAddress, remodelRoom, task);

    //If a wall treatment is to be done, get the wall surface area
    //assume all four walls of the room are to be redone
    if (task == paint or task == wallpaper)
    {
        //calculate and print the estimates
        wallSurfaceArea = calcWallSurfaceArea(roomWidth, roomDepth, roomHeight);
        paintCost = calcPaintCost(wallSurfaceArea);
        wallpaperCost = calcWallPaperCost(wallSurfaceArea);
        printWallCostComparisons(paintCost, wallpaperCost);
    }

    //if a floor is to be done, get the square footage of the room
    if (task == carpet or task == tile or task == woodFloor)
    {
        //calculate and print the estimates
        floorArea = calcFloorArea(roomWidth, roomDepth);
        carpetCost = calcCarpetCost(floorArea);
        tileCost = calcTileCost(floorArea);
        woodFloorCost = calcWoodFloor(floorArea);
        printFloorCostComparisons(carpetCost, tileCost, woodFloorCost);
    }
    return 0;
}

/* ouput 
 
Customer Name: 
Customer Phone Number: 
Customer Address: 
What room are we remodeling?: 
What job needs to be done?
0: Paint
1: Wallpaper
2: Carpet
3: Tile
4: Wood Floor
What is the room width? 
What is the room depth? 


Preparing order for:

Happy Gilmore
	(408)665-4321
	432B Main St, Mountain View, CA. 95120
	Remodeling the Living room with tile 
		Carpet Estimate: 1728
		Tile Estimate: 2376
		Wood Estimate: 2592
 
 */