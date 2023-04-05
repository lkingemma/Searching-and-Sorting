// Emma King 
// This program searches and sorts zip codes and towns.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


// Function prototypes
void readFromFile(string zipCode[], string townName[], int& counter);
void displayZipTown(const string zipCode[], const string townName[], int size);
void bubbleSort(string zipCode[], string townName[], int size);
int linearSearch(const string zipCode[], const string searchZipCode, int size);

int main() 
{    
    const int MAX_SIZE = 50;
    string zipCode[MAX_SIZE];
    string townName[MAX_SIZE];
    int counter = 0;
    int index = -1;
    string searchZipCode;
  
    // Read data from file
    readFromFile(zipCode, townName, counter);
  
    // Display the zip codes and town names
    // displayZipTown(zipCode, townName, counter);

    // Sort the arrays by zip code
    bubbleSort(zipCode, townName, counter);

    // Display the sorted zip codes and town names
    displayZipTown(zipCode, townName, counter);

    // Prompt the user to enter a zip code
    cout << "Enter a zip code: ";
    cin >> searchZipCode;

    // Search for the zip code and display the corresponding town name
    index = linearSearch(zipCode, searchZipCode, counter);
    if (index != -1)
    {
        cout << "The town name is " << townName[index] << endl;
    } 
    else 
    {
        cout << "The zip code you searched for cannot be located" << endl;
    }

    return 0;
}

// Open the input file
void readFromFile(string zipCode[], string townName[], int& counter)
{
    ifstream inFile;
    inFile.open("zipInfo.txt");

    if (!inFile) 
    {
        cout << "Could not open file." << endl;
        exit(-1);
    }

    // Read data from the file into the parallel arrays
    while (!inFile.eof()) 
    {
        inFile >> zipCode[counter];
        inFile.get();
        getline(inFile, townName[counter]);
        counter++;
    }

    // Close the input file
    inFile.close();
}

// Display the zip codes and town names in a table
void displayZipTown(const string zipCode[], const string townName[], int size) 
{
  
    cout  << left << setw(12) << "Zip Code" << "Town Name\n\n";
    for (int i = 0; i < size; i++) 
    {
        cout << setw(12) << zipCode[i] << townName[i] << endl;
    }
    cout << endl;
}

// Sort the array by zip code using bubble sort
void bubbleSort(string zipCode[], string townName[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (zipCode[j] > zipCode[j+1]) 
            {
                swap(zipCode[j], zipCode[j+1]);
                swap(townName[j], townName[j+1]);
            }
        }
    }
}

// Search for a zip code in an array using linear search
int linearSearch(const string zipCode[], const string searchZipCode, int size) 
{

    for (int i = 0; i < size; i++) 
    {
        if (zipCode[i] == searchZipCode) 
        {
            return i;
        }
    }
    return -1;
}
