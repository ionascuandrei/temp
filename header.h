struct History{
	int success_fail;
	int new_active_locked;
	struct History *next;
};
typedef struct Hystory HISTORY;
struct Card{
	double card_number;
	int pin[4];
	char expiry[5];
	char cvv[3];
	int balance;
	int status;
	struct Card *next;
};
typedef struct Card LSC;
struct poz{
	int nr;
	struct poz *next;
};
typedef struct poz POZ;