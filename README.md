# 2526_DTI_2507_PROGRAMMATION_SYSTEME_TP_MENPIOT_AMINE

Question 1 :

<img width="378" height="110" alt="image" src="https://github.com/user-attachments/assets/3a8d2bc8-2514-49c1-a509-2451b01317c5" />

Le shell se lance comme requis mais aucune action n'est possible. La commande quitte le shell linux

Question 2 :

<img width="943" height="322" alt="image" src="https://github.com/user-attachments/assets/6c0fa514-cad4-47af-979e-c342f30b8f74" />

Les commandes se lancent correctement sur le shell et leur résultat s'affiche. On a testé avec plusieurs commandes et ça fonctionne. Il y a bien retour à la ligne

Question 3 :

<img width="300" height="67" alt="image" src="https://github.com/user-attachments/assets/1c680a88-99b4-4cb8-ada7-c3cd00cf852e" />

La commande exit permet bien de quitter le shell ENSEA avec un message gentil.

Question 4 :

<img width="958" height="168" alt="image" src="https://github.com/user-attachments/assets/aa68f321-cf14-4052-bfc4-a6b7f8801173" />

On a bien l'affichage du code de retour. On a le code 0 pour une commande fonctionnelle. 

<img width="196" height="90" alt="image" src="https://github.com/user-attachments/assets/4bc30f08-c863-4824-b347-e04f8787d73d" />

Pour une commande qui n'existe pas, on a le code 1. 

Question 5 :

<img width="974" height="260" alt="image" src="https://github.com/user-attachments/assets/c27aabd4-2ab9-4ba4-bee2-14b0164c5a27" />

On peut remarquer que le temps d'exécution est différent selon les commandes mais aussi qu'il est significativement plus long lorsque la commande n'est pas reconnue. 

Questions 6 et 7 :

<img width="379" height="150" alt="image" src="https://github.com/user-attachments/assets/d8bda81f-19d3-495e-9d8f-eb0b5a6d2039" />

Notre code ne fonctionne pas. Il ne renvoie pas de message de segfault mais il est tout de même possible qu'il s'en agisse. L'ajout du tableau array semble en avoir été la cause. 

Pour la question 7, nous avons ajouté au code original, dans le code de l'enfant, les fonctions permettant de traiter des documents (open avec les arguments WRONLY pour l'écriture) et (RDONLY pour la lecture). 
La fonction dup2 permet de remplacer le descripteur de fichier par un nouveau pour prendre en entrée ou mettre en sortie le fichier que nous appelons.
