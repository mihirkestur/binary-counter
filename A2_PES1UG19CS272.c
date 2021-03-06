//Name    : Mihir Madhusudan Kestur   SRN     : PES1UG19CS272     Section : E     Semester: 4
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assignment_2.h"
//this structure is for the list, which is used to keep track of the losers of the winners
typedef struct player_node{
    int data;
    struct player_node *next_player;
}player;
//this structure is used to keep track of the different list of matches
typedef struct list_of_matches{
    struct list_of_matches *next_match_list, *previous_match_list;
    struct player_node *winner;
}tournament;
//used to create a node ("player") which holds the number and the next node to a loser
static player *create_player(int number){
    player *new_player = (player *)malloc(sizeof(player));
    new_player->data = number;
    new_player->next_player = NULL;
    return new_player;
}
//this initializes the adjacency list with number of list of matches = matches
static tournament *initialize_tournament(int matches){
    tournament *new_match_list_head = (tournament *)malloc(sizeof(tournament)),*temp_list;
    new_match_list_head->winner = NULL;
    new_match_list_head->previous_match_list = NULL;
    new_match_list_head->next_match_list = NULL;
    temp_list = new_match_list_head;
    for(int i = 0; i < matches-1; i++){
        tournament *new_match_list = (tournament *)malloc(sizeof(tournament));
        new_match_list->winner = NULL;
        new_match_list->previous_match_list = temp_list;
        new_match_list->next_match_list = NULL;
        temp_list->next_match_list = new_match_list;
        temp_list = new_match_list;
    }
    return new_match_list_head;
}
//this function is used to search the final list for the second largest element and display it
static void display_second_largest(player *final_list){
    int second_largest = final_list->data;
    while(final_list != NULL){
        if(final_list->data > second_largest){
            second_largest = final_list->data;
        }
        final_list = final_list->next_player;
    }
    printf("\n%d\n",second_largest);
}
//this function prints the LHS of the match between two different lists in the desired format
static void arrange_match(player *player_1, player *player_2){
    //traverse the list and print it 
    player *temp_player;
    temp_player = player_2;
    while(temp_player != NULL){
        printf("%d ",temp_player->data);
        temp_player = temp_player->next_player;
    }
    printf("X ");
    temp_player = player_1;
    while(temp_player != NULL){
        printf("%d ",temp_player->data);
        temp_player = temp_player->next_player;
    }
    printf("= ");
}
//this function finds the winner between two match lists and returns the modified match list
static player *find_winner(player *player_1, player *player_2){
    player *winner,*loser,*loser_of_this_winner;
    //find the winner, form a new list having the losers of the winner and then return it
    if(player_1->data > player_2->data){ 
        printf("%d %d ",player_1->data,player_2->data);
        winner = create_player(player_1->data);
        winner->next_player = create_player(player_2->data);
        loser = winner->next_player; 
        loser_of_this_winner = player_1->next_player;
        while(loser_of_this_winner != NULL){
            printf("%d ",loser_of_this_winner->data);
            loser->next_player = create_player(loser_of_this_winner->data);
            loser = loser->next_player;
            loser_of_this_winner = loser_of_this_winner->next_player;
        }
    }
    else{
        printf("%d %d ",player_2->data,player_1->data);
        winner = create_player(player_2->data);
        winner->next_player = create_player(player_1->data);
        loser = winner->next_player; 
        loser_of_this_winner = player_2->next_player;
        while(loser_of_this_winner != NULL){
            printf("%d ",loser_of_this_winner->data);
            loser->next_player = create_player(loser_of_this_winner->data);
            loser = loser->next_player; 
            loser_of_this_winner = loser_of_this_winner->next_player;
        }
    }
    printf("\n");
    return winner;
}
//this function prints LHS and RHS for every two new players in the array
static void first_match(int first, int second, tournament *list){
    printf("%d X %d = %d %d\n", first, second, list->winner->data, list->winner->next_player->data);
}
//main function to find the second largest element in the given array
void find_second_greatest(int *numbers, int length){
    //finding the number matches to be played and initializing the adjacency list
    int matches = ceil(log(length)/log(2)) + 1, flag = 0;
    tournament *match_list_head = initialize_tournament(matches),*match_list = match_list_head;
    //if number of elements is odd, reduce length by 1 and set flag to 1 to run the logic once more
    if(length % 2 != 0){
        length = length - 1;
        flag = 1;
    }
    //accessing all elements in the array two at a time
    for(int i = 0; i < length; i = i + 2){
        match_list = match_list_head;
        //comparing the two numbers and creating a list
        if(numbers[i] > numbers[i+1]){
            match_list->winner = create_player(numbers[i]);
            match_list->winner->next_player = create_player(numbers[i+1]);
        }
        else{
            match_list->winner = create_player(numbers[i+1]);
            match_list->winner->next_player = create_player(numbers[i]);
        }
        //play match between the two incoming consecutive elements
        first_match(numbers[i],numbers[i+1],match_list);
        //arrange match between two different match lists if another match list exists
        match_list = match_list_head->next_match_list;
        while(match_list->winner != NULL){
            arrange_match(match_list->previous_match_list->winner, match_list->winner);
            match_list->winner = find_winner(match_list->previous_match_list->winner, match_list->winner);
            match_list->previous_match_list->winner = NULL;
            match_list = match_list->next_match_list;
        }
        match_list->winner = match_list->previous_match_list->winner;
        match_list->previous_match_list->winner = NULL;
    }
    //if odd number of elements, run the logic once more to account for the last element
    if(flag){
        match_list = match_list_head;
        match_list->winner = create_player(numbers[length]);
        //arrange match between two different match lists if another match list exists
        match_list = match_list_head->next_match_list;
        while(match_list->winner != NULL){
            arrange_match(match_list->previous_match_list->winner, match_list->winner);
            match_list->winner = find_winner(match_list->previous_match_list->winner, match_list->winner);
            match_list->previous_match_list->winner = NULL;
            match_list = match_list->next_match_list;
        }
        match_list->winner = match_list->previous_match_list->winner;
        match_list->previous_match_list->winner = NULL;
    }
    //once all the elements in the array has played at least one match, traverse list to find first non-NULL match list
    match_list = match_list_head;
    player *final_match_list;
    while(match_list != NULL){
        if(match_list->winner != NULL){
            final_match_list = match_list->winner;
            break;
        }
        match_list = match_list->next_match_list;
    }
    /*arrange matches between the first non-NULL match list and all other non-NULL match lists remaining 
    to finally obtain only 1 match list called the final_match_list*/
    match_list = match_list->next_match_list;
    while(match_list != NULL){
        if(match_list->winner != NULL){
            if(match_list->winner->data > final_match_list->data){
                arrange_match(match_list->winner,final_match_list);
                match_list->winner = find_winner(match_list->winner,final_match_list);
                final_match_list = match_list->winner;
            }
            else{
                arrange_match(final_match_list,match_list->winner);
                final_match_list = find_winner(final_match_list,match_list->winner);
            }
        }
        match_list = match_list->next_match_list;
    }
    //since we know first element is the greatest element, passing the next node reduces the number of comparisons
    display_second_largest(final_match_list->next_player);
}