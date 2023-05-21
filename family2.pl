% Facts: parent(Child, Parent)
parent(john, mary).
parent(john, mike).
parent(mary, alice).
parent(mary, george).
parent(mike, lisa).
parent(mike, james).
parent(susan, alice).
parent(susan, george).
parent(lisa, carol).
parent(lisa, paul).
parent(james, karen).
parent(james, daniel).

% Rule: grandparent(Grandchild, Grandparent)
grandparent(Grandchild, Grandparent) :-
    parent(Grandchild, Parent),
    parent(Parent, Grandparent).

% Rule: sibling(Person1, Person2)
sibling(Person1, Person2) :-
    parent(Person1, Parent),
    parent(Person2, Parent),
    Person1 \= Person2.

% Rule: cousin(Person1, Person2)
cousin(Person1, Person2) :-
    parent(Person1, Parent1),
    parent(Person2, Parent2),
    sibling(Parent1, Parent2).

% La regla great_grandparent/2 toma dos argumentos: GreatGrandchild y GreatGrandparent.
 Esta regla establece que GreatGrandparent es el bisabuelo/a de GreatGrandchild si existe
  un Child tal que GreatGrandchild es el hijo/a de Child y Child es el nieto/a de GreatGrandparent.
parent(GreatGrandchild, Child): esta parte de la regla verifica que exista una relación directa 
de paternidad entre GreatGrandchild y Child. Es decir, Child es el padre o la madre de GreatGrandchild.
grandparent(Child, GreatGrandparent): Esta parte de la regla utiliza la regla existente
 grandparent/2 para verificar si Child es un nieto/a de GreatGrandparent. La regla grandparent/2 
 establece que Grandparent es un abuelo/a de Child si existe un Parent tal que Child es el hijo/a
  de Parent y Parent es el hijo/a de Grandparent.
Al combinar ambos pasos, la regla great_grandparent/2 
nos permite encontrar los bisabuelos de un individuo. Primero encuentra a los hijos de los
 bisabuelos (Child), y luego verifica si esos hijos son nietos de los bisabuelos (GreatGrandparent). %

% Rule: great_grandparent(GreatGrandchild, GreatGrandparent)
great_grandparent(GreatGrandchild, GreatGrandparent) :-
    parent(GreatGrandchild, Child),
    grandparent(Child, GreatGrandparent).

%
La regla great_great_grandparent/2 toma dos argumentos: GreatGreatGrandchild y GreatGreatGrandparent.
 Esta regla establece que GreatGreatGrandparent es el tatarabuelo/a de GreatGreatGrandchild si existe
  un Child tal que GreatGreatGrandchild es el hijo/a de Child y Child es el bisnieto/a de 
  GreatGreatGrandparent.
parent(GreatGreatGrandchild, Child): Esta parte de la regla verifica que exista una relación
 directa de paternidad entre GreatGreatGrandchild y Child. Es decir, Child es el padre o la madre
  de GreatGreatGrandchild.
great_grandparent(Child, GreatGreatGrandparent): Esta parte de la regla utiliza la regla
 great_grandparent/2 para verificar si Child es un bisnieto/a de GreatGreatGrandparent.
  La regla great_grandparent/2 establece que GreatGrandparent es un bisabuelo/a de Child
   si existe un Parent tal que Child es el hijo/a de Parent y Parent es el hijo/a de GreatGrandparent.
%

% Rule: great_great_grandparent(GreatGreatGrandchild, GreatGreatGrandparent)
great_great_grandparent(GreatGreatGrandchild, GreatGreatGrandparent) :-
    parent(GreatGreatGrandchild, Child),
    great_grandparent(Child, GreatGreatGrandparent).

%
La regla nephew/2 toma dos argumentos: Nephew y UncleOrAunt. Esta regla establece
 que Nephew es el sobrino/a de UncleOrAunt si existe un Parent tal que Nephew es el hijo/a
  de Parent y UncleOrAunt es el hermano/a de Parent.
parent(Nephew, Parent): Esta parte de la regla verifica que exista una relación 
directa de paternidad entre Nephew y Parent. Es decir, Parent es el padre o la madre de Nephew.
sibling(Parent, UncleOrAunt): Esta parte de la regla utiliza la regla sibling/2 para
 verificar si Parent y UncleOrAunt son hermanos/as. La regla sibling/2 establece que
  Person1 y Person2 son hermanos/as si tienen un mismo padre o madre en común.
%

% Rule: nephew(Nephew, UncleOrAunt)
nephew(Nephew, UncleOrAunt) :-
    parent(Nephew, Parent),
    sibling(Parent, UncleOrAunt).