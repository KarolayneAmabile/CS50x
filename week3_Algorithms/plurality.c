#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char *name; // a string is a pointer to a array of caracters 
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX]; // is like a array of two dimensions, candidates[name][votes]

// Number of candidates
int candidate_count = 0; // global scope

// Function prototypes
bool vote(char *name); // makes the count of votes
void print_winner(void); // prints the winner

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2) // argc less then 2 means that no argument has passes by CLI
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = 0;
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];
        printf("Vote: ");
        scanf("%s", &name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int maximum = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= maximum)
        {
            maximum = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maximum)
        {
            printf("%s", candidates[i].name);
        }
    }
}