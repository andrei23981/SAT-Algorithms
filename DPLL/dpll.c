#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VARS 100
#define MAX_CLAUSES 500
#define MAX_LITERALS 100

typedef struct {
    int literals[MAX_LITERALS];
    int size;
} Clause;

typedef struct {
    Clause clauses[MAX_CLAUSES];
    int numClauses;
    int numVars;
} CNF;

int assignment[MAX_VARS + 1]; // -1 = neasignat, 0 = fals, 1 = adevărat

bool isClauseSatisfied(Clause* c) {
    for (int i = 0; i < c->size; i++) {
        int lit = c->literals[i];
        int var = abs(lit);
        if (assignment[var] == -1) continue;
        if ((lit > 0 && assignment[var] == 1) || (lit < 0 && assignment[var] == 0))
            return true;
    }
    return false;
}

bool unitPropagation(CNF* cnf) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < cnf->numClauses; i++) {
            Clause* c = &cnf->clauses[i];
            if (isClauseSatisfied(c)) continue;

            int unassigned = 0, unit = 0;
            for (int j = 0; j < c->size; j++) {
                int var = abs(c->literals[j]);
                if (assignment[var] == -1) {
                    unassigned++;
                    unit = c->literals[j];
                }
            }
            if (unassigned == 1) {
                int var = abs(unit);
                assignment[var] = (unit > 0) ? 1 : 0;
                changed = true;
            } else if (unassigned == 0 && !isClauseSatisfied(c)) {
                return false;
            }
        }
    }
    return true;
}

bool dpll(CNF* cnf) {
    if (!unitPropagation(cnf))
        return false;

    for (int i = 0; i < cnf->numClauses; i++) {
        if (!isClauseSatisfied(&cnf->clauses[i])) {
            int var = 0;
            for (int v = 1; v <= cnf->numVars; v++) {
                if (assignment[v] == -1) {
                    var = v;
                    break;
                }
            }
            if (var == 0)
                return false;

            for (int val = 1; val >= 0; val--) {
                assignment[var] = val;
                if (dpll(cnf)) return true;
                assignment[var] = -1;
            }
            return false;
        }
    }
    return true;
}

int main() {
    CNF cnf;
    printf("Numar variabile: ");
    scanf("%d", &cnf.numVars);
    printf("Numar clauze: ");
    scanf("%d", &cnf.numClauses);

    for (int i = 0; i < cnf.numClauses; i++) {
        printf("Clauza %d (literal(i) separati de spatiu, terminati cu 0): ", i + 1);
        cnf.clauses[i].size = 0;
        int lit;
        while (scanf("%d", &lit) && lit != 0) {
            cnf.clauses[i].literals[cnf.clauses[i].size++] = lit;
        }
    }

    for (int i = 0; i <= cnf.numVars; i++)
        assignment[i] = -1;

    if (dpll(&cnf)) {
        printf("Formula este satisfiabila.\nAsignare:\n");
        for (int i = 1; i <= cnf.numVars; i++)
            printf("x%d = %s\n", i, assignment[i] == 1 ? "adevarat" : "fals");
    } else {
        printf("Formula NU este satisfiabila.\n");
    }

    return 0;
}