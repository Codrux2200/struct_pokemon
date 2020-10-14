/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/
#include <stdlib.h>
typedef struct pokemonidentity  pokemonidentity;
struct pokemonidentity 
{
    char *name;
    char *type;
    int damage;
    int life;
};

int my_put_nbr(int nb);

void my_put_str(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}

char *my_strdup(char *str)
{
    int i = 0;
    char *fin = NULL;

    for (; str[i] != '\0'; i++);
    fin = malloc((i+1) * sizeof(char));
    for (i = 0; str[i] != '\0'; i++)
        fin[i] = str[i];
    fin[i + 1] = '\0';
    return fin;
}

pokemonidentity *writecard(char *name, char *type , int dmg, int hp)
{
    pokemonidentity *card = malloc(sizeof(pokemonidentity));

    card->name = my_strdup(name);
    card->type = my_strdup(type);
    card->damage = dmg;
    card->life = hp;
    return (card);
}

void print_card(pokemonidentity *card)
{
    my_put_str("Name: ");
    my_put_str(card->name);
    my_put_str("\nType: ");
    my_put_str(card->type);
    my_put_str("\nLvl: ");
    my_put_nbr(card->damage);
    my_put_str("\nHP: ");
    my_put_nbr(card->life);
    my_put_str("\n");
}

void shout(pokemonidentity *card)
{
    my_put_str(card->name);
    my_put_str(": ");
    my_put_str("piiikkkaaaattcchoou");
    my_put_str("\n");
}


void fight(pokemonidentity *card)
{
    my_put_str(card->name);
    my_put_str(" deals ");
    my_put_nbr(card->damage);
    my_put_str("dmg.");
    my_put_str("\n");
}

typedef void (*fptr)(pokemonidentity *card);
fptr ftab[3];

int main(int ac , char **av){
    ftab[0] = &print_card;
    ftab[1] = &shout;
    ftab[2] = &fight;
    
    for (int i = 0; i != ac ; i++){
        if (av[i][0] == 's'){
            ftab[1](writecard("pikachu", "electrique", 18, 155));
            my_put_str("\n");
        }
        if (av[i][0] == 'p'){
            ftab[0](writecard("pikachu", "electrique", 18, 155));
            my_put_str("\n");
        }
        if (av[i][0] == 'f'){
            ftab[2](writecard("pikachu", "electrique", 18, 155));
            my_put_str("\n");
        }
    }
}