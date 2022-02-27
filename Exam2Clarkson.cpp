#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int getNumCandidates();
long getNumVoters();
void displayStats(long[], double[], long);
void calcWinner(long[], int);

int main()
{
    srand(time(0));     // seed random numbers

    int numCandidates;   // the number of candidates that will be entered by the user
    double numVoters;      // the number of voters that will be entered by the user

    numCandidates = getNumCandidates();     // call function to get input number of candidates
    numVoters = getNumVoters();


    // arrays to hold the votes and percentages
    long candidateVotes[numCandidates];
    double votePercentages[numCandidates];

    // for loop to populate the candidateVotes[] array for each caddidate with random numbers
    for (int i = 0; i < numCandidates; i++)
    {
        candidateVotes[i] = 0;

        int maxvalue = (int)numVoters;
        candidateVotes[i] = 1 + rand() % maxvalue;

    }


    // for loop to populate votePercentages[] array for each candidate
    for (int i = 0; i < numCandidates; i++)
    {
        votePercentages[i] = candidateVotes[i] / numVoters;
    }

    displayStats(candidateVotes, votePercentages, numCandidates);   // call funtion to display stats
    calcWinner(candidateVotes, numCandidates);     // call function to calcuate winner

}

/*
    Definition of function getNumCandidates()
    This function must allow the user to specify the number of candidates in the simulated election.
    The minimum simulation is 2 and maximum simulation is 5. Validate the user input so that the
    number of cadidates is between 2 and 5. Return the validated input as an integer.
*/

int getNumCandidates()
{
    int candidates;     // local variable to hold input number of candidates
    cout << "\nHow many candidates are running? (Min: 2 Max: 5): ";
    cin >> candidates;
    // validate the user input
    while (candidates < 2 or candidates > 5)
    {
        cout << "\n\nERROR: Must enter between 2 and 5 candidates.";
        cout << "\nHow many candidates are running? (Min: 2 Max: 5): ";
        cin >> candidates;
    }

    return candidates;
}

/*
    Definition of getNumVoters function
    This function allows the user to specify the number of voters in the simualted election.
    The simulation can do between 1 and 300,000,000 voters. Validate the user input and
    return the validated input as a long.
*/

long getNumVoters()
{
    long voters; // local variable to hold the number of voters input

    cout << "\n\nHow many voters are voting? (Min: 1 Max: 300000000): ";
    cin >> voters;

    // validate the user input
    while (voters < 1 or voters > 300000000)
    {
        cout << "\n\nERROR: Must enter between 1 and 300000000 voters.";
        cout << "\nHow many voters are voting? (Min: 1 Max: 300000000): ";
        cin >> voters;
    }
    return voters;
}

/*
    Define function displayStats()
    This function accepts parallel arrays that contain the cadidate votes and vote pecentages
    as well as the number of voters. Display the candidate number along with stats for each
    candidate
*/

void displayStats(long candidateVotes[], double votePercentages[], long numCandidates)
{
    cout << fixed << showpoint << setprecision(2); // decimal place formatting
    // column headers
    cout << endl << endl << setw(10) << "Candidate" << setw(16) << "Votes" << setw(17) << "% of Votes\n";
    // display the votes and % votes for each candidate
    for (int i = 0; i < numCandidates ; i++)
    {
        cout << "Candidate #" << (i + 1)  << setw(15) << candidateVotes[i] << setw(15)
                << (votePercentages[i] * 100) << endl;
    }
}

/*
    Define the function calcWinner()
    This function accepts the array that contains the number of cadidate votes and the number
    of candidates entered and displays the candidate with the most votes
*/

void calcWinner(long candidateVotes[], int numCandidates)
{
    int mostVotes = candidateVotes[0]; // initialize to first value of array
    int mostIndex = 0;

    // loop through array to find candidate with maxiumum value of votes
    for (int i = 1; i < numCandidates; i++)
    {
        if (candidateVotes[i] > mostVotes) // compare the current value against the current maximum value
        {
            mostVotes = candidateVotes[i];
            mostIndex = i; // update index when new maximum is found
        }
    }
    cout << "\n\nElection Winner\n";
    cout << "Candidate #" << (mostIndex + 1) << setw(15) << mostVotes << " votes" << endl;
}
