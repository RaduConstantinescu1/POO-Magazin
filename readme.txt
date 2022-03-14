Cerinta 3:
a. Parcurg lista de produse si adaug intr-o noua lista produsele a caror categorie este "espressor" si este de tipul "DiscountedProduct".
b. Parcurg lista de useri si ii adaug in lista pe cei de tip "BasicUser" avand costul de transport <11.5lei.
c. Folosesc dynamic_cast pentru produsele de tip "ResealedProduct" pentru a avea acces la metodele clasei si ii adaug in lista pe cei avand motivul "lipsa_accesorii". Implementez in clasa utility functia compareResealedProduct, dupa care sortez lista.
d. Analog ex. c.
e. Introduc toti userii intr-o variabila de tip map<string,int>. Astfel, in map voi avea elemente de tip (nume judet,nr. de util.). Caut elementul cu nr. maxim, parcurg lista de useri si ii introduc pe aceia cu aceeasi adresa de facturare/livrare, care stau la casa, din judetul gasit mai devreme.
   Sortez lista folosind functia compareUsers din clasa utility.
f. Caut userii de tip "PremiumUser" si fac downcast la clasa respectiva (primul while) . In al doilea while: pentru fiecare element din map parcurg lista de produse (al treilea while) cautand produsele din categoriile respective, apoi daca id-urile lor sunt egale, introduc in lista userul.
   De asemenea, am introdus o conditie de oprire pentru cazul in care gasesc un produs de acest fel.  

Cerinta 5:

   Pentru ambele functii de request:
   1.am returnat false daca cantitatea era <=0.
   2.false daca id-ul produsului nu se regasea in lista de produse a serverului.
   3.false daca id-ul userului nu se regasea.
   4.am obtinut shoppingcart-ul userului cautandu-i id-ul in map-ul <id,shoppingCart> al serverului.
   5.am cautat in cart produsul respectiv pentru a stii ce metoda sa folosesc (add/raise)
   7.verific cantitatea la addRequest sa fie <= cu cea disponibila (pe server), returnez false in caz contrar.
   8.verific cantitatea la deleteRequest sa fie <= cu cea disonibila (in cos), returnez false altfel.
   6.daca produsul s-a regasit in cart folosesc raise(addRequest)/lower(deleteRequest), altfel add/return false. 
   7.dupa ce am modificat cantitatea din cos, adaug, respectiv scad cantitatea produsului din baza de date a serverului.
    