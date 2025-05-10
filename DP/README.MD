# Algoritmul Davis-Putnam pentru Satisfiabilitatea formulelor CNF

Acest program implementează **algoritmul Davis-Putnam** pentru a determina dacă o formulă logică exprimată în forma normală conjunctivă (FNC) este **satisfiabilă** sau **nesatisfiabilă**, folosind eliminarea literaliilor pure și rezoluția simbolică.

---

## 📘 Descriere

- Algoritmul **Davis-Putnam** încearcă să determine satisfiabilitatea unei formule logice folosind două tehnici:
  - Eliminarea literaliilor pure.
  - Aplicarea rezoluției simbolice pe clauze.
  
- Algoritmul continuă să aplice aceste tehnici până când:
  - Se ajunge la o formulă goală (indicând satisfiabilitate).
  - Sau se găsește o clauză goală (indicând nesatisfiabilitate).

---

## 🛠️ Cum funcționează

1. **Eliminarea literaliilor pure**: Dacă o variabilă apare numai într-o formă (pozitivă sau negativă) în toate clauzele, aceasta este eliminată din formulă.
2. **Rezoluția simbolică**: Se alege o variabilă și se elimină clauzele care o conțin, generând o formulă mai mică.
3. Repetarea acestui proces până la o formulă goală sau o clauză goală.

---

## 🧑‍💻 Compilare și rulare

```bash
gcc davis_putnam.c -o davis_putnam
./davis_putnam
