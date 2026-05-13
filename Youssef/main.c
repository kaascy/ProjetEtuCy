#include <stdio.h>
#include "deck/deck.h"
#include "player/player.h"
#include "rules/rules.h"
#include "game/round.h"
#include "game/game.h"
#include "ui/display.h"
#include "ui/input.h"
#include "save/save.h"
#include "stats/stats.h"
 
int main()
{
    Deck deck;
    Player players[10];
    int nbPlayers;
    int i;
    char nomJoueur[50];
 
    printf("\n  ====================================\n");
    printf("       Bienvenue dans FLIPTECH !\n");
    printf("  ====================================\n\n");
 
    // initialize and shuffle the deck
    deck_init(&deck);
    deck_shuffle(&deck);
    printf("  Deck pret : %d cartes melangees.\n\n", deck.size);
 
    // ask for the number of players
    nbPlayers = safe_input_int("Combien de joueurs ?", 1, 10);
 
    // ask for each player's name and initialize
    for (i = 0; i < nbPlayers; i++) {
        printf("  Nom du joueur %d", i + 1);
        safe_input_string(nomJoueur, sizeof(nomJoueur), "");
        player_init(&players[i], nomJoueur);
    }
 
    printf("\n  La partie commence ! Bonne chance.\n\n");
 
    // launch the game loop
    game_run(&deck, players, nbPlayers);
 
    // show winner
    display_winner(players, nbPlayers);
 
    // offer to save
    if (safe_input_yes_no("Voulez-vous enregistrer les scores ? (oui/non)"))
        save_scores_to_file(players, nbPlayers);
 
    // propose the statistics
    if (safe_input_yes_no("Voulez-vous voir les statistiques ? (oui/non)")) {
        printf("\n  --- Statistiques ---\n");
        stats_display_best_player(players, nbPlayers);
        stats_display_average_scores(players, nbPlayers);
        stats_display_all_scores(players, nbPlayers);
    }
 
    printf("  Merci d'avoir joue a FlipTech !\n\n");
    return 0;
}