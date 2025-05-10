# Algoritmul DPLL pentru Satisfiabilitatea formulelor CNF

Acest program implementează **algoritmul DPLL** (Davis-Putnam-Logemann-Loveland) pentru a determina dacă o formulă logică exprimată în forma normală conjunctivă (FNC) este **satisfiabilă** sau **nesatisfiabilă**. Algoritmul utilizează **propagarea unității** și recursiunea pentru a rezolva formulele FNC.

---

## 📘 Descriere

Algoritmul **DPLL** este o îmbunătățire a algoritmului Davis-Putnam, care se bazează pe tehnica de **propagare a unității** și **împărțirea recursivă** pentru a verifica satisfiabilitatea formulelor FNC.

1. **Propagarea unității**: Dacă o clauză conține un singur literal neasignat, se poate atribui valoarea respectivă variabilei asociate literalului.
2. **Recursivitatea**: Algoritmul alege o variabilă neasignată, o atribuie unei valori și continuă să aplice algoritmul pe formula redusă.
3. Procesul continuă până când formula este satisfiabilă sau nu mai sunt variabile disponibile.

---

## 🛠️ Cum funcționează

1. **Inițializare**: Se citește numărul de variabile și clauze din formula FNC.
2. **Propagarea unității**: Algoritmul încearcă să simplifice formula prin propagarea literaliilor unitare.
3. **Recursivitate**: Dacă formula nu este satisfăcută, alegem o variabilă neasignată și încercăm ambele valori (adevărat și fals) pentru aceasta.
4. **Stop**: Dacă ajungem la o formulă satisfăcută, algoritmul returnează adevărat. Dacă toate opțiunile sunt explorate și nu găsim o soluție, algoritmul returnează fals.

---

## 🧑‍💻 Compilare și rulare

```bash
gcc dpll.c -o dpll
./dpll
