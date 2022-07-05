#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
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
        //printf("Candidate Name:%s\n",candidates[i].name);
        candidates[i].votes = 0;
        //printf("Candidate initial vote:%i\n",candidates[i].votes);
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

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
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = (candidates[i].votes) + 1;
            return true;
        }
    }
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int n = candidate_count;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                int swap = candidates[i].votes;
                string can_swap = candidates[i].name;
                candidates[i].votes = candidates[j].votes;
                candidates[i].name = candidates[j].name;
                candidates[j].votes = swap;
                candidates[j].name = can_swap;
            }
        }
        //printf("Check:%s\n",candidates[i].name);
    }

    // for (int i = 0; i< n; i++)
    // {
    //     printf("Final: %s\n",candidates[i].name);
    //     printf("Votes: %i\n",candidates[i].votes);
    // }
    for (int i = 0; i < n - 1; i++)
    {
        if ((candidates[n - 1].votes) == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    printf("%s\n", candidates[n - 1].name);




    return;
}