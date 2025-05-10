# Algoritmul de Rezoluție (CNF Resolution Algorithm)

Acest program implementează **algoritmul de rezoluție** pentru a determina dacă o formulă logică exprimată în forma normală conjunctivă (CNF) este **satisfiabilă** sau **nesatisfiabilă**.

---

## 📌 Descriere

Algoritmul aplică regula de rezoluție pe toate perechile posibile de clauze dintr-o formulă logică. Dacă în urma aplicării regulii de rezoluție se obține clauza vidă, atunci formula este **nesatisfiabilă**. În caz contrar, formula poate fi **satisfiabilă**.

---

## 🧠 Cum funcționează

Fiecare clauză este reprezentată ca un set de literali (numere întregi, unde `-x` înseamnă negația variabilei `x`). Algoritmul parcurge perechile de clauze, căutând un literal și negația sa. Dacă o astfel de pereche este găsită, clauzele sunt combinate (rezolvate), iar noua clauză este adăugată doar dacă este diferită de cele existente.

---

## 🛠️ Compilare și rulare

```bash
gcc resolution.c -o resolution
./resolution
