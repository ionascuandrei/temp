struct History{
	int success_fail;
	int new_active_locked;
	struct History *next;
};
typedef struct Hystory HISTORY;
struct Card{
	long int card_number;
	char *pin;
	char *expiry;
	char *cvv;
	int balance;
	char status[6];
	struct Card *next;
};
typedef struct Card LSC;
struct poz{
	int nr;
	LSC *card_curent;
	HISTORY *history_card_curent;
	struct poz *next;
};
typedef struct poz POZ;
