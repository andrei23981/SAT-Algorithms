#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CLAUSES 100
#define MAX_LITERALS 20
typedef struct {
    int literals[MAX_LITERALS];
    int size;
} Clause;
Clause formula[MAX_CLAUSES];
int num_clauses = 0;
bool is_pure(int var) {
    bool seen_pos = false, seen_neg = false;
    for (int i = 0; i < num_clauses; ++i) {
        for (int j = 0; j < formula[i].size; ++j) {
            if (formula[i].literals[j] == var) seen_pos = true;
            if (formula[i].literals[j] == -var) seen_neg = true;
        }
    }
    return (seen_pos ^ seen_neg); // doar unul dintre ele apare
}
void eliminate_pure_literals() {
    for (int v = 1; v <= 10; ++v) {
        if (is_pure(v)) {
            int new_size = 0;
            for (int i = 0; i < num_clauses; ++i) {
                bool found = false;
                for (int j = 0; j < formula[i].size; ++j) {
                    if (formula[i].literals[j] == v || formula[i].literals[j] == -v) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    formula[new_size++] = formula[i];
                }
            }
            num_clauses = new_size;
        }
    }
}
bool is_empty_clause(Clause c) {
    return c.size == 0;
}
bool is_formula_empty() {
    return num_clauses == 0;
}
bool has_empty_clause() {
    for (int i = 0; i < num_clauses; ++i) {
        if (is_empty_clause(formula[i])) return true;
    }
    return false;
}
bool davis_putnam() {
    while (true) {
        eliminate_pure_literals();
        if (is_formula_empty()) return true;         // satisfiabil
        if (has_empty_clause()) return false;        // nesatisfiabil
        // alegem prima variabilă și facem rezoluție (simbolic)
        int var = abs(formula[0].literals[0]);
        Clause new_formula[MAX_CLAUSES];
        int new_size = 0;
        // aplicăm rezoluția pentru variabilă
        for (int i = 0; i < num_clauses; ++i) {
            bool skip = false;
            for (int j = 0; j < formula[i].size; ++j) {
                if (formula[i].literals[j] == var || formula[i].literals[j] == -var) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                new_formula[new_size++] = formula[i];
            }
        }
        for (int i = 0; i < new_size; ++i) {
            formula[i] = new_formula[i];
        }
        num_clauses = new_size;
    }
}
int main() {
    printf("Numar clauze: ");
    scanf("%d", &num_clauses);
    for (int i = 0; i < num_clauses; ++i) {
        printf("Numar literali in clauza #%d: ", i + 1);
        scanf("%d", &formula[i].size);
        printf("Introdu literalii: ");
        for (int j = 0; j < formula[i].size; ++j) {
            scanf("%d", &formula[i].literals[j]);
        }
    }
    if (davis_putnam()) {
        printf("\nFormula este SATISFIABILĂ.\n");
    } else {
        printf("\nFormula este NESATISFIABILĂ.\n");
    }
    return 0;
}