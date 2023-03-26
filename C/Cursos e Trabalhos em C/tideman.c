#include <cs50.h>
#include <stdio.h>
#include <string.h>

// NUMERO MAXIMO DE CANDIDATOS
#define MAX 9

// NUMERO DE ELEITORES QUE PREFEREM I MAIS J
int preferences[MAX][MAX];

// BLOQUEAR MAIS QUE J
bool locked[MAX][MAX];

// PAR VENCEDOR E PERDEDOR
typedef struct
{
int winner;
int loser;
}
pair;

// ARRAY DOS CANDIDATOS
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// PROTOTIPOS DE FUNÇÃO
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
// VOTO INVALIDO
if (argc < 2)
{
printf("DIGITE OS NOMES DOS CANDIDATOS\n");
return 1;
}
// CANDIDATOS POPULARES
candidate_count = argc - 1;
if (candidate_count > MAX)
{
    printf("NUMERO MÁXIMO DE CANDIDATOS É %i\n", MAX);
    return 2;
}
for (int i = 0; i < candidate_count; i++)
{
    candidates[i] = argv[i + 1];
}

for (int i = 0; i < candidate_count; i++)
{
    for (int j = 0; j < candidate_count; j++)
    {
        locked[i][j] = false;
    }
}

pair_count = 0;
int voter_count = get_int("NÚMERO DE ELEITORES: ");

// CONSULTA VOTOS
for (int i = 0; i < voter_count; i++)
{
    int ranks[candidate_count];

    for (int j = 0; j < candidate_count; j++)
    {
        string name = get_string("VENCEDOR %i: ", j + 1);

        if (!vote(j, name, ranks))
        {
            printf("VOTO INVÁLIDO.\n");
            return 3;
        }
    }

    record_preferences(ranks);

    printf("\n");
}

add_pairs();
sort_pairs();
lock_pairs();
print_winner();
return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO- Percorra os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        // Verifique se o nome é válido
        if (strcmp(candidates[i], name) == 0)
        {
            // Atualize a matriz de classificações com preferência de classificação
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO - Avalia o Rank dos eleitores
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            //Atualiza o de eleitores que preferem i ou j.
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = pair_count - 1; i >= 0 ; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if ((preferences[pairs[j].winner][pairs[j].loser]) < (preferences[pairs[j + 1].winner][pairs[j + 1].loser]))
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

// O ciclo verificando a seta que entra em cada candidato
bool cycle(int end, int cycle_start)
{
    // Retorna verdadeiro se houver um ciclo criado - caso base de recursão
    if (end == cycle_start)
    {
        return true;
    }
    // Percorrer os candidatos - caso recursivo
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (cycle(i, cycle_start))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO - Percorrer os pares
    for (int i = 0; i < pair_count; i++)
    {
        // Se a função de ciclo retornar falso, bloqueie o par
        if (!cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO - Vencedor é o candidato que não tem setas apontando pra ele.
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}