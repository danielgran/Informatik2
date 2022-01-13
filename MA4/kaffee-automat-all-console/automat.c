/**********************************************************************\
 * Kurzbeschreibung: automat.c
 * Stellt Funktionen zur Realisierung eines Automaten zur Verf�gung,  
 * die �ber die in der automat.h vorgegebene C-Schnittstelle 
 * mit einer grafischen Schnittstelle kommunizieren. 
 *
 * Datum:       Autor:        Grund der Aenderung:
 * 
 *
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "automat.h"

/*--- #defines -------------------------------------------------------*/
/* Macro zur Ermittlung der Array Groesse */
#define SIZE_OF(a) (sizeof((a))/ sizeof(*(a)))

#define NR_OF_STATES        (I-A + 1)

/*--- Datentypen (typedef) -------------------------------------------*/
/* Definition der Zustaende */
typedef enum {A=0,B,C,D,E,F,G,H,I} state_t; 

/* Definition der fsm-spezifischen Variablen */
/* Struktur zur Beschreibung eines Uebergangs mit "Don't Care"-Moeglichkeit */
typedef struct {
    int       input;
    int       mask;
    state_t   nxtstate;
} fsm_state_t;

/* Struktur zur Beschreibung aller Uebergaenge eines Zustands */
typedef struct {
    const fsm_state_t * transitions;
    int                 nrOfTransitions;
    state_t             defaultNxtState;
} fsm_full_state_t;

/*--- Modulglobale static Variablen ----------------------------------*/
/* Definition der Zustandsvariablen */
static state_t s_curstate = A; /* Initialisierung */

/* Definition aller Zustandsuebergaenge fuer jeden Zustand */
static const fsm_state_t s_transitions_A[] =
{ /*    input   mask      nxtstate */
  {     0b110,  0b100,   B },
  {     0b111,  0b100,   C }
};

static const fsm_state_t s_transitions_B[] =
{ /*    input   mask      nxtstate */
  {     0b110,  0b100,   C },
  {     0b111,  0b100,   D }
};

static const fsm_state_t s_transitions_C[] =
{ /*    input   mask      nxtstate */
  {     0b110,  0b100,   D },
  {     0b011,  0b000,   F },
  {     0b111,  0b000,   H }
};

static const fsm_state_t s_transitions_D[] =
{ /*    input   mask      nxtstate */
  {     0b010,  0b000,   F },
  {     0b111,  0b100,   E },
  {     0b110,  0b000,   H }
};

static const fsm_state_t s_transitions_E[] =
{ /*    input   mask      nxtstate */
  { 0b101, 0b101, D },
  { 0b101, 0b010, E },
  { 0b010, 0b000, F },
  { 0b110, 0b000, H }
};

static const fsm_state_t s_transitions_F[] =
{ /*    input   mask      nxtstate */
  { 0b000, 0b001, F },
  { 0b011, 0b001, G },
  { 0b101, 0b001, H },
  { 0b111, 0b001, I }
};

static const fsm_state_t s_transitions_G[] =
{ /*    input   mask      nxtstate */
  /* TODO   */
  { 0b001, 0b001, F },
  { 0b011, 0b001, G },
  { 0b101, 0b001, H },
  { 0b111, 0b001, I }

};

static const fsm_state_t s_transitions_H[] =
{ /*    input   mask      nxtstate */
  /* TODO   */
  { 0b001, 0b001, A },
  { 0b010, 0b000, B },
  { 0b011, 0b000, C },
  { 0b111, 0b001, I }
};

static const fsm_state_t s_transitions_I[] =
{ /*    input   mask      nxtstate */
  /* TODO   */
  { 0b001, 0b001, A },
  { 0b010, 0b000, B },
  { 0b011, 0b000, C },
  { 0b101, 0b001, H },
  { 0b111, 0b001, I }
};

/* Definition der Uebergangstabelle */
/* Die Reihenfolge der Zustaende in der enum Definition muss der
 * Reihenfolge der Zustaende in der Uebergangstabelle entsprechen
 *                 [Zeile] [Spalte] */
static const fsm_full_state_t s_state_table[NR_OF_STATES] =
{
    /* transitions     nrOfTransitions           defaultNxtState */
    { s_transitions_A, SIZE_OF(s_transitions_A), A },
    { s_transitions_B, SIZE_OF(s_transitions_B), B },
    { s_transitions_C, SIZE_OF(s_transitions_C), C },
    { s_transitions_D, SIZE_OF(s_transitions_D), D },
    { s_transitions_E, SIZE_OF(s_transitions_E), E },
    { s_transitions_F, SIZE_OF(s_transitions_F), F },
    { s_transitions_G, SIZE_OF(s_transitions_G), G },
    { s_transitions_H, SIZE_OF(s_transitions_H), H },
    { s_transitions_I, SIZE_OF(s_transitions_I), I }
};

/* Definition der Ausgaenge */
static const fsm_action_t s_out_table[NR_OF_STATES] = 
{
    /* display    muenz_rueck   kaffee_los     guthaben,   display_string */
    /* state A */
    {   false,       false,       false,          0,          "Warten" },     

    /* state B */
    {   false,       false,       false,          1,          "1 Euro" },

    /* state C */               
    {   false,       false,       false,          2,          "2 Euro" },      

    /* state D */         
    {   false,       false,       false,          3,          "3 Euro" },

    /* state E */               
    {   false,       true,       false,          3,          "3 Euro, Rück" },

    /* state F */               
    {   true,       false,       false,          4,          "4 Euro" },           

    /* state G */ 
    {   true,       true,       false,          4,          "4 Euro, Rück" },  

    /* state H */
    {   true,       false,       true,          0,          "Kaffee" },    

    /* state I */ 
    {   true,       true,       true,          0,          "Kaffee, Rück" }
};

/*--- Funktionsdefinition --------------------------------------------*/
void automat_reset(void)
{
    printf("---- automat_reset ----\n");
    
    
    s_curstate = A;
}

/*--- Funktionsdefinition --------------------------------------------*/
void automat_transition(BOOL becher, BOOL muenze, BOOL muenz_wert)
{
  printf("---- automat_transition becher(%0d) muenze(%0d) muenz_wert(%0d) ----\n",
           becher, muenze, muenz_wert);
    
  int i=0, x=0, y=0;

	y = becher<<2 | muenze<<1 | muenz_wert;

	for (x=0; x<s_state_table[s_curstate].nrOfTransitions; x++) {
		i = y | s_state_table[s_curstate].transitions[x].mask; // Uebergebenes maskieren
		if (s_state_table[s_curstate].transitions[x].input == i) {
			s_curstate = s_state_table[s_curstate].transitions[x].nxtstate;
			break;
		}
	}
}

/*--- Funktionsdefinition --------------------------------------------*/
fsm_action_t automat_output(void)
{
    return s_out_table[s_curstate];
}
