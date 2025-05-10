#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CLAUSES 100
#define MAX_LITERALS 20
typedef struct {
    int literals[MAX_LITERALS];
    int size;
} Clause;
Clause clauses[MAX_CLAUSES];
int num_clauses = 0;
bool is_complement(int a, int b) {
    return a == -b;
}
bool clause_equals(Clause *a, Clause *b) {
    if (a->size != b->size) return false;
    for (int i = 0; i < a->size; ++i) {
        bool found = false;
        for (int j = 0; j < b->size; ++j) {
            if (a->literals[i] == b->literals[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}
bool clause_empty(Clause *c) {
    return c->size == 0;
}
bool clause_exists(Clause *c) {
    for (int i = 0; i < num_clauses; ++i) {
        if (clause_equals(c, &clauses[i])) return true;
    }
    return false;
}
void print_clause(Clause *c) {
    for (int i = 0; i < c->size; ++i) {
        printf("%d ", c->literals[i]);
    }
    printf("\n");
}
bool resolve() {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < num_clauses; ++i) {
            for (int j = i + 1; j < num_clauses; ++j) {
                for (int a = 0; a < clauses[i].size; ++a) {
                    for (int b = 0; b < clauses[j].size; ++b) {
                        if (is_complement(clauses[i].literals[a], clauses[j].literals[b])) {
                            Clause res;
                            res.size = 0;
                            for (int k = 0; k < clauses[i].size; ++k) {
                                if (k != a) res.literals[res.size++] = clauses[i].literals[k];
                            }
                            for (int k = 0; k < clauses[j].size; ++k) {
                                if (k != b) {
                                    bool duplicate = false;
                                    for (int m = 0; m < res.size; ++m) {
                                        if (res.literals[m] == clauses[j].literals[k]) {
                                            duplicate = true;
                                            break;
                                        }
                                    }
                                    if (!duplicate) res.literals[res.size++] = clauses[j].literals[k];
                                }
                            }

                            if (clause_empty(&res)) {
                                return true; // clauza vidă
                            }

                            if (!clause_exists(&res)) {
                                clauses[num_clauses++] = res;
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    printf("Introdu numarul de clauze: ");
    scanf("%d", &num_clauses);

    for (int i = 0; i < num_clauses; ++i) {
        printf("Clauza #%d: Introdu numarul de literali: ", i + 1);
        scanf("%d", &clauses[i].size);
        printf("Introdu literalii (ex: 1 -2 3): ");
        for (int j = 0; j < clauses[i].size; ++j) {
            scanf("%d", &clauses[i].literals[j]);
        }
    }

    bool rezultat = resolve();
    if (rezultat) {
        printf("\nFormula este NESATISFIABILĂ (s-a generat clauza vidă).\n");
    } else {
        printf("\nFormula este POSIBIL SATISFIABILĂ (nu s-a generat clauza vidă).\n");
    }

    return 0;
}